from importlib.metadata import version
from time import monotonic

from cachetools import cached, keys
from cachetools.func import TTLCache, _UnboundTTLCache


_CACHETOOLS_VERSION = tuple(int(i) for i in version("cachetools").split("."))


def ttl_cache(maxsize=128, ttl=600, timer=monotonic, typed=False):
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


def _cache(cache, maxsize, typed, info: bool = False):
    # reimplement ttl_cache with no RLock for race conditions

    key = keys.typedkey if typed else keys.hashkey
    get_params = lambda: {"maxsize": maxsize, "typed": typed}

    # `info` param was added in 5.3
    if _CACHETOOLS_VERSION >= (5, 3):

        def decorator(func):
            wrapper = cached(cache=cache, key=key, lock=None, info=info)(func)
            wrapper.cache_parameters = get_params
            return wrapper

    elif info:
        raise ValueError(
            "You cannot use the `info` param with cachetools versions < 5.3"
        )

    else:

        def decorator(func):
            wrapper = cached(cache=cache, key=key, lock=None)(func)
            wrapper.cache_parameters = get_params
            return wrapper

    return decorator
