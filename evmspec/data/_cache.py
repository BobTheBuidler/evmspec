from time import monotonic
from cachetools import cached, keys
from cachetools.func import TTLCache, _UnboundTTLCache


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


def _cache(cache, maxsize, typed):
    # reimplement ttl_cache with no RLock for race conditions

    def decorator(func):
        key = keys.typedkey if typed else keys.hashkey
        wrapper = cached(cache=cache, key=key, lock=None, info=True)(func)
        wrapper.cache_parameters = lambda: {"maxsize": maxsize, "typed": typed}
        return wrapper

    return decorator
