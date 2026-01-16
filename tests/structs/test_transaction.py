import json

import pytest

pytest.importorskip("dictstruct")
from faster_hexbytes import HexBytes  # type: ignore [import-not-found]
from msgspec import Raw

from evmspec.data import Address, BlockHash, BlockNumber, Nonce, TransactionHash, Wei, uint
from evmspec.data._ids import ChainId, TransactionIndex
from evmspec.structs.transaction import AccessListEntry, Transaction2930, Transaction7702


ADDRESS = "0x" + "11" * 20
ADDRESS_2 = "0x" + "22" * 20
TX_HASH = "0x" + "33" * 32
BLOCK_HASH = "0x" + "44" * 32
STORAGE_KEY = "0x" + "55" * 32


def _raw(value) -> Raw:
    return Raw(json.dumps(value).encode())


def _base_tx_kwargs() -> dict[str, object]:
    return {
        "input": HexBytes("0x"),
        "hash": TransactionHash(TX_HASH),
        "to": Address(ADDRESS),
        "gas": Wei(21_000),
        "value": Wei(0),
        "nonce": Nonce(1),
        "chainId": ChainId(1),
        "sender": Address(ADDRESS),
        "blockHash": BlockHash(BLOCK_HASH),
        "blockNumber": BlockNumber(1),
        "transactionIndex": TransactionIndex(0),
        "v": uint(1),
        "r": HexBytes("0x1"),
        "s": HexBytes("0x2"),
        "gasPrice": Wei(1),
    }


def test_access_list_entry_storage_keys() -> None:
    entry = AccessListEntry(address=Address(ADDRESS), _storageKeys=_raw([STORAGE_KEY]))
    storage_keys = entry.storageKeys
    assert len(storage_keys) == 1
    assert storage_keys[0].hex() == STORAGE_KEY


def test_transaction_access_list_decode() -> None:
    access_list = [
        {"address": ADDRESS_2, "storageKeys": [STORAGE_KEY]},
    ]
    tx = Transaction2930(_accessList=_raw(access_list), **_base_tx_kwargs())
    decoded = tx.accessList
    assert len(decoded) == 1
    assert decoded[0].address == Address(ADDRESS_2)
    assert decoded[0].storageKeys[0].hex() == STORAGE_KEY


def test_transaction_authorization_list_decode() -> None:
    authorization_list = [
        {
            "chainId": "0x1",
            "address": ADDRESS,
            "nonce": "0x1",
            "gas": "0x5208",
            "yParity": "0x1",
            "r": "0x1",
            "s": "0x2",
        }
    ]
    tx = Transaction7702(
        _authorizationList=_raw(authorization_list),
        maxFeePerGas=Wei(1),
        maxPriorityFeePerGas=Wei(1),
        **_base_tx_kwargs(),
    )
    decoded = tx.authorizationList
    assert len(decoded) == 1
    assert decoded[0].address == Address(ADDRESS)
    assert decoded[0].chainId == ChainId(1)


def test_transaction_getitem_and_hash() -> None:
    tx = Transaction2930(**_base_tx_kwargs())
    assert tx["from"] == Address(ADDRESS)
    assert tx.block == BlockNumber(1)
    assert hash(tx) == hash(tx.hash.hex())

    with pytest.raises(KeyError) as exc_info:
        _ = tx["missing"]
    assert str(exc_info.value) == "'missing'"
