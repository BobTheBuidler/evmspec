from decimal import Decimal
from enum import Enum, EnumMeta
from functools import cached_property
from typing import Optional, Tuple

from dictstruct import DictStruct, LazyDictStruct
from eth_typing import HexStr
from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from evmspec.data import Address, BlockNumber, TransactionHash, Wei, _decode_hook, uint
from evmspec.data._ids import TransactionIndex
from evmspec.structs.log import Log


class FeeStats(DictStruct, frozen=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """Arbitrum includes this in the `feeStats` field of a tx receipt.

    See Also:
        :class:`ArbitrumFeeStats`
    """

    l1Calldata: Wei
    l2Storage: Wei
    l1Transaction: Wei
    l2Computation: Wei


class ArbitrumFeeStats(DictStruct, frozen=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """Arbitrum includes these with a tx receipt.

    See Also:
        :class:`FeeStats`
    """

    paid: FeeStats
    """
    The breakdown of gas paid for the transaction.

    (price * unitsUsed)
    """
    # These 2 attributes do not always exist
    unitsUsed: FeeStats = UNSET  # type: ignore [assignment]
    """The breakdown of units of gas used for the transaction."""
    prices: FeeStats = UNSET  # type: ignore [assignment]
    """The breakdown of gas prices for the transaction."""


class _HexStringToIntEnumMeta(EnumMeta):
    """
    A metaclass for Enums that allows conversion from hexadecimal string values to integer Enum members.
    """

    def __call__(cls, hexstr: HexStr, *args, **kw):
        return __em_call__(cls, int(hexstr, 16), *args, **kw)


class Status(Enum, metaclass=_HexStringToIntEnumMeta):
    """
    Enum representing the status of a transaction, indicating success or failure.

    Attributes:
        failure (int): Represents a failed transaction with a value of 0.
        success (int): Represents a successful transaction with a value of 1.

    Examples:
        >>> Status.success
        <Status.success: 1>

        >>> Status.failure
        <Status.failure: 0>
    """

    failure = 0
    success = 1


class TransactionReceipt(LazyDictStruct, frozen=True, kw_only=True, omit_defaults=True, repr_omit_defaults=True, dict=True):  # type: ignore [call-arg]
    """Represents the receipt of a transaction within a block.

    See Also:
        :class:`FullTransactionReceipt`
    """

    transactionHash: TransactionHash
    """The unique hash of this transaction.

    Examples:
        >>> receipt.transactionHash
        TransactionHash('0x...')
    """

    blockNumber: BlockNumber
    """The block number that contains the transaction.

    Examples:
        >>> receipt.blockNumber
        BlockNumber(1234567)
    """

    contractAddress: Optional[Address]
    """The contract address created, if the transaction was a contract creation, otherwise `None`.

    Examples:
        >>> receipt.contractAddress
        Address('0x...')
    """

    transactionIndex: TransactionIndex
    """The position of this transaction within the block.

    Examples:
        >>> receipt.transactionIndex
        TransactionIndex(0)
    """

    status: Status
    """The status of the transaction, represented by the :class:`Status` enum: 
    :attr:`Status.success` (1) if the transaction succeeded, :attr:`Status.failure` (0) if it failed.

    Examples:
        >>> receipt.status
        <Status.success: 1>
    """

    gasUsed: Wei
    """The amount of gas used by this transaction, not counting internal transactions, calls or delegate calls.

    Examples:
        >>> receipt.gasUsed
        Wei(21000)
    """

    cumulativeGasUsed: Wei
    """The total amount of gas used in the block up to and including this transaction.

    Examples:
        >>> receipt.cumulativeGasUsed
        Wei(100000)
    """

    _logs: Raw = field(name="logs")
    """The logs that were generated during this transaction."""

    @cached_property
    def logs(self) -> Tuple[Log, ...]:
        """The logs that were generated during this transaction.

        Examples:
            >>> receipt.logs
            (Log(...), Log(...))
        """
        return json.decode(self._logs, type=Tuple[Log, ...], dec_hook=_decode_hook)

    # These fields are only present on Mainnet.
    effectiveGasPrice: Wei = UNSET  # type: ignore [assignment]
    """
    The actual value per gas deducted from the sender's account.

    This field is only present on Mainnet.

    Examples:
        >>> receipt.effectiveGasPrice
        Wei(1000000000)
    """

    type: uint = UNSET  # type: ignore [assignment]
    """
    The transaction type.

    This field is only present on Mainnet.

    Examples:
        >>> receipt.type
        uint(2)
    """

    blobGasUsed: Wei = UNSET  # type: ignore [assignment]
    """This field is sometimes present, only on Mainnet.

    Examples:
        >>> receipt.blobGasUsed
        Wei(0)
    """

    # These fields are only present on Optimism.
    l1FeeScalar: Decimal = UNSET  # type: ignore [assignment]
    """This field is only present on Optimism.

    Examples:
        >>> receipt.l1FeeScalar
        Decimal('1.0')
    """
    l1GasUsed: Wei = UNSET  # type: ignore [assignment]
    """This field is only present on Optimism.

    Examples:
        >>> receipt.l1GasUsed
        Wei(50000)
    """
    l1GasPrice: Wei = UNSET  # type: ignore [assignment]
    """This field is only present on Optimism.

    Examples:
        >>> receipt.l1GasPrice
        Wei(1000000000)
    """
    l1Fee: Wei = UNSET  # type: ignore [assignment]
    """This field is only present on Optimism.

    Examples:
        >>> receipt.l1Fee
        Wei(50000000000)
    """

    # These fields are only present on Arbitrum.
    l1BlockNumber: BlockNumber = UNSET  # type: ignore [assignment]
    """This field is only present on Arbitrum.

    Examples:
        >>> receipt.l1BlockNumber
        BlockNumber(1234567)
    """
    l1InboxBatchInfo: Optional[HexBytes] = UNSET  # type: ignore [assignment]
    """This field is only present on Arbitrum.

    Examples:
        >>> receipt.l1InboxBatchInfo
        HexBytes('0x...')
    """
    _feeStats: Raw = field(name="feeStats", default=UNSET)  # type: ignore [assignment]
    """This field is only present on Arbitrum."""

    @cached_property
    def feeStats(self) -> ArbitrumFeeStats:
        """This field is only present on Arbitrum.

        Examples:
            >>> receipt.feeStats
            ArbitrumFeeStats(...)
        """
        return json.decode(
            self._feeStats, type=ArbitrumFeeStats, dec_hook=Wei._decode_hook
        )


class FullTransactionReceipt(TransactionReceipt, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """Extends :class:`TransactionReceipt` to include full details."""

    blockHash: HexBytes
    """The hash of the block that contains the transaction.

    Examples:
        >>> full_receipt.blockHash
        HexBytes('0x...')
    """

    logsBloom: HexBytes
    """The bloom filter for all logs in this block.

    Examples:
        >>> full_receipt.logsBloom
        HexBytes('0x...')
    """


__em_call__ = EnumMeta.__call__
