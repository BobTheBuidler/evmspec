# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import UINT_HEX_CASES, UINT_HEX_CASE_IDS
from evmspec.data import UnixTimestamp, Wei, uint

UINT_VALUE_CASES = [
    uint(0),
    uint(1),
    uint(0x5208),
    uint(0xFFFFFFFFFFFFFFFF),
    uint(int("0x" + "ff" * 32, 16)),
]
UINT_VALUE_CASE_IDS = [
    "0",
    "1",
    "gas-21000",
    "uint64-max",
    "uint256-max",
]

UINT_DECODE_STR_CASES = [
    "0x2a",
    "0x0000000000000001",
    "0xffffffffffffffff",
    "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
]
UINT_DECODE_STR_CASE_IDS = [
    "42",
    "padded-1",
    "uint64-max",
    "uint256-max",
]

UINT_DECODE_INT_CASES = [
    42,
    0xFFFFFFFFFFFFFFFF,
    int("0x" + "ff" * 32, 16),
]
UINT_DECODE_INT_CASE_IDS = [
    "42",
    "uint64-max",
    "uint256-max",
]

WEI_INSTANCES = [
    Wei(10**9),
    Wei(10**18),
]
WEI_INSTANCE_IDS = [
    "gwei",
    "ether",
]

TIMESTAMP_INSTANCES = [
    UnixTimestamp(0),
    UnixTimestamp(1700000000),
]
TIMESTAMP_INSTANCE_IDS = [
    "epoch",
    "recent",
]


def _wei_scaled_uncached(value: Wei) -> None:
    value.__dict__.pop("scaled", None)
    value.scaled


def _unix_timestamp_datetime_uncached(value: UnixTimestamp) -> None:
    value.__dict__.pop("datetime", None)
    value.datetime


@pytest.mark.benchmark(group="uint_fromhex")
@pytest.mark.parametrize("hexstr", UINT_HEX_CASES, ids=UINT_HEX_CASE_IDS)
def test_uint_fromhex(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 20_000, uint.fromhex, hexstr)


@pytest.mark.benchmark(group="uint_repr")
@pytest.mark.parametrize("value", UINT_VALUE_CASES, ids=UINT_VALUE_CASE_IDS)
def test_uint_repr(benchmark: BenchmarkFixture, value: uint) -> None:
    benchmark(batch, 50_000, repr, value)


@pytest.mark.benchmark(group="uint_str")
@pytest.mark.parametrize("value", UINT_VALUE_CASES, ids=UINT_VALUE_CASE_IDS)
def test_uint_str(benchmark: BenchmarkFixture, value: uint) -> None:
    benchmark(batch, 50_000, str, value)


@pytest.mark.benchmark(group="uint_decode_str")
@pytest.mark.parametrize("value", UINT_DECODE_STR_CASES, ids=UINT_DECODE_STR_CASE_IDS)
def test_uint_decode_str(benchmark: BenchmarkFixture, value: str) -> None:
    benchmark(batch, 20_000, uint._decode, value)


@pytest.mark.benchmark(group="uint_decode_int")
@pytest.mark.parametrize("value", UINT_DECODE_INT_CASES, ids=UINT_DECODE_INT_CASE_IDS)
def test_uint_decode_int(benchmark: BenchmarkFixture, value: int) -> None:
    benchmark(batch, 20_000, uint._decode, value)


@pytest.mark.benchmark(group="uint_decode_hook")
@pytest.mark.parametrize("hexstr", UINT_DECODE_STR_CASES, ids=UINT_DECODE_STR_CASE_IDS)
def test_uint_decode_hook(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 20_000, uint._decode_hook, uint, hexstr)


@pytest.mark.benchmark(group="wei_scaled")
@pytest.mark.parametrize("value", WEI_INSTANCES, ids=WEI_INSTANCE_IDS)
def test_wei_scaled(benchmark: BenchmarkFixture, value: Wei) -> None:
    benchmark(batch, 20_000, _wei_scaled_uncached, value)


@pytest.mark.benchmark(group="unix_timestamp_datetime")
@pytest.mark.parametrize("value", TIMESTAMP_INSTANCES, ids=TIMESTAMP_INSTANCE_IDS)
def test_unix_timestamp_datetime(
    benchmark: BenchmarkFixture,
    value: UnixTimestamp,
) -> None:
    benchmark(batch, 20_000, _unix_timestamp_datetime_uncached, value)
