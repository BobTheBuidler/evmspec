# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import (
    HASH_1,
    HASH_PADDED,
    HEXBYTES32_CASES,
    HEXBYTES32_CASE_IDS,
)
from evmspec import _new
from evmspec.data import HexBytes32

HEXBYTES_INSTANCE = HexBytes32(HASH_1)
HEXBYTES_PADDED = HexBytes32(HASH_PADDED)


def _hex(hb: HexBytes32) -> None:
    hb.hex()


def _strip(hb: HexBytes32) -> None:
    hb.strip()


def _getitem_int(hb: HexBytes32) -> None:
    hb[0]


def _getitem_slice(hb: HexBytes32) -> None:
    hb[0:4]


def _reduce(hb: HexBytes32) -> None:
    hb.__reduce__()


def _new_hexbytes32(cls: type[HexBytes32], value: bytes | str) -> None:
    _new.HexBytes32(cls, value)


@pytest.mark.benchmark(group="hexbytes32_construct")
@pytest.mark.parametrize("value", HEXBYTES32_CASES, ids=HEXBYTES32_CASE_IDS)
def test_hexbytes32_construct(benchmark: BenchmarkFixture, value: bytes | str) -> None:
    benchmark(batch, 1000, HexBytes32, value)


@pytest.mark.benchmark(group="hexbytes32_hex")
def test_hexbytes32_hex(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, _hex, HEXBYTES_INSTANCE)


@pytest.mark.benchmark(group="hexbytes32_strip")
def test_hexbytes32_strip(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, _strip, HEXBYTES_PADDED)


@pytest.mark.benchmark(group="hexbytes32_repr")
def test_hexbytes32_repr(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, repr, HEXBYTES_INSTANCE)


@pytest.mark.benchmark(group="hexbytes32_hash")
def test_hexbytes32_hash(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, hash, HEXBYTES_INSTANCE)


@pytest.mark.benchmark(group="hexbytes32_getitem_int")
def test_hexbytes32_getitem_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, _getitem_int, HEXBYTES_INSTANCE)


@pytest.mark.benchmark(group="hexbytes32_getitem_slice")
def test_hexbytes32_getitem_slice(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, _getitem_slice, HEXBYTES_INSTANCE)


@pytest.mark.benchmark(group="hexbytes32_reduce")
def test_hexbytes32_reduce(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, _reduce, HEXBYTES_INSTANCE)


@pytest.mark.benchmark(group="hexbytes32_check_hexstr")
def test_hexbytes32_check_hexstr(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, HexBytes32._check_hexstr, HASH_1)


@pytest.mark.benchmark(group="hexbytes32_new_function")
def test_hexbytes32_new_function(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 1000, _new_hexbytes32, HexBytes32, HASH_1)
