
from enum import Enum

from evmspec._enum import StringToIntEnumMeta


class Type(Enum, metaclass=StringToIntEnumMeta):
    block = 0
    uncle = 1