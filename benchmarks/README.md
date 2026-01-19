# Benchmarks for evmspec

This directory contains CodSpeed-friendly benchmarks for key hot paths and micro-utilities in `evmspec`:

- `test_address_benchmarks.py`: `Address` constructors, checksum, and decode hooks.
- `test_hexbytes_benchmarks.py`: `HexBytes32` construction and helpers.
- `test_numeric_benchmarks.py`: `uint` parsing/formatting, `Wei.scaled`, and timestamps.
- `test_uints_benchmarks.py`: fixed-width uint constructors.
- `test_cache_benchmarks.py`: `ttl_cache` wrapper creation and cached call paths.
- `test_enum_benchmarks.py`: enum metaclass conversions.
- `test_ids_benchmarks.py`: `IntId` arithmetic guard methods.
- `test_decoding_benchmarks.py`: Transaction, receipt, and log decoding.
- `test_block_benchmarks.py`: `TinyBlock.transactions` decoding.
- `test_decode_hook_benchmarks.py`: global decode hooks and internal helpers.

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
