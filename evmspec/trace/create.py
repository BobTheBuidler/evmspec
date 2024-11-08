
from hexbytes import HexBytes

from evmspec.data import Address
from evmspec.trace._base import _ActionBase


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