# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.structs.receipt import Status
from evmspec.structs.trace import call, reward


@pytest.mark.benchmark(group="call_type_enum_str")
def test_call_type_enum_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, call.Type, "call")


@pytest.mark.benchmark(group="call_type_enum_int")
def test_call_type_enum_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, call.Type, 0)


@pytest.mark.benchmark(group="reward_type_enum_str")
def test_reward_type_enum_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, reward.Type, "block")


@pytest.mark.benchmark(group="reward_type_enum_int")
def test_reward_type_enum_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, reward.Type, 0)


@pytest.mark.benchmark(group="status_enum_hex")
def test_status_enum_hex(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, Status, "0x1")
