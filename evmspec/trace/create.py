from functools import cached_property
from typing import ClassVar, Literal

from hexbytes import HexBytes
from msgspec import Raw, field, json

from evmspec.data import Address, _decode_hook
from evmspec.trace._base import _ActionBase, _FilterTraceBase, _ResultBase


class Action(
    _ActionBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Represents the action type for contract creations.

    This class captures the initialization code necessary for deploying a 
    new contract on the Ethereum Virtual Machine (EVM).
    """

    init: HexBytes
    """The init code for the deployed contract."""


class Result(_ResultBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """Represents the result of a contract creation action.

    It includes details such as the address and bytecode of the newly 
    deployed contract. This information is essential for verifying the 
    deployment was successful and retrieving the contract's code.
    """

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
):  # type: ignore [call-arg]
    """Represents a trace of a contract deployment.

    Provides a detailed trace structure which includes both raw and decoded 
    versions of the action data used during the contract deployment on the 
    Ethereum network.
    """

    type: ClassVar[Literal["create"]] = "create"

    _action: Raw = field(name="action")
    """The raw create action data, following the parity format."""

    @cached_property
    def action(self) -> Action:
        """Decodes the raw action data into an Action object using parity style.

        Utilizes the `_action` field for decoding, transforming it into a 
        structured Action object that represents the specific details 
        of the contract creation process.
        """
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    result: Result
    """The result object, adhering to the parity format, containing deployment details."""