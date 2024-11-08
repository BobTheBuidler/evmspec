from typing import ClassVar, Literal

from hexbytes import HexBytes
from msgspec import Raw, json, field

from evmspec.data import Address, _decode_hook
from evmspec.trace._base import _ActionBase, _FilterTraceBase


class Action(
    _ActionBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):
    """
    Action type for contract creations.
    """

    init: HexBytes
    """The init code for the deployed contract."""


class Result(_ResultBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    address: Address
    """The address of the deployed contract."""

    code: HexBytes
    """The bytecode of the deployed contract."""


class Trace(
    _FilterTraceBase,
    tag="create",
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):
    type: ClassVar[Literal["create"]] = "create"

    _action: Raw = field(name="action")
    """The create action, parity style."""

    @cached_property
    def action(self) -> Action:
        """The create action, parity style."""
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    result: Result
    """The result object, parity style."""
