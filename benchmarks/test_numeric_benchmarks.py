# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import UINT_HEX_CASES, UINT_HEX_CASE_IDS
from evmspec.data import UnixTimestamp, Wei, uint

UINT_HEX_WORKLOAD_CASES = [
    *UINT_HEX_CASES,
    "0x10",
    "0x65f2",
    "0x5208",
    "0x3b9aca00",
    "0x1c9c380",
    "0xffffffffffffffff",
    "0x10000000000000000",
    "0x0000000000000001",
    "0x0000000000000000000000000000000000000000000000000000000000000000",
    "0x0000000000000000000000000000000000000000000000000000000000000001",
    "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
]
UINT_HEX_WORKLOAD_IDS = [
    *UINT_HEX_CASE_IDS,
    "16",
    "block",
    "gas-21000",
    "gwei",
    "gas-limit",
    "uint64-max",
    "uint64-plus-one",
    "padded-1",
    "padded-32-zero",
    "padded-32-one",
    "uint256-max",
]

UINT_INSTANCE = uint(42)
WEI_VALUE = 10**18
TIMESTAMP_VALUE = 1700000000


def _wei_scaled(value: int) -> None:
    Wei(value).scaled


def _unix_timestamp_datetime(value: int) -> None:
    UnixTimestamp(value).datetime


@pytest.mark.benchmark(group="uint_fromhex")
@pytest.mark.parametrize("hexstr", UINT_HEX_WORKLOAD_CASES, ids=UINT_HEX_WORKLOAD_IDS)
def test_uint_fromhex(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 20_000, uint.fromhex, hexstr)


@pytest.mark.benchmark(group="uint_repr")
def test_uint_repr(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 50_000, repr, UINT_INSTANCE)


@pytest.mark.benchmark(group="uint_str")
def test_uint_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 50_000, str, UINT_INSTANCE)


@pytest.mark.benchmark(group="uint_decode_str")
def test_uint_decode_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 20_000, uint._decode, "0x2a")


@pytest.mark.benchmark(group="uint_decode_int")
def test_uint_decode_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 20_000, uint._decode, 42)


@pytest.mark.benchmark(group="uint_decode_hook")
def test_uint_decode_hook(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 20_000, uint._decode_hook, uint, "0x2a")


@pytest.mark.benchmark(group="wei_scaled")
def test_wei_scaled(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 20_000, _wei_scaled, WEI_VALUE)


@pytest.mark.benchmark(group="unix_timestamp_datetime")
def test_unix_timestamp_datetime(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 20_000, _unix_timestamp_datetime, TIMESTAMP_VALUE)
