# mypy: disable-error-code=misc
import pytest
from cachetools.func import TTLCache
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.data._cache import _cache, ttl_cache


def _build_ttl_cache() -> None:
    @ttl_cache(maxsize=32, ttl=1)
    def _cached(x: int) -> int:
        return x + 1

    _cached(1)


def _build_unbound_ttl_cache() -> None:
    @ttl_cache(maxsize=None, ttl=1)
    def _cached(x: int) -> int:
        return x + 1

    _cached(1)


def _build_cache_direct() -> None:
    decorator = _cache(TTLCache(32, 1), 32, False)

    def _cached(x: int) -> int:
        return x + 1

    cached = decorator(_cached)
    cached(1)


def _build_cache_typed() -> None:
    decorator = _cache(TTLCache(32, 1), 32, True)

    def _cached(x: int) -> int:
        return x + 1

    cached = decorator(_cached)
    cached(1)


def _build_cache_info() -> None:
    try:
        decorator = _cache(TTLCache(32, 1), 32, False, info=True)
    except ValueError:
        return

    def _cached(x: int) -> int:
        return x + 1

    cached = decorator(_cached)
    cached(1)


def _build_ttl_cache_default() -> None:
    @ttl_cache
    def _cached(x: int) -> int:
        return x + 1

    _cached(1)


@ttl_cache(maxsize=32, ttl=1)
def _cached_call(x: int) -> int:
    return x + 1


@pytest.mark.benchmark(group="ttl_cache_build")
def test_ttl_cache_build(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _build_ttl_cache)


@pytest.mark.benchmark(group="ttl_cache_build_unbound")
def test_ttl_cache_build_unbound(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _build_unbound_ttl_cache)


@pytest.mark.benchmark(group="cache_direct_build")
def test_cache_direct_build(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _build_cache_direct)


@pytest.mark.benchmark(group="cache_direct_typed")
def test_cache_direct_typed(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _build_cache_typed)


@pytest.mark.benchmark(group="cache_direct_info")
def test_cache_direct_info(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _build_cache_info)


@pytest.mark.benchmark(group="ttl_cache_build_default")
def test_ttl_cache_build_default(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _build_ttl_cache_default)


@pytest.mark.benchmark(group="ttl_cache_call")
def test_ttl_cache_call(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _cached_call, 1)
