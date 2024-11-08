from typing import Union

from evmspec.trace import call, create, reward, suicide

FilterTrace = Union[call.Trace, create.Trace, reward.Trace, suicide.Trace]
