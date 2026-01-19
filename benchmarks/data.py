import json

ADDRESS_HEX = "52908400098527886E0F7030069857D2E4169EE7"
ADDRESS_CHECKSUM = "0x" + ADDRESS_HEX
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
HASH_PADDED = "0x" + "00" * 31 + "01"
BLOB_HASH_1 = "0x" + "55" * 32
BLOB_HASH_2 = "0x" + "66" * 32

TOPIC_0 = "0x" + "aa" * 32
TOPIC_1 = "0x" + "bb" * 32
DATA_32 = "0x" + "00" * 32
DATA_UINT_32 = "0x" + "00" * 31 + "2a"
DATA_ADDRESS_32 = "0x" + "00" * 12 + ADDRESS_HEX

HEXBYTES32_CASES = [
    HASH_1,
    bytes.fromhex("11" * 32),
]
HEXBYTES32_CASE_IDS = [
    "hexstr",
    "bytes",
]

UINT_HEX_CASES = [
    "0x0",
    "0x1",
    "0xff",
    "0x7fffffffffffffff",
]
UINT_HEX_CASE_IDS = [
    "0",
    "1",
    "ff",
    "int64-max",
]

TX_BASE = {
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

LEGACY_TX = {
    **TX_BASE,
    "type": "0x0",
}

TX_2930 = {
    **TX_BASE,
    "type": "0x1",
    "yParity": "0x1",
    "accessList": [],
}

TX_1559 = {
    **TX_BASE,
    "type": "0x2",
    "maxFeePerGas": "0x77359400",
    "maxPriorityFeePerGas": "0x3b9aca00",
    "yParity": "0x1",
    "accessList": [],
}

TX_4844 = {
    **TX_1559,
    "type": "0x3",
    "maxFeePerBlobGas": "0x1",
    "blobVersionedHashes": [BLOB_HASH_1, BLOB_HASH_2],
}

TX_7702 = {
    **TX_1559,
    "type": "0x4",
    "authorizationList": [],
}

TX_RLP = {
    **TX_BASE,
}

TX_LIST = [
    LEGACY_TX,
    TX_1559,
]

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

FULL_LOG = {
    **LOG,
    "blockHash": HASH_2,
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

FULL_RECEIPT = {
    **RECEIPT,
    "blockHash": HASH_2,
    "logsBloom": "0x" + "00" * 256,
}

FEE_STATS = {
    "paid": {
        "l1Calldata": "0x1",
        "l2Storage": "0x2",
        "l1Transaction": "0x3",
        "l2Computation": "0x4",
    },
    "unitsUsed": {
        "l1Calldata": "0x1",
        "l2Storage": "0x2",
        "l1Transaction": "0x3",
        "l2Computation": "0x4",
    },
    "prices": {
        "l1Calldata": "0x1",
        "l2Storage": "0x2",
        "l1Transaction": "0x3",
        "l2Computation": "0x4",
    },
}

RECEIPT_WITH_FEE_STATS = {
    **RECEIPT,
    "feeStats": FEE_STATS,
}

BLOCK_COMMON = {
    "timestamp": "0x65f2",
    "number": "0x1",
    "hash": HASH_1,
    "logsBloom": "0x" + "00" * 256,
    "receiptsRoot": HASH_2,
    "extraData": "0x",
    "nonce": "0x0000000000000000",
    "miner": ADDRESS_CHECKSUM,
    "gasLimit": "0x5208",
    "gasUsed": "0x5208",
    "uncles": [HASH_3],
    "sha3Uncles": HASH_4,
    "size": "0x200",
    "transactionsRoot": HASH_2,
    "stateRoot": HASH_3,
    "mixHash": HASH_4,
    "parentHash": HASH_2,
}

BLOCK_WITH_HASHES = {
    **BLOCK_COMMON,
    "transactions": [HASH_1, HASH_2],
}

BLOCK_WITH_TXS = {
    **BLOCK_COMMON,
    "transactions": TX_LIST,
}

MINED_BLOCK = {
    **BLOCK_WITH_HASHES,
    "difficulty": "0x1",
    "totalDifficulty": "0x2",
}

BASE_BLOCK = {
    **MINED_BLOCK,
    "baseFeePerGas": "0x1",
}

WITHDRAWALS = [
    {
        "index": "0x1",
        "amount": "0x2",
        "address": ADDRESS_CHECKSUM,
        "validatorIndex": "0x3",
    },
    {
        "index": "0x2",
        "amount": "0x3",
        "address": ADDRESS_ZERO,
        "validatorIndex": "0x4",
    },
]

SHANGHAI_BLOCK = {
    **BLOCK_WITH_HASHES,
    "withdrawals": WITHDRAWALS,
}

ERIGON_HEADER = {
    "timestamp": "0x65f2",
    "parentHash": HASH_1,
    "uncleHash": HASH_2,
    "coinbase": ADDRESS_CHECKSUM,
    "root": HASH_3,
    "difficulty": "0x1",
}

TRACE_BASE = {
    "blockNumber": "0x10",
    "blockHash": HASH_1,
    "transactionHash": HASH_2,
    "transactionPosition": 0,
    "traceAddress": [0, 1],
    "subtraces": 0,
}

TRACE_CALL = {
    **TRACE_BASE,
    "type": "call",
    "action": {
        "from": ADDRESS_CHECKSUM,
        "value": "0x0",
        "gas": "0x5208",
        "callType": "call",
        "to": ADDRESS_LOWER,
        "input": "0x",
    },
    "result": {
        "gasUsed": "0x5208",
        "output": "0x",
    },
}

TRACE_CREATE = {
    **TRACE_BASE,
    "type": "create",
    "action": {
        "from": ADDRESS_CHECKSUM,
        "value": "0x0",
        "gas": "0x5208",
        "init": "0x00",
        "creationMethod": "create",
    },
    "result": {
        "gasUsed": "0x5208",
        "address": ADDRESS_CHECKSUM,
        "code": "0x00",
    },
}

TRACE_REWARD = {
    **TRACE_BASE,
    "type": "reward",
    "action": {
        "from": ADDRESS_CHECKSUM,
        "value": "0x0",
        "gas": "0x5208",
        "author": ADDRESS_CHECKSUM,
        "rewardType": "block",
    },
}

TRACE_SUICIDE = {
    **TRACE_BASE,
    "type": "suicide",
    "action": {
        "from": ADDRESS_CHECKSUM,
        "value": "0x0",
        "gas": "0x5208",
    },
    "result": None,
}


def _dump(obj: object) -> bytes:
    return json.dumps(obj, separators=(",", ":")).encode()


RAW_LEGACY_TX = _dump(LEGACY_TX)
RAW_TX_2930 = _dump(TX_2930)
RAW_TX_1559 = _dump(TX_1559)
RAW_EIP1559_TX = RAW_TX_1559
RAW_TX_4844 = _dump(TX_4844)
RAW_TX_7702 = _dump(TX_7702)
RAW_TX_RLP = _dump(TX_RLP)
RAW_TX_LIST = _dump(TX_LIST)
RAW_BLOCK_WITH_TXS = _dump(BLOCK_WITH_TXS)
RAW_BLOCK_WITH_HASHES = _dump(BLOCK_WITH_HASHES)
RAW_MINED_BLOCK = _dump(MINED_BLOCK)
RAW_BASE_BLOCK = _dump(BASE_BLOCK)
RAW_SHANGHAI_BLOCK = _dump(SHANGHAI_BLOCK)
RAW_LOG = _dump(LOG)
RAW_LOG_LIST = _dump([LOG])
RAW_FULL_LOG = _dump(FULL_LOG)
RAW_RECEIPT = _dump(RECEIPT)
RAW_FULL_RECEIPT = _dump(FULL_RECEIPT)
RAW_RECEIPT_WITH_FEE_STATS = _dump(RECEIPT_WITH_FEE_STATS)
RAW_ERIGON_HEADER = _dump(ERIGON_HEADER)
RAW_TRACE_CALL = _dump(TRACE_CALL)
RAW_TRACE_CREATE = _dump(TRACE_CREATE)
RAW_TRACE_REWARD = _dump(TRACE_REWARD)
RAW_TRACE_SUICIDE = _dump(TRACE_SUICIDE)
