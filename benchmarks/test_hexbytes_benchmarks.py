# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import (
    ADDRESS_TOPIC_CHECKSUM,
    DATA_32,
    HASH_1,
    HASH_PADDED,
    HEXBYTES32_CASE_IDS,
    HEXBYTES32_CASES,
)
from evmspec import _new
from evmspec.data import HexBytes32

HEXBYTES32_WORKLOAD_HEXSTRS = [
    HASH_1,
    ADDRESS_TOPIC_CHECKSUM,
    HASH_PADDED,
    DATA_32,
]
HEXBYTES32_WORKLOAD_IDS = [
    "hash",
    "address-topic",
    "padded-small",
    "all-zero",
]
HEXBYTES32_WORKLOAD_INSTANCES = [HexBytes32(value) for value in HEXBYTES32_WORKLOAD_HEXSTRS]

GETITEM_INT_CASES = [0, 15, 31]
GETITEM_INT_CASE_IDS = ["first", "middle", "last"]
GETITEM_SLICE_CASES = [slice(0, 4), slice(12, 32)]
GETITEM_SLICE_CASE_IDS = ["prefix-4", "address-20"]


def _hex(hb: HexBytes32) -> None:
    hb.hex()


def _strip(hb: HexBytes32) -> None:
    hb.strip()


def _getitem_int(hb: HexBytes32, index: int) -> None:
    hb[index]


def _getitem_slice(hb: HexBytes32, key: slice) -> None:
    hb[key]


def _reduce(hb: HexBytes32) -> None:
    hb.__reduce__()


@pytest.mark.benchmark(group="hexbytes32_construct")
@pytest.mark.parametrize("value", HEXBYTES32_CASES, ids=HEXBYTES32_CASE_IDS)
def test_hexbytes32_construct(benchmark: BenchmarkFixture, value: bytes | str) -> None:
    benchmark(batch, 100_000, HexBytes32, value)


@pytest.mark.benchmark(group="hexbytes32_hex")
@pytest.mark.parametrize(
    "hb",
    HEXBYTES32_WORKLOAD_INSTANCES,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
def test_hexbytes32_hex(benchmark: BenchmarkFixture, hb: HexBytes32) -> None:
    benchmark(batch, 200_000, _hex, hb)


@pytest.mark.benchmark(group="hexbytes32_strip")
@pytest.mark.parametrize(
    "hb",
    HEXBYTES32_WORKLOAD_INSTANCES,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
def test_hexbytes32_strip(benchmark: BenchmarkFixture, hb: HexBytes32) -> None:
    benchmark(batch, 200_000, _strip, hb)


@pytest.mark.benchmark(group="hexbytes32_repr")
@pytest.mark.parametrize(
    "hb",
    HEXBYTES32_WORKLOAD_INSTANCES,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
def test_hexbytes32_repr(benchmark: BenchmarkFixture, hb: HexBytes32) -> None:
    benchmark(batch, 200_000, repr, hb)


@pytest.mark.benchmark(group="hexbytes32_hash")
@pytest.mark.parametrize(
    "hb",
    HEXBYTES32_WORKLOAD_INSTANCES,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
def test_hexbytes32_hash(benchmark: BenchmarkFixture, hb: HexBytes32) -> None:
    benchmark(batch, 200_000, hash, hb)


@pytest.mark.benchmark(group="hexbytes32_getitem_int")
@pytest.mark.parametrize(
    "hb",
    HEXBYTES32_WORKLOAD_INSTANCES,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
@pytest.mark.parametrize("index", GETITEM_INT_CASES, ids=GETITEM_INT_CASE_IDS)
def test_hexbytes32_getitem_int(
    benchmark: BenchmarkFixture,
    hb: HexBytes32,
    index: int,
) -> None:
    benchmark(batch, 200_000, _getitem_int, hb, index)


@pytest.mark.benchmark(group="hexbytes32_getitem_slice")
@pytest.mark.parametrize(
    "hb",
    HEXBYTES32_WORKLOAD_INSTANCES,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
@pytest.mark.parametrize("key", GETITEM_SLICE_CASES, ids=GETITEM_SLICE_CASE_IDS)
def test_hexbytes32_getitem_slice(
    benchmark: BenchmarkFixture,
    hb: HexBytes32,
    key: slice,
) -> None:
    benchmark(batch, 200_000, _getitem_slice, hb, key)


@pytest.mark.benchmark(group="hexbytes32_reduce")
@pytest.mark.parametrize(
    "hb",
    HEXBYTES32_WORKLOAD_INSTANCES,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
def test_hexbytes32_reduce(benchmark: BenchmarkFixture, hb: HexBytes32) -> None:
    benchmark(batch, 200_000, _reduce, hb)


@pytest.mark.benchmark(group="hexbytes32_check_hexstr")
@pytest.mark.parametrize(
    "hexstr",
    HEXBYTES32_WORKLOAD_HEXSTRS,
    ids=HEXBYTES32_WORKLOAD_IDS,
)
def test_hexbytes32_check_hexstr(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 200_000, HexBytes32._check_hexstr, hexstr)


@pytest.mark.benchmark(group="hexbytes32_new_function")
@pytest.mark.parametrize("value", HEXBYTES32_CASES, ids=HEXBYTES32_CASE_IDS)
def test_hexbytes32_new_function(benchmark: BenchmarkFixture, value: bytes | str) -> None:
    benchmark(batch, 100_000, _new.HexBytes32, HexBytes32, value)
