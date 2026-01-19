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


@pytest.mark.benchmark(group="address_checksum")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_checksum(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 1000, Address.checksum, address)


@pytest.mark.benchmark(group="address_construct")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_construct(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 1000, Address, address)


@pytest.mark.benchmark(group="address_reduce")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_reduce(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 1000, _reduce, address)


@pytest.mark.benchmark(group="address_decode_hook")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_decode_hook(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 1000, Address._decode_hook, Address, address)


@pytest.mark.benchmark(group="address_decode_hook_unsafe")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_decode_hook_unsafe(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 1000, Address._decode_hook_unsafe, Address, address)


@pytest.mark.benchmark(group="address_new_function")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_new_function(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 1000, _new.Address, Address, address)


@pytest.mark.benchmark(group="address_checksum_internal")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_checksum_internal(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 1000, Address._Address__checksum, address)
