# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import HEXBYTES32_CASES, HEXBYTES32_CASE_IDS
from evmspec.data import HexBytes32


@pytest.mark.benchmark(group="hexbytes32_construct")
@pytest.mark.parametrize("value", HEXBYTES32_CASES, ids=HEXBYTES32_CASE_IDS)
def test_hexbytes32_construct(benchmark: BenchmarkFixture, value: bytes | str) -> None:
    benchmark(batch, 100, HexBytes32, value)
