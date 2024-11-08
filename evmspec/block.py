import logging
from functools import cached_property
from typing import Tuple, Union

from dictstruct import DictStruct, LazyDictStruct
from hexbytes import HexBytes
from msgspec import UNSET, Raw, ValidationError, field, json

from evmspec._ids import IntId
from evmspec.data import (
    Address,
    BlockHash,
    BlockNumber,
    Nonce,
    TransactionHash,
    UnixTimestamp,
    Wei,
    uint,
    _decode_hook,
)
from evmspec.transaction import Transaction, TransactionRLP


logger = logging.getLogger(__name__)

Transactions = Union[
    Tuple[TransactionHash, ...],
    Tuple[Transaction, ...],
]


class TinyBlock(LazyDictStruct, frozen=True, kw_only=True, dict=True):  # type: ignore [call-arg]

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""

    _transactions: Raw = field(name="transactions")
    """Array of transaction objects, or 32 Bytes transaction hashes depending on the last given parameter."""

    @cached_property
    def transactions(self) -> Transactions:
        """Array of transaction objects, or 32 Bytes transaction hashes depending on the last given parameter."""
        try:
            transactions = json.decode(
                self._transactions,
                type=Tuple[Union[str, Transaction], ...],
                dec_hook=_decode_hook,
            )
        except ValidationError as e:
            arg0: str = e.args[0]
            split_pos = arg0.find("$")
            if (
                split_pos >= 0
                and arg0[:split_pos] == "Object missing required field `type` - at `"
            ):
                # TODO: debug why this happens and how to build around it
                transactions = json.decode(
                    self._transactions,
                    type=Tuple[Union[str, TransactionRLP], ...],
                    dec_hook=_decode_hook,
                )
            else:
                from dank_mids.types import better_decode

                logger.exception(e)
                transactions = [
                    better_decode(
                        raw_tx, type=Union[str, Transaction], dec_hook=_decode_hook
                    )
                    for raw_tx in json.decode(self._transactions, type=Tuple[Raw, ...])
                ]
        if transactions and isinstance(transactions[0], str):
            transactions = (TransactionHash(txhash) for txhash in transactions)
        return tuple(transactions)


class Block(TinyBlock, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    number: BlockNumber
    """The block number."""

    hash: BlockHash
    """The hash of the block."""

    logsBloom: HexBytes
    """The bloom filter for the logs of the block."""

    receiptsRoot: HexBytes
    """The root of the receipts trie of the block."""

    extraData: HexBytes
    """The “extra data” field of this block."""

    nonce: Nonce
    """Hash of the generated proof-of-work."""

    miner: Address
    """The address of the miner receiving the reward."""

    gasLimit: Wei
    """The maximum gas allowed in this block."""

    gasUsed: Wei
    """The total used gas by all transactions in this block."""

    uncles: Tuple[HexBytes, ...]
    """An Array of uncle hashes."""

    sha3Uncles: HexBytes
    """SHA3 of the uncles data in the block."""

    size: uint
    """The size of the block, in bytes."""

    transactionsRoot: HexBytes
    """The root of the transaction trie of the block."""

    stateRoot: HexBytes
    """The root of the final state trie of the block."""

    mixHash: HexBytes
    """A string of a 256-bit hash encoded as a hexadecimal."""

    parentHash: HexBytes
    """Hash of the parent block."""


class MinedBlock(Block, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]

    difficulty: uint
    """The difficulty at this block."""

    totalDifficulty: uint
    """Hexadecimal of the total difficulty of the chain until this block."""


class BaseBlock(MinedBlock, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    # contains fields only seen on Base

    baseFeePerGas: Wei
    """The base fee per gas."""


class StakingWithdrawal(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """A Struct representing an Ethereum staking withdrawal."""

    index: IntId

    amount: Wei = UNSET
    """This field is not always present."""

    address: Address = UNSET
    """This field is not always present."""

    validatorIndex: IntId = UNSET
    """This field is not always present."""


class ShanghaiCapellaBlock(Block, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    # contains staking withdrawals field

    _withdrawals: Raw = field(name="withdrawals")
    """This field is only present on Ethereum."""

    @cached_property
    def withdrawals(self) -> Tuple[StakingWithdrawal, ...]:
        """This field is only present on Ethereum."""
        return json.decode(
            self._withdrawals, type=Tuple[StakingWithdrawal, ...], dec_hook=_decode_hook
        )
