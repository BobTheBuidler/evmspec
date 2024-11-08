
from enum import Enum
from hexbytes import HexBytes

from evmspec._enum import StringToIntEnumMeta
from evmspec.data import Address
from evmspec.trace._base import _ActionBase


class Type(Enum, metaclass=StringToIntEnumMeta):
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
):
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

    output: HexBytes
    """The output of this transaction."""