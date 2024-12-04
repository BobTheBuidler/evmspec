from enum import Enum
from functools import cached_property
from typing import ClassVar, Literal, Optional

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from evmspec.data import Address, _decode_hook
from evmspec.data._enum import StringToIntEnumMeta
from evmspec.structs.trace._base import _ActionBase, _FilterTraceBase, _ResultBase


class Type(Enum, metaclass=StringToIntEnumMeta):
    """
    Enum representing the types of contract calls: call, delegatecall, and staticcall.

    Examples:
        >>> Type.call
        <Type.call: 0>
        >>> Type.delegatecall
        <Type.delegatecall: 1>
        >>> Type.staticcall
        <Type.staticcall: 2>

    See Also:
        - :class:`Action`
        - :class:`Trace`
    """

    call = 0
    delegatecall = 1
    staticcall = 2


class Action(
    _ActionBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    Action type for contract calls.

    Examples:
        >>> action = Action(callType=Type.call, to=Address("0x0"), input=HexBytes("0x"))
        >>> action.callType
        <Type.call: 0>
        >>> action.to
        '0x0000000000000000000000000000000000000000'
        >>> action.input
        HexBytes('0x')
    """

    callType: Type
    """The type of the call."""

    to: Address
    """The receiver address."""

    input: HexBytes
    """The input data of the action (transaction)."""


class Result(_ResultBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents the result of a contract call action, including the output data of the contract call.

    Attributes:
        output: The output of this transaction.

    Examples:
        >>> result = Result(output=HexBytes("0x"))
        >>> result.output
        HexBytes('0x')
    """

    output: HexBytes
    """The output of this transaction."""


class Trace(
    _FilterTraceBase,
    tag="call",
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    Represents a trace of a contract call, including action and result details.

    Examples:
        >>> data = b'{"type": "call", "action": {"callType": 0, "to": "0x0", "input": "0x"}, "result": null, "error": "out of gas"}'
        >>> trace = msgspec.json.decode(data, type=Trace)
        >>> trace = Trace(_action=Raw(b'{"callType": 0, "to": "0x0", "input": "0x"}'), result=None)
        >>> trace.type
        'call'
        >>> trace.action.callType
        <Type.call: 0>
        >>> trace.result is None
        True
        >>> trace.error
        "out of gas"

    See Also:
        - :class:`Action`
        - :class:`Result`
    """

    type: ClassVar[Literal["call"]] = "call"
    """A class-level constant identifying the trace type as a contract call trace.

    This attribute is used to distinguish this trace from other types of traces
    within the Ethereum Virtual Machine (EVM).

    Examples:
        >>> Trace.type
        'call'
    """

    _action: Raw = field(name="action")  # type: ignore [assignment]
    """The raw call action data, parity style."""

    @cached_property
    def action(self) -> Action:
        """The decoded call action, parity style."""
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    result: Optional[Result]
    """
    The result object, parity style.

    None if the call errored. Error details will be included in the error field.
    """

    error: str = UNSET  # type: ignore [assignment]
    """The error message, if an error occurred."""
