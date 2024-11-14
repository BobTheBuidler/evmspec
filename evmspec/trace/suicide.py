from typing import ClassVar, Literal

from evmspec.trace._base import _ActionBase, _FilterTraceBase


class Action(
    _ActionBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Represents the action type for contract suicides.

    This class captures the details of the self-destruct operation
    for contract suicides. It inherits attributes from
    :class:`_ActionBase` that provide common details such as sender,
    value, and gas for Ethereum transaction actions.

    See Also:
        - :class:`_ActionBase` for common action attributes.

    Examples:
        >>> from evmspec.trace.suicide import Action
        >>> action = Action(sender="0x123", value=1000, gas=21000)
        >>> action.sender
        '0x123'
        >>> action.value
        1000
        >>> action.gas
        21000
    """


class Trace(
    _FilterTraceBase,
    tag="suicide",
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Represents a trace of a contract self-destruct operation.

    This class provides a detailed trace of a contract `suicide` action
    including the specific action taken and the result of the operation,
    conforming to the structure of a parity-style Ethereum trace.

    Attributes:
        type: The constant literal denoting the trace type as 'suicide'.
        action: The suicide action, parity style.
        result: Explicitly set to None, indicating no meaningful result is expected
            from a contract self-destruct operation.

    See Also:
        - :class:`_FilterTraceBase` for common trace attributes.
        - :class:`Action` for details on the action attribute.

    Examples:
        >>> from evmspec.trace.suicide import Trace, Action
        >>> trace = Trace(
        ...     blockNumber=123456,
        ...     blockHash="0xabc",
        ...     transactionHash="0xdef",
        ...     transactionPosition=1,
        ...     traceAddress=[0],
        ...     subtraces=0,
        ...     action=Action(sender="0x123", value=1000, gas=21000),
        ...     result=None
        ... )
        >>> trace.type
        'suicide'
        >>> trace.action.sender
        '0x123'
        >>> trace.result is None
        True
    """

    type: ClassVar[Literal["suicide"]] = "suicide"
    """The constant literal denoting the trace type as 'suicide'."""

    action: Action
    """The suicide action, parity style."""

    result: Literal[None]
    """Explicitly set to None, indicating no meaningful result is expected 
    from a contract self-destruct operation."""
