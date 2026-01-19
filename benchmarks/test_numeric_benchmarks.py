# mypy: disable-error-code=misc
from collections.abc import Callable
from typing import Final

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

UINT_INSTANCE: Final = uint(42)
WEI_INSTANCE: Final = Wei(10**18)
TIMESTAMP_INSTANCE: Final = UnixTimestamp(1700000000)

NUMERIC_CALLS = [
    pytest.param(
        5000,
        repr,
        (UINT_INSTANCE,),
        id="uint-repr",
        marks=pytest.mark.benchmark(group="uint_repr"),
    ),
    pytest.param(
        5000,
        str,
        (UINT_INSTANCE,),
        id="uint-str",
        marks=pytest.mark.benchmark(group="uint_str"),
    ),
    pytest.param(
        2000,
        uint._decode,
        ("0x2a",),
        id="uint-decode-str",
        marks=pytest.mark.benchmark(group="uint_decode_str"),
    ),
    pytest.param(
        2000,
        uint._decode,
        (42,),
        id="uint-decode-int",
        marks=pytest.mark.benchmark(group="uint_decode_int"),
    ),
    pytest.param(
        2000,
        uint._decode_hook,
        (uint, "0x2a"),
        id="uint-decode-hook",
        marks=pytest.mark.benchmark(group="uint_decode_hook"),
    ),
    pytest.param(
        2000,
        getattr,
        (WEI_INSTANCE, "scaled"),
        id="wei-scaled",
        marks=pytest.mark.benchmark(group="wei_scaled"),
    ),
    pytest.param(
        2000,
        getattr,
        (TIMESTAMP_INSTANCE, "datetime"),
        id="unix-timestamp-datetime",
        marks=pytest.mark.benchmark(group="unix_timestamp_datetime"),
    ),
]


@pytest.mark.benchmark(group="uint_fromhex")
@pytest.mark.parametrize("hexstr", UINT_HEX_WORKLOAD_CASES, ids=UINT_HEX_WORKLOAD_IDS)
def test_uint_fromhex(benchmark: BenchmarkFixture, hexstr: str) -> None:
    benchmark(batch, 2000, uint.fromhex, hexstr)


@pytest.mark.parametrize("iterations, func, args", NUMERIC_CALLS)
def test_numeric_helpers(
    benchmark: BenchmarkFixture,
    iterations: int,
    func: Callable[..., object],
    args: tuple[object, ...],
) -> None:
    benchmark(batch, iterations, func, *args)
