from enum import Enum
from functools import cached_property
from typing import ClassVar, Literal, Optional

from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from evmspec._enum import StringToIntEnumMeta
from evmspec.data import Address, _decode_hook
from evmspec.trace._base import _ActionBase, _FilterTraceBase, _ResultBase


class Type(Enum, metaclass=StringToIntEnumMeta):
    """
    Enum representing the types of contract calls: call, delegatecall, and staticcall.
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
    type: ClassVar[Literal["call"]] = "call"

    _action: Raw = field(name="action")  # type: ignore [assignment]
    """The call action, parity style."""

    @cached_property
    def action(self) -> Action:
        """The call action, parity style."""
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    result: Optional[Result]
    """
    The result object, parity style.
    
    None if the call errored. Error details will be included in the error field.
    """

    error: str = UNSET  # type: ignore [assignment]
    """The error message, if an error occurred."""
