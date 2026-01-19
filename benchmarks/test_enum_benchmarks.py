# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.structs.receipt import Status
from evmspec.structs.trace import call, reward

CALL_TYPE_CASES = [
    ("call", "str-call"),
    ("delegatecall", "str-delegatecall"),
    ("staticcall", "str-staticcall"),
    (0, "int-call"),
    (1, "int-delegatecall"),
    (2, "int-staticcall"),
    (call.Type.call, "enum-call"),
    (call.Type.delegatecall, "enum-delegatecall"),
    (call.Type.staticcall, "enum-staticcall"),
]
CALL_TYPE_VALUES = [value for value, _ in CALL_TYPE_CASES]
CALL_TYPE_IDS = [case_id for _, case_id in CALL_TYPE_CASES]

REWARD_TYPE_CASES = [
    ("block", "str-block"),
    ("uncle", "str-uncle"),
    (0, "int-block"),
    (1, "int-uncle"),
    (reward.Type.block, "enum-block"),
    (reward.Type.uncle, "enum-uncle"),
]
REWARD_TYPE_VALUES = [value for value, _ in REWARD_TYPE_CASES]
REWARD_TYPE_IDS = [case_id for _, case_id in REWARD_TYPE_CASES]


@pytest.mark.benchmark(group="call_type_enum")
@pytest.mark.parametrize("value", CALL_TYPE_VALUES, ids=CALL_TYPE_IDS)
def test_call_type_enum(benchmark: BenchmarkFixture, value) -> None:
    benchmark(batch, 2000, call.Type, value)


@pytest.mark.benchmark(group="reward_type_enum")
@pytest.mark.parametrize("value", REWARD_TYPE_VALUES, ids=REWARD_TYPE_IDS)
def test_reward_type_enum(benchmark: BenchmarkFixture, value) -> None:
    benchmark(batch, 2000, reward.Type, value)


@pytest.mark.benchmark(group="status_enum_hex")
def test_status_enum_hex(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 2000, Status, "0x1")
