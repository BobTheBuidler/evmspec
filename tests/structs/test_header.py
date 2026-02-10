import json

import pytest

pytest.importorskip("dictstruct")
msgspec = pytest.importorskip("msgspec")

from faster_hexbytes import HexBytes  # type: ignore [import-not-found]

from evmspec.data import _decode_hook
from evmspec.structs.header import ErigonBlockHeader

ADDRESS = "0x" + "11" * 20
HASH_PARENT = "0x" + "22" * 32
HASH_UNCLES = "0x" + "33" * 32
HASH_STATE = "0x" + "44" * 32
HASH_TX = "0x" + "55" * 32
HASH_RECEIPTS = "0x" + "66" * 32
HASH_MIX = "0x" + "77" * 32
HASH_WITHDRAWALS = "0x" + "88" * 32
HASH_BEACON = "0x" + "99" * 32
HASH_REQUESTS = "0x" + "aa" * 32
HASH_BLOCK = "0x" + "bb" * 32


def _base_header_payload() -> dict[str, object]:
    return {
        "parentHash": HASH_PARENT,
        "sha3Uncles": HASH_UNCLES,
        "miner": ADDRESS,
        "stateRoot": HASH_STATE,
        "transactionsRoot": HASH_TX,
        "receiptsRoot": HASH_RECEIPTS,
        "logsBloom": "0x00",
        "difficulty": "0x0",
        "number": "0x1",
        "gasLimit": "0x5208",
        "gasUsed": "0x0",
        "timestamp": "0x1",
        "extraData": "0x",
        "mixHash": HASH_MIX,
        "nonce": "0x0000000000000000",
        "baseFeePerGas": "0x1",
        "withdrawalsRoot": HASH_WITHDRAWALS,
        "blobGasUsed": "0x0",
        "excessBlobGas": "0x0",
        "parentBeaconBlockRoot": HASH_BEACON,
        "requestsHash": HASH_REQUESTS,
        "blockAccessListHash": None,
        "hash": HASH_BLOCK,
        "totalDifficulty": "0x2",
    }


def test_erigon_header_decodes_sha3uncles() -> None:
    payload = _base_header_payload()
    encoded = json.dumps(payload).encode()
    header = msgspec.json.decode(encoded, type=ErigonBlockHeader, dec_hook=_decode_hook)
    assert header.sha3Uncles == HexBytes(payload["sha3Uncles"])
    assert header.uncleHash == header.sha3Uncles
    assert header.blockAccessListHash is None
