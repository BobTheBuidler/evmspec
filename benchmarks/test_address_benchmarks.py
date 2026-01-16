# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import ADDRESS_CASES, ADDRESS_CASE_IDS
from evmspec.data import Address


@pytest.mark.benchmark(group="address_checksum")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_checksum(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 100, Address.checksum, address)


@pytest.mark.benchmark(group="address_construct")
@pytest.mark.parametrize("address", ADDRESS_CASES, ids=ADDRESS_CASE_IDS)
def test_address_construct(benchmark: BenchmarkFixture, address: str) -> None:
    benchmark(batch, 100, Address, address)
