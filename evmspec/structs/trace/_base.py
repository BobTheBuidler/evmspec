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
    sender address, the amount of ETH transferred, in Wei, and the gas provided.

    This class is intended to be subclassed within the repository and is not
    part of the public API. It can be instantiated directly if needed for
    internal purposes.

    Examples:
        >>> from evmspec.structs.trace._base import _ActionBase
        >>> class MyAction(_ActionBase):
        ...     pass
        >>> action = MyAction(sender="0xabc...", value=1000, gas=21000)
        >>> action.sender
        '0xabc...'

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
    """The amount of Wei sent in this action (transaction).

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

    This class is intended to be subclassed within the repository and is not
    part of the public API. It can be instantiated directly if needed for
    internal purposes.

    Examples:
        >>> from evmspec.structs.trace._base import _ResultBase
        >>> class MyResult(_ResultBase):
        ...     pass
        >>> result = MyResult(gasUsed=21000)
        >>> result.gasUsed
        21000

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

    This class is intended to be subclassed within the repository and is not
    part of the public API. It can be instantiated directly if needed for
    internal purposes.

    Examples:
        >>> from evmspec.structs.trace._base import _FilterTraceBase
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
        >>> trace.blockNumber
        123456

    See Also:
        - :class:`_ActionBase` for representing actions in traces.
        - :class:`_ResultBase` for representing results in traces.
    """

    blockNumber: BlockNumber
    """The number of the block where this action happened.

    Examples:
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
        >>> trace.blockNumber
        123456
    """

    blockHash: BlockHash
    """The hash of the block where this action happened.

    Examples:
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
        >>> trace.blockHash
        '0xabc...'
    """

    transactionHash: TransactionHash
    """The hash of the transaction being traced.

    Examples:
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
        >>> trace.transactionHash
        '0xdef...'
    """

    transactionPosition: int
    """The position of the transaction in the block.

    Examples:
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
        >>> trace.transactionPosition
        1
    """

    traceAddress: List[uint]
    """The trace addresses (array) representing the path of the call within the trace tree.

    Examples:
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
        >>> trace.traceAddress
        [0, 1]
    """

    subtraces: uint
    """The number of traces of internal transactions that occurred during this transaction.

    Examples:
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
        >>> trace.subtraces
        2
    """

    error: str = UNSET  # type: ignore [assignment]
    """An error message if an error occurred during the execution of the transaction. Defaults to UNSET.

    Examples:
        >>> class MyTrace(_FilterTraceBase):
        ...     pass
        >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2, error=UNSET)
        >>> trace.error
        UNSET
    """

    @property
    def block(self) -> BlockNumber:
        """A shorthand getter for 'blockNumber'.

        Examples:
            >>> class MyTrace(_FilterTraceBase):
            ...     pass
            >>> trace = MyTrace(blockNumber=123456, blockHash="0xabc...", transactionHash="0xdef...", transactionPosition=1, traceAddress=[0, 1], subtraces=2)
            >>> trace.block
            123456
        """
        return self.blockNumber
