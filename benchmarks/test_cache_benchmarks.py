# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.data._cache import ttl_cache


def _frozen_time() -> float:
    return 0.0


@pytest.mark.benchmark(group="ttl_cache_call")
def test_ttl_cache_call(benchmark: BenchmarkFixture) -> None:
    @ttl_cache(maxsize=32, ttl=1, timer=_frozen_time)
    def _cached_call(x: int) -> int:
        return x + 1

    benchmark(batch, 25_000, _cached_call, 1)
