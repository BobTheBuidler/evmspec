from collections import MutableMapping, OrderedDict
from importlib.metadata import version
from math import inf
from time import monotonic
from typing import Any, Callable, Final, Iterator, Literal, Optional, Tuple, Type, TypedDict, final

from cachetools import cached, keys


_CACHETOOLS_VERSION: Final = tuple(map(int, version("cachetools").split(".")))


@final
class CacheParams(TypedDict):
    maxsize: Optional[int]
    typed: bool


_LinkKey = Any

def ttl_cache(maxsize: Optional[int] = 128, ttl: float = 600, timer = monotonic, typed: bool = False):
    """Decorator to wrap a function with a memoizing callable that saves
    up to `maxsize` results based on a Least Recently Used (LRU)
    algorithm with a per-item time-to-live (TTL) value.
    """
    if maxsize is None:
        return _cache(_UnboundTTLCache(ttl, timer), None, typed)
    elif callable(maxsize):
        return _cache(TTLCache(128, ttl, timer), 128, typed)(maxsize)
    else:
        return _cache(TTLCache(maxsize, ttl, timer), maxsize, typed)


def _cache(cache, maxsize: int, typed: bool, info: bool = False):
    # reimplement ttl_cache with no RLock for race conditions

    key = keys.typedkey if typed else keys.hashkey
    cache_params = CacheParams(maxsize=maxsize, typed=typed)

    def get_cache_params() -> CacheParams:
        return cache_params

    # `info` param was added in 5.3
    if _CACHETOOLS_VERSION >= (5, 3):
        cache_deco = cached(cache=cache, key=key, lock=None, info=info)

    elif info:
        raise ValueError(
            "You cannot use the `info` param with cachetools versions < 5.3"
        )

    else:
        cache_deco = cached(cache=cache, key=key, lock=None)

    def decorator(func):
        wrapper = cache_deco(func)
        wrapper.cache_parameters = get_cache_params
        return wrapper

    return decorator


@final
class _DefaultSize:
    __slots__ = ()
    def __getitem__(self, _):
        return 1
    def __setitem__(self, _, value):
        assert value == 1
    def pop(self, _):
        return 1


@final
class Cache(MutableMapping):
    """Mutable mapping to serve as a simple cache or cache base class."""

    __marker: Final = object()

    def __init__(self, maxsize: int) -> None:
        self.__size: Final = _DefaultSize()
        self.__data: Final = {}
        self.__currsize: int = 0
        self.__maxsize: Final = maxsize

    def __repr__(self) -> str:
        return "%s(%r, maxsize=%r, currsize=%r)" % (
            self.__class__.__name__,
            list(self.__data.items()),
            self.__maxsize,
            self.__currsize,
        )

    def __getitem__(self, key):
        try:
            return self.__data[key]
        except KeyError:
            return self.__missing__(key)

    def __setitem__(self, key, value) -> None:
        maxsize = self.__maxsize
        size = self.getsizeof(value)
        if size > maxsize:
            raise ValueError("value too large")
        if key not in self.__data or self.__size[key] < size:
            while self.__currsize + size > maxsize:
                self.popitem()
        if key in self.__data:
            diffsize = size - self.__size[key]
        else:
            diffsize = size
        self.__data[key] = value
        self.__size[key] = size
        self.__currsize += diffsize

    def __delitem__(self, key):
        size = self.__size.pop(key)
        del self.__data[key]
        self.__currsize -= size

    def __contains__(self, key) -> bool:
        return key in self.__data

    def __missing__(self, key) -> NoReturn:
        raise KeyError(key)

    def __iter__(self):
        return iter(self.__data)

    def __len__(self) -> int:
        return len(self.__data)

    def get(self, key, default=None):
        if key in self:
            return self[key]
        else:
            return default

    def pop(self, key, default=__marker):
        if key in self:
            value = self[key]
            del self[key]
        elif default is self.__marker:
            raise KeyError(key)
        else:
            value = default
        return value

    def setdefault(self, key, default=None):
        if key in self:
            value = self[key]
        else:
            self[key] = value = default
        return value

    @property
    def maxsize(self) -> int:
        """The maximum size of the cache."""
        return self.__maxsize

    @property
    def currsize(self) -> int:
        """The current size of the cache."""
        return self.__currsize

    @staticmethod
    def getsizeof(value: Any) -> Literal[1]:
        """Return the size of a cache element's value."""
        return 1


@final
class TTLCache(Cache):
    """LRU Cache implementation with per-item time-to-live (TTL) value."""

    def __init__(self, maxsize: int, ttl: float, timer: Callable[[], float] = monotonic, getsizeof=None):
        Cache.__init__(self, maxsize, getsizeof)
        root = _Link()
        self.__root: Final = _Link()
        root.prev = root.next = root
        self.__links: Final[OrderedDict[_LinkKey, _Link]] = OrderedDict()
        self.__timer: Final = _Timer(timer)
        self.__ttl: Final = ttl

    def __contains__(self, key: _LinkKey) -> bool:
        try:
            link = self.__links[key]  # no reordering
        except KeyError:
            return False
        else:
            return not (link.expire < self.__timer())

    def __getitem__(self, key, cache_getitem=Cache.__getitem__):
        try:
            link = self.__getlink(key)
        except KeyError:
            expired = False
        else:
            expired = link.expire < self.__timer()
        if expired:
            return self.__missing__(key)
        else:
            return cache_getitem(self, key)

    def __setitem__(self, key, value, cache_setitem=Cache.__setitem__) -> None:
        with self.__timer as time:
            self.expire(time)
            cache_setitem(self, key, value)
        expiration = time + self.__ttl
        try:
            link = self.__getlink(key)
        except KeyError:
            self.__links[key] = link = _Link(key, expiration)
        else:
            link.unlink()
            link.expire = expiration
        link.next = root = self.__root
        link.prev = prev = root.prev
        prev.next = root.prev = link

    def __delitem__(self, key, cache_delitem=Cache.__delitem__) -> None:
        cache_delitem(self, key)
        link = self.__links.pop(key)
        link.unlink()
        if link.expire < self.__timer():
            raise KeyError(key)

    def __iter__(self) -> Iterator[_LinkKey]:
        root = self.__root
        curr = root.next
        while curr is not root:
            # "freeze" time for iterator access
            with self.__timer as time:
                if not (curr.expire < time):
                    yield curr.key
            curr = curr.next

    def __len__(self) -> int:
        root = self.__root
        curr = root.next
        time = self.__timer()
        count = len(self.__links)
        while curr is not root and curr.expire < time:
            count -= 1
            curr = curr.next
        return count

    def __setstate__(self, state):
        self.__dict__.update(state)
        root = self.__root
        root.prev = root.next = root
        for link in sorted(self.__links.values(), key=lambda obj: obj.expire):
            link.next = root
            link.prev = prev = root.prev
            prev.next = root.prev = link
        self.expire(self.__timer())

    def __repr__(self, cache_repr=Cache.__repr__) -> str:
        with self.__timer as time:
            self.expire(time)
            return cache_repr(self)

    @property
    def currsize(self) -> int:
        with self.__timer as time:
            self.expire(time)
            return super().currsize

    @property
    def timer(self) -> "_Timer":
        """The timer function used by the cache."""
        return self.__timer

    @property
    def ttl(self) -> float:
        """The time-to-live value of the cache's items."""
        return self.__ttl

    def expire(self, time: Optional[float] = None) -> None:
        """Remove expired items from the cache."""
        if time is None:
            time = self.__timer()
        root = self.__root
        curr = root.next
        links = self.__links
        while curr is not root and curr.expire < time:
            Cache.__delitem__(self, curr.key)
            del links[curr.key]
            next = curr.next
            curr.unlink()
            curr = next

    def clear(self) -> None:
        with self.__timer as time:
            self.expire(time)
            Cache.clear(self)

    def get(self, *args, **kwargs):
        with self.__timer:
            return Cache.get(self, *args, **kwargs)

    def pop(self, *args, **kwargs):
        with self.__timer:
            return Cache.pop(self, *args, **kwargs)

    def setdefault(self, *args, **kwargs):
        with self.__timer:
            return Cache.setdefault(self, *args, **kwargs)

    def popitem(self):
        """Remove and return the `(key, value)` pair least recently used that
        has not already expired.

        """
        with self.__timer as time:
            self.expire(time)
            try:
                key = next(iter(self.__links))
            except StopIteration:
                raise KeyError("%s is empty" % type(self).__name__) from None
            else:
                return (key, self.pop(key))

    def __getlink(self, key) -> "_Link":
        value = self.__links[key]
        self.__links.move_to_end(key)
        return value


class _UnboundTTLCache(TTLCache):
    def __init__(self, ttl, timer):
        TTLCache.__init__(self, inf, ttl, timer)

    @property
    def maxsize(self):
        return None


@final
class _Link:

    __slots__ = ("key", "expire", "next", "prev")

    next: "_Link"
    prev: "_Link"

    def __init__(self, key: _LinkKey = None, expire: Optional[float] = None) -> None:
        self.key: Final = key
        self.expire = expire

    def __reduce__(self) -> Tuple[Type["_Link"], Tuple[_LinkKey, Any]]:
        return _Link, (self.key, self.expire)

    def unlink(self) -> None:
        next = self.next
        prev = self.prev
        prev.next = next
        next.prev = prev


@final
class _Timer:

    __slots__ = ("__timer", "__nesting", "__time")

    __time: float

    def __init__(self, timer: Callable[[], float]) -> None:
        self.__timer: Final = timer
        self.__nesting: int = 0

    def __call__(self) -> float:
        if self.__nesting == 0:
            return self.__timer()
        else:
            return self.__time

    def __enter__(self) -> float:
        if self.__nesting == 0:
            self.__time = time = self.__timer()
        else:
            time = self.__time
        self.__nesting += 1
        return time

    def __exit__(self, *exc) -> None:
        self.__nesting -= 1

    def __reduce__(self) -> Tuple[Type["_Timer"], Tuple[Callable[[], float]]]:
        return _Timer, (self.__timer,)

    def __getattr__(self, name: str) -> Any:
        return getattr(self.__timer, name)
