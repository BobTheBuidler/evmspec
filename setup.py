from pathlib import Path
from setuptools import setup
from mypyc.build import mypycify

try:
    import tomllib  # Python 3.11+
except ModuleNotFoundError:
    import tomli as tomllib  # Older Python


with Path("pyproject.toml").open("rb") as f:
    pyproject_data = tomllib.load(f)
    poetry_config = pyproject_data["tool"]["poetry"]


setup(
    name=poetry_config["name"],
    version=poetry_config["version"],
    packages=["evmspec"],
    package_data={"evmspec": ["py.typed"]},
    include_package_data=True,
    ext_modules=mypycify(
        [
            "evmspec/_utils.py",
            "--pretty",
            "--install-types",
            "--non-interactive",
            "--disable-error-code=unused-ignore",
        ]
    ),
    zip_safe=False,
)
