# mypy: disable-error-code=misc
import pytest
from cachetools.func import TTLCache
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.data._cache import _cache, ttl_cache


@pytest.mark.benchmark(group="ttl_cache_call")
def test_ttl_cache_call(benchmark: BenchmarkFixture) -> None:
    @ttl_cache(maxsize=32, ttl=1)
    def _cached_call(x: int) -> int:
        return x + 1
    benchmark(batch, 200_000, _cached_call, 1)
