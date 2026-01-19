from collections.abc import Callable
from typing import Any


def batch(iterations: int, func: Callable[..., Any], *args: Any, **kwargs: Any) -> None:
    for _ in range(iterations):
        func(*args, **kwargs)
