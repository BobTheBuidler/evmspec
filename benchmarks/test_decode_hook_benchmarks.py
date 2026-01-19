# mypy: disable-error-code=misc
from decimal import Decimal

import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import ADDRESS_CHECKSUM, HASH_1
from evmspec.data import Address, BlockNumber, HexBytes32, _decode_hook
from evmspec.data._main import _decode_hook_unsafe
from evmspec.data import _main as data_main


def _decode_hook_address() -> None:
    _decode_hook(Address, ADDRESS_CHECKSUM)


def _decode_hook_uint() -> None:
    _decode_hook(BlockNumber, "0x2a")


def _decode_hook_hexbytes() -> None:
    _decode_hook(HexBytes32, HASH_1)


def _decode_hook_decimal() -> None:
    _decode_hook(Decimal, "1.23")


def _decode_hook_unsafe_address() -> None:
    _decode_hook_unsafe(Address, ADDRESS_CHECKSUM)


def _make_decode_logs() -> None:
    try:
        data_main.__make_decode_logs()
    except TypeError:
        pass


def _import_dank() -> None:
    data_main.__import_dank_tx_methods()


@pytest.mark.benchmark(group="decode_hook_address")
def test_decode_hook_address(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_address)


@pytest.mark.benchmark(group="decode_hook_uint")
def test_decode_hook_uint(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_uint)


@pytest.mark.benchmark(group="decode_hook_hexbytes")
def test_decode_hook_hexbytes(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_hexbytes)


@pytest.mark.benchmark(group="decode_hook_decimal")
def test_decode_hook_decimal(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_decimal)


@pytest.mark.benchmark(group="decode_hook_unsafe_address")
def test_decode_hook_unsafe_address(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_hook_unsafe_address)


@pytest.mark.benchmark(group="make_decode_logs")
def test_make_decode_logs(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _make_decode_logs)


@pytest.mark.benchmark(group="import_dank_tx_methods")
def test_import_dank_tx_methods(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 10, _import_dank)
