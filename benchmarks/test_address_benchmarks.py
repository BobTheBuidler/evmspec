# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import ADDRESS_CASES, ADDRESS_CASE_IDS, ADDRESS_CHECKSUM, ADDRESS_LOWER
from evmspec import _new
from evmspec.data import Address

ADDRESS_INSTANCE = Address(ADDRESS_CHECKSUM)


def _reduce(obj: Address) -> None:
    obj.__reduce__()


def _decode_hook(cls: type[Address], value: str) -> None:
    cls._decode_hook(cls, value)


def _decode_hook_unsafe(cls: type[Address], value: str) -> None:
    cls._decode_hook_unsafe(cls, value)


def _new_address(cls: type[Address], value: str) -> None:
    _new.Address(cls, value)


def _checksum_internal(value: str) -> None:
    Address._Address__checksum(value)  # type: ignore[attr-defined]


@pytest.mark.benchmark(group="address_checksum")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_checksum(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 100, Address.checksum, address)


@pytest.mark.benchmark(group="address_construct")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_construct(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 100, Address, address)


@pytest.mark.benchmark(group="address_reduce")
def test_address_reduce(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 100, _reduce, ADDRESS_INSTANCE)


@pytest.mark.benchmark(group="address_decode_hook")
def test_address_decode_hook(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 100, _decode_hook, Address, ADDRESS_CHECKSUM)


@pytest.mark.benchmark(group="address_decode_hook_unsafe")
def test_address_decode_hook_unsafe(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 100, _decode_hook_unsafe, Address, ADDRESS_CHECKSUM)


@pytest.mark.benchmark(group="address_new_function")
def test_address_new_function(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 100, _new_address, Address, ADDRESS_CHECKSUM)


@pytest.mark.benchmark(group="address_checksum_internal")
def test_address_checksum_internal(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 100, _checksum_internal, ADDRESS_LOWER)
