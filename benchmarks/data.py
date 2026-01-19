import json

ADDRESS_CHECKSUM = "0x52908400098527886E0F7030069857D2E4169EE7"
ADDRESS_LOWER = "0xde709f2102306220921060314715629080e2fb77"
ADDRESS_UPPER = "0xDE709F2102306220921060314715629080E2FB77"
ADDRESS_ZERO = "0x0000000000000000000000000000000000000000"
ADDRESS_PRECOMPILE_1 = "0x0000000000000000000000000000000000000001"
ADDRESS_PRECOMPILE_9 = "0x0000000000000000000000000000000000000009"
ADDRESS_DEAD = "0x000000000000000000000000000000000000dead"
ADDRESS_SAMPLE = "0x1234567890abcdef1234567890abcdef12345678"

ADDRESS_CASES = [
    ADDRESS_CHECKSUM,
    ADDRESS_LOWER,
    ADDRESS_UPPER,
    ADDRESS_ZERO,
    ADDRESS_PRECOMPILE_1,
    ADDRESS_PRECOMPILE_9,
    ADDRESS_DEAD,
    ADDRESS_SAMPLE,
]
ADDRESS_CASE_IDS = [
    "checksummed",
    "lower",
    "upper",
    "zero",
    "precompile-1",
    "precompile-9",
    "dead",
    "sample",
]

HASH_1 = "0x" + "11" * 32
HASH_2 = "0x" + "22" * 32
HASH_3 = "0x" + "33" * 32
HASH_4 = "0x" + "44" * 32

TOPIC_0 = "0x" + "aa" * 32
TOPIC_1 = "0x" + "bb" * 32
DATA_32 = "0x" + "00" * 32
HASH_PADDED = "0x" + "00" * 31 + "01"
ADDRESS_TOPIC_CHECKSUM = "0x" + "00" * 12 + ADDRESS_CHECKSUM[2:]

HEXBYTES32_CASES = [
    HASH_1,
    bytes.fromhex(HASH_1[2:]),
    HASH_1[2:],
    HASH_PADDED,
    ADDRESS_TOPIC_CHECKSUM,
    DATA_32,
]
HEXBYTES32_CASE_IDS = [
    "hexstr",
    "bytes",
    "hexstr-no-prefix",
    "padded-small",
    "address-topic",
    "all-zero",
]

UINT_HEX_CASES = [
    "0x0",
    "0x1",
    "0x10",
    "0x65f2",
    "0x5208",
    "0x3b9aca00",
    "0x1c9c380",
    "0xffffffffffffffff",
    "0x10000000000000000",
    "0x0000000000000001",
    "0x0000000000000000000000000000000000000000000000000000000000000000",
    "0x0000000000000000000000000000000000000000000000000000000000000001",
    "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
]
UINT_HEX_CASE_IDS = [
    "0",
    "1",
    "16",
    "block",
    "gas-21000",
    "gwei",
    "gas-limit",
    "uint64-max",
    "uint64-plus-one",
    "padded-1",
    "padded-32-zero",
    "padded-32-one",
    "uint256-max",
]

LEGACY_TX = {
    "type": "0x0",
    "hash": HASH_1,
    "nonce": "0x1",
    "blockHash": HASH_2,
    "blockNumber": "0x10",
    "transactionIndex": "0x0",
    "from": ADDRESS_CHECKSUM,
    "to": ADDRESS_LOWER,
    "value": "0x0",
    "gas": "0x5208",
    "gasPrice": "0x3b9aca00",
    "input": "0x",
    "v": "0x1b",
    "r": HASH_3,
    "s": HASH_4,
}

EIP1559_TX = {
    "type": "0x2",
    "hash": HASH_2,
    "nonce": "0x2",
    "blockHash": HASH_3,
    "blockNumber": "0x10",
    "transactionIndex": "0x1",
    "from": ADDRESS_LOWER,
    "to": ADDRESS_CHECKSUM,
    "value": "0x1",
    "gas": "0x5208",
    "gasPrice": "0x3b9aca00",
    "maxFeePerGas": "0x77359400",
    "maxPriorityFeePerGas": "0x3b9aca00",
    "input": "0x",
    "v": "0x0",
    "r": HASH_1,
    "s": HASH_2,
    "yParity": "0x1",
    "accessList": [],
}

TX_LIST = [
    LEGACY_TX,
    EIP1559_TX,
]

BLOCK_WITH_TXS = {
    "timestamp": "0x65f2",
    "transactions": TX_LIST,
}

BLOCK_WITH_HASHES = {
    "timestamp": "0x65f2",
    "transactions": [HASH_1, HASH_2],
}

LOG = {
    "address": ADDRESS_CHECKSUM,
    "topics": [TOPIC_0, TOPIC_1],
    "data": DATA_32,
    "removed": False,
    "blockNumber": "0x10",
    "transactionHash": HASH_1,
    "logIndex": "0x1",
    "transactionIndex": "0x0",
}

RECEIPT = {
    "transactionHash": HASH_1,
    "blockNumber": "0x10",
    "contractAddress": None,
    "transactionIndex": "0x0",
    "status": "0x1",
    "gasUsed": "0x5208",
    "cumulativeGasUsed": "0x5208",
    "logs": [LOG],
    "effectiveGasPrice": "0x3b9aca00",
    "type": "0x2",
}


def _dump(obj: object) -> bytes:
    return json.dumps(obj, separators=(",", ":")).encode()


RAW_LEGACY_TX = _dump(LEGACY_TX)
RAW_EIP1559_TX = _dump(EIP1559_TX)
RAW_TX_LIST = _dump(TX_LIST)
RAW_BLOCK_WITH_TXS = _dump(BLOCK_WITH_TXS)
RAW_BLOCK_WITH_HASHES = _dump(BLOCK_WITH_HASHES)
RAW_LOG = _dump(LOG)
RAW_RECEIPT = _dump(RECEIPT)
