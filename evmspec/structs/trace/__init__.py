from typing import Union

from evmspec.structs.trace import call, create, reward, suicide

FilterTrace = Union[call.Trace, create.Trace, reward.Trace, suicide.Trace]
"""A type alias for filtering trace types.

FilterTrace is a Union of the following trace types:
- :class:`evmspec.structs.trace.call.Trace`
- :class:`evmspec.structs.trace.create.Trace`
- :class:`evmspec.structs.trace.reward.Trace`
- :class:`evmspec.structs.trace.suicide.Trace`

Examples:
    You can use `FilterTrace` to specify a variable that can hold any of the trace types:
    
    >>> from evmspec.structs.trace import FilterTrace
    >>> trace: FilterTrace = call.Trace(...)
    >>> trace = create.Trace(...)
    >>> trace = reward.Trace(...)
    >>> trace = suicide.Trace(...)

See Also:
    - :class:`evmspec.structs.trace.call.Trace`
    - :class:`evmspec.structs.trace.create.Trace`
    - :class:`evmspec.structs.trace.reward.Trace`
    - :class:`evmspec.structs.trace.suicide.Trace`
"""

__all__ = ["call", "create", "reward", "suicide", "FilterTrace"]
