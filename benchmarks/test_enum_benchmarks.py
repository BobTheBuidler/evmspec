# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.structs.receipt import Status
from evmspec.structs.trace import call, reward

TRACE_TYPE_CASES = [
    (call.Type, "call", "call-str-call"),
    (call.Type, "delegatecall", "call-str-delegatecall"),
    (call.Type, "staticcall", "call-str-staticcall"),
    (call.Type, 0, "call-int-call"),
    (call.Type, 1, "call-int-delegatecall"),
    (call.Type, 2, "call-int-staticcall"),
    (call.Type, call.Type.call, "call-enum-call"),
    (call.Type, call.Type.delegatecall, "call-enum-delegatecall"),
    (call.Type, call.Type.staticcall, "call-enum-staticcall"),
    (reward.Type, "block", "reward-str-block"),
    (reward.Type, "uncle", "reward-str-uncle"),
    (reward.Type, 0, "reward-int-block"),
    (reward.Type, 1, "reward-int-uncle"),
    (reward.Type, reward.Type.block, "reward-enum-block"),
    (reward.Type, reward.Type.uncle, "reward-enum-uncle"),
]
TRACE_TYPE_VALUES = [(enum_cls, value) for enum_cls, value, _ in TRACE_TYPE_CASES]
TRACE_TYPE_IDS = [case_id for _, _, case_id in TRACE_TYPE_CASES]
STATUS_CASES = [
    ("0x1", "hex-success"),
    ("0x0", "hex-failure"),
    ("1", "dec-success"),
    ("0", "dec-failure"),
    ("0X1", "hex-upper-success"),
    ("0X0", "hex-upper-failure"),
]
STATUS_VALUES = [value for value, _ in STATUS_CASES]
STATUS_IDS = [case_id for _, case_id in STATUS_CASES]


@pytest.mark.benchmark(group="trace_type_enum")
@pytest.mark.parametrize("enum_cls, value", TRACE_TYPE_VALUES, ids=TRACE_TYPE_IDS)
def test_trace_type_enum(benchmark: BenchmarkFixture, enum_cls, value) -> None:
    benchmark(batch, 20_000, enum_cls, value)


@pytest.mark.benchmark(group="status_enum")
@pytest.mark.parametrize("value", STATUS_VALUES, ids=STATUS_IDS)
def test_status_enum(benchmark: BenchmarkFixture, value) -> None:
    benchmark(batch, 20_000, Status, value)
