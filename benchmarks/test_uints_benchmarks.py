# mypy: disable-error-code=misc
import pytest
from hexbytes import HexBytes
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.data import uints

HEXBYTE_VALUE = HexBytes(1)

UINT_CLASSES = [
    uints.uint8,
    uints.uint40,
    uints.uint64,
    uints.uint128,
    uints.uint256,
]
UINT_CLASS_IDS = [
    "uint8",
    "uint40",
    "uint64",
    "uint128",
    "uint256",
]


@pytest.mark.benchmark(group="uints_construct")
@pytest.mark.parametrize("cls", UINT_CLASSES, ids=UINT_CLASS_IDS)
def test_uints_construct(benchmark: BenchmarkFixture, cls) -> None:
    benchmark(batch, 2000, cls, HEXBYTE_VALUE)
