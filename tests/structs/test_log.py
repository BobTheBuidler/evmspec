import pytest

pytest.importorskip("dictstruct")

from evmspec.data import Address, BlockNumber, TransactionHash
from evmspec.data._ids import LogIndex, TransactionIndex
from evmspec.structs.log import Data, Log, TinyLog, Topic

ADDRESS = "0x" + "11" * 20
TOPIC = "0x" + "22" * 32


def test_data_as_uint_and_address() -> None:
    data = Data("0x0a")
    assert data.as_uint == 10

    address_data = Data("0x" + "00" * 12 + "11" * 20)
    assert str(address_data.as_address) == Address(ADDRESS)


def test_data_as_address_invalid() -> None:
    bad = Data("0x" + "11" * 32)
    with pytest.raises(ValueError):
        _ = bad.as_address


def test_data_as_uints() -> None:
    data = Data("0x01")
    assert data.as_uint8 == 1
    assert data.as_uint64 == 1
    assert data.as_uint128 == 1
    assert data.as_uint256 == 1


def test_topic_dynamic_uint_property() -> None:
    topic = Topic("0x" + "00" * 31 + "0a")
    assert topic.as_uint40 == 10


def test_tinylog_topic_accessors() -> None:
    log = TinyLog(topics=(Topic(TOPIC),))
    assert log.topic0 == Topic(TOPIC)

    with pytest.raises(AttributeError) as exc_info:
        _ = log.topic1
    assert "topic1" in str(exc_info.value)

    with pytest.raises(AttributeError) as exc_info:
        _ = log.topic2
    assert "topic2" in str(exc_info.value)

    with pytest.raises(AttributeError) as exc_info:
        _ = log.topic3
    assert "topic3" in str(exc_info.value)


def test_log_block_property() -> None:
    log = Log(
        topics=(Topic(TOPIC),),
        address=Address(ADDRESS),
        data=Data("0x"),
        removed=False,
        blockNumber=BlockNumber(1),
        transactionHash=TransactionHash(TOPIC),
        logIndex=LogIndex(0),
        transactionIndex=TransactionIndex(0),
    )
    assert log.block == BlockNumber(1)
