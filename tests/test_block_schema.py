import json

import pytest
from msgspec import UNSET, ValidationError
from msgspec.json import Decoder

from evmspec.data import _decode_hook
from evmspec.structs.block import BaseBlock

_decode_base_block = Decoder(type=BaseBlock, dec_hook=_decode_hook).decode


def _hx(byte: str, nbytes: int) -> str:
    return "0x" + (byte * nbytes)


def _base_payload() -> dict[str, object]:
    return {
        "number": "0x1",
        "hash": _hx("11", 32),
        "logsBloom": _hx("00", 256),
        "receiptsRoot": _hx("22", 32),
        "extraData": "0x",
        "nonce": "0x0000000000000000",
        "miner": _hx("33", 20),
        "gasLimit": "0x1c9c380",
        "gasUsed": "0x0",
        "uncles": [],
        "sha3Uncles": _hx("44", 32),
        "size": "0x1",
        "transactionsRoot": _hx("55", 32),
        "stateRoot": _hx("66", 32),
        "mixHash": _hx("77", 32),
        "parentHash": _hx("88", 32),
        "timestamp": "0x1",
        "transactions": [],
        "difficulty": "0x0",
    }


def _decode(payload: dict[str, object]) -> BaseBlock:
    return _decode_base_block(json.dumps(payload).encode())


def test_baseblock_pre_london_decodes() -> None:
    block = _decode(_base_payload())

    assert getattr(block, "baseFeePerGas", UNSET) is UNSET


def test_baseblock_london_decodes() -> None:
    payload = _base_payload()
    payload["baseFeePerGas"] = "0x3b9aca00"

    block = _decode(payload)

    assert int(block.baseFeePerGas) == int(payload["baseFeePerGas"], 16)


def test_baseblock_shanghai_decodes_with_withdrawals_fields() -> None:
    payload = _base_payload()
    payload.update(
        {
            "baseFeePerGas": "0x3b9aca00",
            "withdrawalsRoot": _hx("99", 32),
            "withdrawals": [
                {
                    "index": "0x1",
                    "validatorIndex": "0x2",
                    "address": _hx("aa", 20),
                    "amount": "0x3",
                }
            ],
        }
    )

    block = _decode(payload)

    assert len(block.withdrawals) == 1
    assert str(block.withdrawals[0].address).lower() == str(payload["withdrawals"][0]["address"]).lower()


def test_baseblock_modern_decodes_with_cancun_prague_fields() -> None:
    payload = _base_payload()
    payload.update(
        {
            "baseFeePerGas": "0x6c3f71624",
            "withdrawalsRoot": _hx("9b", 32),
            "withdrawals": [],
            "blobGasUsed": "0x20000",
            "excessBlobGas": "0x10000",
            "parentBeaconBlockRoot": _hx("ab", 32),
            "requestsHash": _hx("cd", 32),
        }
    )

    block = _decode(payload)

    assert int(block.blobGasUsed) == int(payload["blobGasUsed"], 16)
    assert int(block.excessBlobGas) == int(payload["excessBlobGas"], 16)
    assert "0x" + bytes(block.parentBeaconBlockRoot).hex() == payload["parentBeaconBlockRoot"]
    assert "0x" + bytes(block.requestsHash).hex() == payload["requestsHash"]


def test_baseblock_rejects_unknown_field() -> None:
    payload = _base_payload()
    payload["baseFeePerGas"] = "0x3b9aca00"
    payload["notAField"] = "0x1"

    with pytest.raises(ValidationError, match="unknown field"):
        _decode(payload)


def test_baseblock_decode_is_field_order_deterministic() -> None:
    payload = _base_payload()
    payload.update(
        {
            "baseFeePerGas": "0x6c3f71624",
            "withdrawalsRoot": _hx("9b", 32),
            "withdrawals": [],
            "blobGasUsed": "0x20000",
            "excessBlobGas": "0x10000",
            "parentBeaconBlockRoot": _hx("ab", 32),
            "requestsHash": _hx("cd", 32),
        }
    )

    reordered = dict(reversed(list(payload.items())))

    block_a = _decode(payload)
    block_b = _decode(reordered)

    assert block_a == block_b
    assert block_a.transactions == block_b.transactions
