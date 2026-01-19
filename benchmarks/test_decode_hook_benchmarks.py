# mypy: disable-error-code=misc
from decimal import Decimal

import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import ADDRESS_CHECKSUM, HASH_1
from evmspec.data import Address, BlockNumber, HexBytes32, _decode_hook
from evmspec.data._main import _decode_hook_unsafe
from evmspec.data import _main as data_main


@pytest.mark.benchmark(group="decode_hook_address")
def test_decode_hook_address(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook, ADDRESS_CHECKSUM)


@pytest.mark.benchmark(group="decode_hook_uint")
def test_decode_hook_uint(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook, BlockNumber, "0x2a")


@pytest.mark.benchmark(group="decode_hook_hexbytes")
def test_decode_hook_hexbytes(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook, HexBytes32, HASH_1)


@pytest.mark.benchmark(group="decode_hook_decimal")
def test_decode_hook_decimal(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook, Decimal, "1.23")


@pytest.mark.benchmark(group="decode_hook_unsafe_address")
def test_decode_hook_unsafe_address(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_unsafe, Address, ADDRESS_CHECKSUM)


@pytest.mark.benchmark(group="decode_hook_uint")
def test_decode_hook_unsafe_uint(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_unsafe, BlockNumber, "0x2a")


@pytest.mark.benchmark(group="decode_hook_hexbytes")
def test_decode_hook_unsafe_hexbytes(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_unsafe, HexBytes32, HASH_1)


@pytest.mark.benchmark(group="decode_hook_decimal")
def test_decode_hook_unsafe_decimal(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_unsafe, Decimal, "1.23")
