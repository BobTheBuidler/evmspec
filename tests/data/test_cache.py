import pytest
from cachetools import TTLCache

from evmspec.data._cache import _CACHETOOLS_VERSION, _cache, ttl_cache


def test_ttl_cache_basic() -> None:
    calls = {"count": 0}

    @ttl_cache(maxsize=2, ttl=60)
    def double(x: int) -> int:
        calls["count"] += 1
        return x * 2

    assert double(2) == 4
    assert double(2) == 4
    assert calls["count"] == 1
    assert double.cache_parameters() == {"maxsize": 2, "typed": False}


def test_ttl_cache_typed() -> None:
    calls = {"count": 0}

    @ttl_cache(maxsize=2, ttl=60, typed=True)
    def identity(x):
        calls["count"] += 1
        return x

    identity(1)
    identity(1.0)
    identity(1)
    assert calls["count"] == 2


def test_cache_info_flag() -> None:
    cache = TTLCache(maxsize=2, ttl=60)
    if _CACHETOOLS_VERSION >= (5, 3):
        decorator = _cache(cache, 2, False, info=True)

        @decorator
        def func(x: int) -> int:
            return x

        assert hasattr(func, "cache_info")
    else:
        with pytest.raises(ValueError):
            _cache(cache, 2, False, info=True)
