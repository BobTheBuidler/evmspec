import json

import pytest
from faster_hexbytes import HexBytes  # type: ignore [import-not-found]
from msgspec import Raw
from msgspec import ValidationError

from evmspec.data import Address, BlockHash, BlockNumber, TransactionHash, Wei, uint
pytest.importorskip("dictstruct")

from evmspec.structs.trace import call, create, reward, suicide


ADDRESS = "0x" + "11" * 20
ADDRESS_2 = "0x" + "22" * 20
TX_HASH = "0x" + "33" * 32
BLOCK_HASH = "0x" + "44" * 32


def _raw(value) -> Raw:
    return Raw(json.dumps(value).encode())


def _base_trace_kwargs() -> dict[str, object]:
    return {
        "blockNumber": BlockNumber(1),
        "blockHash": BlockHash(BLOCK_HASH),
        "transactionHash": TransactionHash(TX_HASH),
        "transactionPosition": 0,
        "traceAddress": [uint(0)],
        "subtraces": uint(0),
    }


def test_call_trace_action_decode() -> None:
    action = {
        "from": ADDRESS,
        "value": "0x1",
        "gas": "0x5208",
        "callType": "call",
        "to": ADDRESS_2,
        "input": "0x",
    }
    trace = call.Trace(_action=_raw(action), result=None, **_base_trace_kwargs())
    decoded = trace.action
    assert decoded.callType is call.Type.call
    assert decoded.sender == Address(ADDRESS)
    assert trace.block == BlockNumber(1)


def test_create_trace_action_decode() -> None:
    action = {
        "from": ADDRESS,
        "value": "0x0",
        "gas": "0x5208",
        "init": "0x6000",
        "creationMethod": "create",
    }
    result = create.Result(
        gasUsed=Wei(21_000),
        address=Address(ADDRESS),
        code=HexBytes("0x6000"),
    )
    trace = create.Trace(_action=_raw(action), result=result, **_base_trace_kwargs())
    decoded = trace.action
    assert decoded.init == HexBytes("0x6000")


def test_create_trace_action_validation_error_logs(caplog) -> None:
    trace = create.Trace(_action=_raw({}), result=None, **_base_trace_kwargs())
    with pytest.raises(ValidationError):
        _ = trace.action
    assert "error decoding" in caplog.text


def test_reward_trace_action_decode() -> None:
    action = {
        "from": ADDRESS,
        "value": "0x1",
        "gas": "0x5208",
        "author": ADDRESS_2,
        "rewardType": "block",
    }
    trace = reward.Trace(_action=_raw(action), **_base_trace_kwargs())
    decoded = trace.action
    assert decoded.rewardType is reward.Type.block
    assert decoded.author == Address(ADDRESS_2)


def test_suicide_trace() -> None:
    action = suicide.Action(sender=Address(ADDRESS), value=Wei(1), gas=Wei(21_000))
    trace = suicide.Trace(action=action, result=None, **_base_trace_kwargs())
    assert trace.type == "suicide"
    assert trace.action.sender == Address(ADDRESS)
