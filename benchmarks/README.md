# Benchmarks for evmspec

This directory contains CodSpeed-friendly benchmarks for key hot paths in `evmspec`:

- `test_address_benchmarks.py`: Address checksum and construction.
- `test_block_benchmarks.py`: `TinyBlock.transactions` decoding.
- `test_decode_hook_benchmarks.py`: global decode hooks and internal helpers.
- `test_decoding_benchmarks.py`: Transaction, receipt, and log decoding.
- `test_hexbytes_benchmarks.py`: `HexBytes32` construction.
- `test_numeric_benchmarks.py`: `uint` hex parsing.

## Running Benchmarks

Install the benchmark dependencies:

```
pip install -r requirements-codspeed.txt
```

Run the suite with CodSpeed:

```
pytest benchmarks/ --codspeed
```

## Contributing

- Add benchmarks for new public APIs or hot decode paths.
- Keep inputs representative of real RPC payloads.
- Each benchmark should stand alone (no paired reference/optimized variant).
