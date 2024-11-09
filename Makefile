
.PHONY: docs

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	poetry run sphinx-apidoc -o ./docs/source ./evmspec

mypy:
	poetry run mypy ./evmspec --pretty --ignore-missing-imports --show-error-codes --show-error-context --no-warn-no-return