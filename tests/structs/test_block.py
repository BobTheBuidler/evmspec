import json
import sys
import types

import pytest
from faster_hexbytes import HexBytes  # type: ignore [import-not-found]
from msgspec import Raw

pytest.importorskip("dictstruct")

from evmspec.data import Address, BlockHash, BlockNumber, Nonce, TransactionHash, UnixTimestamp, Wei, uint
from evmspec.structs.block import ShanghaiCapellaBlock, TinyBlock
from evmspec.structs.transaction import TransactionLegacy, TransactionRLP


ADDRESS = "0x" + "11" * 20
TX_HASH = "0x" + "22" * 32
BLOCK_HASH = "0x" + "33" * 32


def _raw(value) -> Raw:
    return Raw(json.dumps(value).encode())


def _base_tx_dict() -> dict[str, str]:
    return {
        "input": "0x",
        "hash": TX_HASH,
        "to": ADDRESS,
        "gas": "0x5208",
        "value": "0x0",
        "nonce": "0x1",
        "from": ADDRESS,
        "blockHash": BLOCK_HASH,
        "blockNumber": "0x1",
        "transactionIndex": "0x0",
        "v": "0x1",
        "r": "0x1",
        "s": "0x2",
        "gasPrice": "0x3b9aca00",
    }


def _base_block_kwargs() -> dict[str, object]:
    return {
        "timestamp": UnixTimestamp(1),
        "_transactions": Raw(b"[]"),
        "number": BlockNumber(1),
        "hash": BlockHash(BLOCK_HASH),
        "logsBloom": HexBytes("0x00"),
        "receiptsRoot": HexBytes("0x00"),
        "extraData": HexBytes("0x00"),
        "nonce": Nonce(0),
        "miner": Address(ADDRESS),
        "gasLimit": Wei(0),
        "gasUsed": Wei(0),
        "uncles": (HexBytes("0x00"),),
        "sha3Uncles": HexBytes("0x00"),
        "size": uint(1),
        "transactionsRoot": HexBytes("0x00"),
        "stateRoot": HexBytes("0x00"),
        "mixHash": HexBytes("0x00"),
        "parentHash": HexBytes("0x00"),
    }


def test_tinyblock_transactions_hashes() -> None:
    raw = _raw([TX_HASH])
    block = TinyBlock(timestamp=UnixTimestamp(1), _transactions=raw)
    txs = block.transactions
    assert txs == (TransactionHash(TX_HASH),)


def test_tinyblock_transactions_decodes_transaction() -> None:
    tx = _base_tx_dict()
    tx["type"] = "0x0"
    block = TinyBlock(timestamp=UnixTimestamp(1), _transactions=_raw([tx]))
    txs = block.transactions
    assert isinstance(txs[0], TransactionLegacy)


def test_tinyblock_transactions_rlp_fallback() -> None:
    tx = _base_tx_dict()
    block = TinyBlock(timestamp=UnixTimestamp(1), _transactions=_raw([tx]))
    txs = block.transactions
    assert isinstance(txs[0], TransactionRLP)


def test_tinyblock_transactions_dank_mids_fallback(monkeypatch) -> None:
    types_mod = types.ModuleType("dank_mids.types")

    def better_decode(_raw_tx, type=None, dec_hook=None):
        return TX_HASH

    types_mod.better_decode = better_decode
    dank_mod = types.ModuleType("dank_mids")
    dank_mod.types = types_mod
    monkeypatch.setitem(sys.modules, "dank_mids", dank_mod)
    monkeypatch.setitem(sys.modules, "dank_mids.types", types_mod)

    block = TinyBlock(timestamp=UnixTimestamp(1), _transactions=_raw([1]))
    txs = block.transactions
    assert txs == (TransactionHash(TX_HASH),)


def test_shanghai_capella_withdrawals_decode() -> None:
    withdrawals = [{"index": "0x1"}]
    block = ShanghaiCapellaBlock(_withdrawals=_raw(withdrawals), **_base_block_kwargs())
    decoded = block.withdrawals
    assert len(decoded) == 1
    assert decoded[0].index == 1
