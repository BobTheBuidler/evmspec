from typing import Union

from evmspec.trace import call, create, reward, suicide

FilterTrace = Union[call.Trace, create.Trace, reward.Trace, suicide.Trace]
"""A type alias for filtering trace types.

FilterTrace is a Union of the following trace types:
- :class:`evmspec.trace.call.Trace
- :class:`evmspec.trace.create.Trace
- :class:`evmspec.trace.reward.Trace
- :class:`evmspec.trace.suicide.Trace
"""

__all__ = ["call", "create", "reward", "suicide", "FilterTrace"]
