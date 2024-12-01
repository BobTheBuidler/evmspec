from typing import List

from dictstruct import DictStruct, LazyDictStruct
from msgspec import UNSET, field

from evmspec.data import Address, BlockHash, BlockNumber, TransactionHash, Wei, uint


class _ActionBase(
    LazyDictStruct,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Base class for representing actions in parity-style Ethereum traces.

    This class provides common attributes for transaction actions such as the
    sender address, the amount of ETH transferred, and the gas provided.

    This class is intended to be subclassed and not instantiated directly.

    See Also:
        - :class:`_ResultBase` for representing results in traces.
        - :class:`_FilterTraceBase` for representing trace details.
    """

    sender: Address = field(name="from")
    """The sender address.

    Note:
        This attribute is mapped to the :func:`~msgspec.field` name 'from'
        during serialization and deserialization.

    Examples:
        >>> from msgspec import json
        >>> class MyAction(_ActionBase):
        ...     pass
        >>> action = json.decode(b'{"from": "0xabc...", "value": 1000, "gas": 21000}', type=MyAction)
        >>> action.sender
        '0xabc...'
    """

    value: Wei
    """The amount of ETH sent in this action (transaction).

    Examples:
        >>> from msgspec import json
        >>> class MyAction(_ActionBase):
        ...     pass
        >>> action = json.decode(b'{"from": "0xabc...", "value": 1000, "gas": 21000}', type=MyAction)
        >>> action.value
        1000
    """

    gas: Wei
    """The gas provided.

    Examples:
        >>> from msgspec import json
        >>> class MyAction(_ActionBase):
        ...     pass
        >>> action = json.decode(b'{"from": "0xabc...", "value": 1000, "gas": 21000}', type=MyAction)
        >>> action.gas
        21000
    """


class _ResultBase(
    DictStruct,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Base class for representing results in parity-style Ethereum traces.

    This class encapsulates the outcome of transaction actions, specifically
    the amount of gas used by the transaction.

    You must subclass this class for various result types. Do not initialize this class directly.

    See Also:
        - :class:`_ActionBase` for representing actions in traces.
        - :class:`_FilterTraceBase` for representing trace details.
    """

    gasUsed: Wei
    """The amount of gas used by this transaction.

    Examples:
        >>> class MyResult(_ResultBase):
        ...     pass
        >>> result = MyResult(gasUsed=21000)
        >>> result.gasUsed
        21000
    """


class _FilterTraceBase(
    LazyDictStruct,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Base class for representing parity-style traces.

    This class contains attributes detailing the block and transaction being traced,
    including block number and hash, transaction hash, position, trace addresses,
    subtraces, and errors if any occurred during execution.

    You must subclass this class for various trace types. Do not initialize this class directly.

    See Also:
        - :class:`_ActionBase` for representing actions in traces.
        - :class:`_ResultBase` for representing results in traces.
    """

    blockNumber: BlockNumber
    """The number of the block where this action happened.

    Examples:
        >>> trace = _FilterTraceBase(blockNumber=123456, ...)
        >>> trace.blockNumber
        123456
    """

    blockHash: BlockHash
    """The hash of the block where this action happened.

    Examples:
        >>> trace = _FilterTraceBase(blockHash="0xabc...", ...)
        >>> trace.blockHash
        '0xabc...'
    """

    transactionHash: TransactionHash
    """The hash of the transaction being traced.

    Examples:
        >>> trace = _FilterTraceBase(transactionHash="0xdef...", ...)
        >>> trace.transactionHash
        '0xdef...'
    """

    transactionPosition: int
    """The position of the transaction in the block.

    Examples:
        >>> trace = _FilterTraceBase(transactionPosition=1, ...)
        >>> trace.transactionPosition
        1
    """

    traceAddress: List[uint]
    """The trace addresses (array) representing the path of the call within the trace tree.

    Examples:
        >>> trace = _FilterTraceBase(traceAddress=[0, 1], ...)
        >>> trace.traceAddress
        [0, 1]
    """

    subtraces: uint
    """The number of traces of internal transactions that occurred during this transaction.

    Examples:
        >>> trace = _FilterTraceBase(subtraces=2, ...)
        >>> trace.subtraces
        2
    """

    error: str = UNSET  # type: ignore [assignment]
    """An error message if an error occurred during the execution of the transaction. Defaults to UNSET.

    Examples:
        >>> trace = _FilterTraceBase(error=UNSET, ...)
        >>> trace.error
        UNSET
    """

    @property
    def block(self) -> BlockNumber:
        """A shorthand getter for 'blockNumber'.

        Examples:
            >>> trace = _FilterTraceBase(blockNumber=123456, ...)
            >>> trace.block
            123456
        """
        return self.blockNumber
