# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.structs.receipt import Status
from evmspec.structs.trace import call, reward


def _call_type_str(value: str) -> None:
    call.Type(value)


def _call_type_int(value: int) -> None:
    call.Type(value)


def _reward_type_str(value: str) -> None:
    reward.Type(value)


def _reward_type_int(value: int) -> None:
    reward.Type(value)


def _status_hex(value: str) -> None:
    Status(value)


@pytest.mark.benchmark(group="call_type_enum_str")
def test_call_type_enum_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _call_type_str, "call")


@pytest.mark.benchmark(group="call_type_enum_int")
def test_call_type_enum_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _call_type_int, 0)


@pytest.mark.benchmark(group="reward_type_enum_str")
def test_reward_type_enum_str(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _reward_type_str, "block")


@pytest.mark.benchmark(group="reward_type_enum_int")
def test_reward_type_enum_int(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _reward_type_int, 0)


@pytest.mark.benchmark(group="status_enum_hex")
def test_status_enum_hex(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _status_hex, "0x1")
