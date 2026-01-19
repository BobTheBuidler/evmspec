# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture
from typing import Final

from benchmarks.batch import batch
from benchmarks.data import UINT_HEX_CASES, UINT_HEX_CASE_IDS
from evmspec.data import UnixTimestamp, Wei, uint

UINT_INSTANCE: Final = uint(42)
WEI_INSTANCE: Final = Wei(10**18)
TIMESTAMP_INSTANCE: Final = UnixTimestamp(1700000000)


@pytest.mark.benchmark(group="uint_fromhex")
@pytest.mark.parametrize("hexstr", UINT_HEX_CASES, ids=UINT_HEX_CASE_IDS)
def test_uint_fromhex(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 2000, uint.fromhex, hexstr)


@pytest.mark.benchmark(group="uint_repr")
def test_uint_repr(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 5000, repr, UINT_INSTANCE)


@pytest.mark.benchmark(group="uint_str")
def test_uint_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 5000, str, UINT_INSTANCE)


@pytest.mark.benchmark(group="uint_decode_str")
def test_uint_decode_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, uint._decode, "0x2a")


@pytest.mark.benchmark(group="uint_decode_int")
def test_uint_decode_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, uint._decode_int, 42)


@pytest.mark.benchmark(group="uint_decode_hook")
def test_uint_decode_hook(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, uint._decode_hook, "0x2a")


@pytest.mark.benchmark(group="wei_scaled")
def test_wei_scaled(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, getattr, WEI_INSTANCE, "scaled")


@pytest.mark.benchmark(group="unix_timestamp_datetime")
def test_unix_timestamp_datetime(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, getattr, TIMESTAMP_INSTANCE, "datetime")
