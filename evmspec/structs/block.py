import logging
from functools import cached_property
from typing import Tuple, Union

from dictstruct import DictStruct, LazyDictStruct
from hexbytes import HexBytes
from msgspec import UNSET, Raw, ValidationError, field, json

from evmspec.data import (
    Address,
    BlockHash,
    BlockNumber,
    Nonce,
    TransactionHash,
    UnixTimestamp,
    Wei,
    _decode_hook,
    uint,
)
from evmspec.data._ids import IntId
from evmspec.structs.transaction import Transaction, TransactionRLP


logger = logging.getLogger(__name__)

Transactions = Union[
    Tuple[TransactionHash, ...],
    Tuple[Transaction, ...],
]
"""
Represents a collection of transactions within a block, which can be
either transaction hashes or full transaction objects.

Examples:
    >>> tx_hashes = (TransactionHash("0x..."), TransactionHash("0x..."))
    >>> tx_objects = (Transaction(...), Transaction(...))

See Also:
    - :class:`evmspec.transaction.Transaction`
"""


class TinyBlock(LazyDictStruct, frozen=True, kw_only=True, dict=True):  # type: ignore [call-arg]
    """
    Represents a minimal block structure with essential fields.

    The `_transactions` attribute can contain either transaction hashes, full transaction objects,
    or `TransactionRLP` objects, depending on the context of the RPC call used to retrieve the block, such as
    `eth_getBlockByHash` or `eth_getBlockByNumber`.

    See Also:
        - :class:`evmspec.transaction.Transaction`
        - :class:`evmspec.transaction.TransactionRLP`
    """

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""

    _transactions: Raw = field(name="transactions")
    """Array of transaction objects, or 32 Bytes transaction hashes depending on the context of the RPC call."""

    @cached_property
    def transactions(self) -> Transactions:
        """
        Decodes and returns the transactions in the block.

        Returns:
            A tuple of transaction objects or transaction hashes.

        Examples:
            >>> block = TinyBlock(timestamp=..., _transactions=...)
            >>> transactions = block.transactions
        """
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

                if "Object contains unknown field" not in arg0:
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
    """
    Represents a full Ethereum block with all standard fields.

    See Also:
        - :class:`TinyBlock`
    """

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
    """An array of uncle hashes."""

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
    """
    Represents a mined Ethereum block with difficulty fields.

    See Also:
        - :class:`Block`
    """

    difficulty: uint
    """The difficulty at this block.

    Examples:
        >>> mined_block = MinedBlock(...)
        >>> mined_block.difficulty
        uint(123456789)
    """

    totalDifficulty: uint
    """The total difficulty of the chain until this block.

    Examples:
        >>> mined_block = MinedBlock(...)
        >>> mined_block.totalDifficulty
        uint(987654321)
    """


class BaseBlock(MinedBlock, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    Represents a base Ethereum block with base fee per gas.

    See Also:
        - :class:`MinedBlock`
    """

    baseFeePerGas: Wei
    """The base fee per gas."""


class StakingWithdrawal(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """A Struct representing an Ethereum staking withdrawal.

    See Also:
        - :class:`ShanghaiCapellaBlock`
    """

    index: IntId

    amount: Wei = UNSET  # type: ignore [assignment]
    """This field is not always present."""

    address: Address = UNSET  # type: ignore [assignment]
    """This field is not always present."""

    validatorIndex: IntId = UNSET  # type: ignore [assignment]
    """This field is not always present."""


class ShanghaiCapellaBlock(Block, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    Represents a block from the Ethereum Shanghai or Capella upgrades, which includes staking withdrawals.

    See Also:
        - :class:`Block`
        - :class:`StakingWithdrawal`
    """

    _withdrawals: Raw = field(name="withdrawals")
    """This field is specific to the Shanghai and Capella upgrades in Ethereum."""

    @cached_property
    def withdrawals(self) -> Tuple[StakingWithdrawal, ...]:
        """
        Decodes and returns the staking withdrawals in the block.

        Returns:
            A tuple of staking withdrawal objects.

        Examples:
            >>> block = ShanghaiCapellaBlock(...)
            >>> withdrawals = block.withdrawals

        See Also:
            - :class:`StakingWithdrawal`
        """
        return json.decode(
            self._withdrawals, type=Tuple[StakingWithdrawal, ...], dec_hook=_decode_hook
        )
