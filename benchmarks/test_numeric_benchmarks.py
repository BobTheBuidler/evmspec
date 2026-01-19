# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import UINT_HEX_CASES, UINT_HEX_CASE_IDS
from evmspec.data import UnixTimestamp, Wei, uint

UINT_INSTANCE = uint(42)
WEI_INSTANCE = Wei(10**18)
TIMESTAMP_INSTANCE = UnixTimestamp(1700000000)


def _uint_repr(value: uint) -> None:
    repr(value)


def _uint_str(value: uint) -> None:
    str(value)


def _uint_decode_str(value: str) -> None:
    uint._decode(value)


def _uint_decode_int(value: int) -> None:
    uint._decode(value)


def _uint_decode_hook(value: str) -> None:
    uint._decode_hook(uint, value)


def _wei_scaled(value: Wei) -> None:
    value.scaled


def _unix_datetime(value: UnixTimestamp) -> None:
    value.datetime


@pytest.mark.benchmark(group="uint_fromhex")
@pytest.mark.parametrize("hexstr", UINT_HEX_CASES, ids=UINT_HEX_CASE_IDS)
def test_uint_fromhex(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 200, uint.fromhex, hexstr)


@pytest.mark.benchmark(group="uint_repr")
def test_uint_repr(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 500, _uint_repr, UINT_INSTANCE)


@pytest.mark.benchmark(group="uint_str")
def test_uint_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 500, _uint_str, UINT_INSTANCE)


@pytest.mark.benchmark(group="uint_decode_str")
def test_uint_decode_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _uint_decode_str, "0x2a")


@pytest.mark.benchmark(group="uint_decode_int")
def test_uint_decode_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _uint_decode_int, 42)


@pytest.mark.benchmark(group="uint_decode_hook")
def test_uint_decode_hook(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _uint_decode_hook, "0x2a")


@pytest.mark.benchmark(group="wei_scaled")
def test_wei_scaled(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _wei_scaled, WEI_INSTANCE)


@pytest.mark.benchmark(group="unix_timestamp_datetime")
def test_unix_timestamp_datetime(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _unix_datetime, TIMESTAMP_INSTANCE)
