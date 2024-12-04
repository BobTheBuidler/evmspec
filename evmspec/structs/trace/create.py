from functools import cached_property
from typing import ClassVar, Literal

from hexbytes import HexBytes
from msgspec import Raw, field, json

from evmspec.data import Address, _decode_hook
from evmspec.structs.trace._base import _ActionBase, _FilterTraceBase, _ResultBase


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

    Examples:
        >>> action = Action(init=HexBytes("0x6000600055"))
        >>> action.init
        HexBytes('0x6000600055')

    See Also:
        - :class:`evmspec.structs.trace._base._ActionBase`
    """

    init: HexBytes
    """The init code for the deployed contract."""


class Result(
    _ResultBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Represents the result of a contract creation action.

    It includes details such as the address and bytecode of the newly
    deployed contract. This information is essential for verifying the
    deployment was successful and retrieving the contract's code.

    Examples:
        >>> result = Result(address=Address("0x1234567890abcdef1234567890abcdef12345678"), code=HexBytes("0x6000600055"))
        >>> result.address
        '0x1234567890abcdef1234567890abcdef12345678'
        >>> result.code
        HexBytes('0x6000600055')

    See Also:
        - :class:`evmspec.structs.trace._base._ResultBase`
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

    Provides a detailed trace structure which includes raw action data
    and a property to decode this data into a structured :class:`Action` object
    representing the specific details of the contract creation process.

    Examples:
        >>> trace = Trace(_action=Raw(b'{"init":"0x6000600055"}'), result=Result(address=Address("0x1234567890abcdef1234567890abcdef12345678"), code=HexBytes("0x6000600055")))
        >>> trace.type
        'create'
        >>> trace.action.init
        HexBytes('0x6000600055')

    See Also:
        - :class:`evmspec.structs.trace._base._FilterTraceBase`
        - :class:`Action`
        - :class:`Result`
    """

    type: ClassVar[Literal["create"]] = "create"
    """A class-level constant identifying the trace type as a contract creation trace.

    This attribute is used to distinguish this trace from other types of traces
    within the Ethereum Virtual Machine (EVM).

    Examples:
        >>> Trace.type
        'create'
    """

    _action: Raw = field(name="action")
    """The raw action data for contract creation, stored as a :class:`msgspec.Raw` type.

    This field holds the raw data that will be decoded into an :class:`Action` object
    using the :attr:`action` property.

    See Also:
        - :attr:`action` for decoding this raw data.
    """

    @cached_property
    def action(self) -> Action:
        """Decodes the raw action data into an :class:`Action` object.

        Utilizes the `_action` field for decoding, transforming it into a
        structured :class:`Action` object that represents the specific details
        of the contract creation process.

        Examples:
            >>> trace = Trace(_action=Raw(b'{"init":"0x6000600055"}'), result=Result(address=Address("0x1234567890abcdef1234567890abcdef12345678"), code=HexBytes("0x6000600055")))
            >>> trace.action.init
            HexBytes('0x6000600055')
        """
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)

    result: Result
    """The result object, adhering to the parity format, containing deployment details.

    This includes the address and bytecode of the deployed contract, which are
    essential for verifying the deployment was successful and retrieving the
    contract's code.

    See Also:
        - :class:`Result` for more details on the result structure.
    """
