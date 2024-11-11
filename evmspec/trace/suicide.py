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
    for contract suicides, with attributes inherited from _ActionBase
    that provide common details such as sender, value, and gas for
    Ethereum transaction actions.
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
    """

    type: ClassVar[Literal["suicide"]] = "suicide"
    """The constant literal denoting the trace type as 'suicide'."""

    action: Action
    """The suicide action, parity style."""

    result: Literal[None]
    """A literal set to None, indicating no result is expected."""
