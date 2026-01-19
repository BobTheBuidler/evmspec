# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import UINT_HEX_CASES, UINT_HEX_CASE_IDS
from evmspec.data import uint


@pytest.mark.benchmark(group="uint_fromhex")
@pytest.mark.parametrize("hexstr", UINT_HEX_CASES, ids=UINT_HEX_CASE_IDS)
def test_uint_fromhex(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 200, uint.fromhex, hexstr)
