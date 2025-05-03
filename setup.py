import tomllib
from pathlib import Path
from setuptools import setup
from mypyc.build import mypycify


with Path("pyproject.toml").open("rb") as f:
    pyproject_data = tomllib.load(f)
    poetry_config = pyproject_data["tool"]["poetry"]


setup(
    name=poetry_config["name"],
    version=poetry_config["version"],
    ext_modules=mypycify(["evmspec/_utils.py"]),
    packages=["evmspec"],
)
