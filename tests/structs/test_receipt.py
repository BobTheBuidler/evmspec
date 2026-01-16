import json

import pytest
from msgspec import Raw

pytest.importorskip("dictstruct")

from evmspec.data import BlockNumber, TransactionHash, Wei
from evmspec.data._ids import TransactionIndex
from evmspec.structs.receipt import Status, TransactionReceipt

ADDRESS = "0x" + "11" * 20
TX_HASH = "0x" + "22" * 32
TOPIC = "0x" + "44" * 32


def _raw(value) -> Raw:
    return Raw(json.dumps(value).encode())


def _logs_raw() -> Raw:
    logs = [
        {
            "address": ADDRESS,
            "topics": [TOPIC],
            "data": "0x",
            "removed": False,
            "blockNumber": "0x1",
            "transactionHash": TX_HASH,
            "logIndex": "0x0",
            "transactionIndex": "0x0",
        }
    ]
    return _raw(logs)


def test_status_hex_enum() -> None:
    assert Status("0x1") is Status.success
    assert Status("0x0") is Status.failure


def test_transaction_receipt_logs_decode() -> None:
    receipt = TransactionReceipt(
        transactionHash=TransactionHash(TX_HASH),
        blockNumber=BlockNumber(1),
        contractAddress=None,
        transactionIndex=TransactionIndex(0),
        status=Status.success,
        gasUsed=Wei(21_000),
        cumulativeGasUsed=Wei(21_000),
        _logs=_logs_raw(),
    )
    logs = receipt.logs
    assert len(logs) == 1
    assert logs[0].transactionHash == TransactionHash(TX_HASH)


def test_transaction_receipt_fee_stats_decode() -> None:
    fee_stats = {
        "paid": {
            "l1Calldata": "0x1",
            "l2Storage": "0x2",
            "l1Transaction": "0x3",
            "l2Computation": "0x4",
        }
    }
    receipt = TransactionReceipt(
        transactionHash=TransactionHash(TX_HASH),
        blockNumber=BlockNumber(1),
        contractAddress=None,
        transactionIndex=TransactionIndex(0),
        status=Status.success,
        gasUsed=Wei(21_000),
        cumulativeGasUsed=Wei(21_000),
        _logs=_logs_raw(),
        _feeStats=_raw(fee_stats),
    )
    decoded = receipt.feeStats
    assert decoded.paid.l1Calldata == Wei(1)
    assert not hasattr(decoded, "unitsUsed")
    assert not hasattr(decoded, "prices")
