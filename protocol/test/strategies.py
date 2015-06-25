from hypothesis import strategy
from hypothesis.specifiers import integers_in_range, integers_from
import hypothesis.strategytests as st
from collections import namedtuple

from src.serialize_header import SerializeHeader
from src.session import Session
from src.message_type import MessageType
from src.message import Message
from src.spec import spec
import src.util as util

# Helper function
def header_int(field):
    return integers_in_range(0, 2**spec.header[field] - 1)

""" MessageType """
@strategy.extend_static(MessageType)
def message_type_strategy(_, settings):
    return strategy(MessageType(
        major = header_int("message_major_type"),
        minor = header_int("message_minor_type")   
    ), settings)

"""
Session
    Note: This uses the data in the spec for the **sender's session**,
    but is meant to generate valid example sessions for both senders
    and recipients.
"""
@strategy.extend_static(Session)
def session_strategy(_, settings):
    return strategy(Session(
        session_number = header_int("sender_session_number"),
        sequence_number = header_int("sender_sequence_number"),
        id = header_int("sender_id")
    ), settings)

"""
BoundedInt
    Used to test util.pack.
"""
class BoundedInt(object):
    def __init__(self, n, upper_bound):
        self.n = n
        self.upper_bound = upper_bound

@strategy.extend_static(BoundedInt)
def bounded_int_strategy(_, settings):
    return strategy(integers_from(0), settings).flatmap(
        lambda ub: strategy(integers_in_range(0, ub), settings).map(
            lambda n: BoundedInt(n, ub)
        ) 
    )

""" SerializeHeader """
simple_header_fields = [
    "sender_session_number", 
    "sender_sequence_number",
    "sender_id",
    "recipient_id",
    "recipient_session_number",
    "recipient_session_sequence_number",
    "message_minor_type",
    "message_major_type",
    "message_timestamp"
]

message_data = { "payload": str }

for field in simple_header_fields:
    message_data[field] = header_int(field)

""" 
Message 
    Strategies for testing parsing and serialization of messages.
"""
@strategy.extend_static(Message)
def message_strategy(specifier, settings):
    return strategy((str, MessageType, int, Session, Session), settings).map(
        lambda m: Message(*m)
    )

"""
Tests for strategies
"""
#bounded_int_strategy_test = st.strategy_test_suite(BoundedInt)
#message_type_strategy_test = st.strategy_test_suite(MessageType) 
#session_strategy_test = st.strategy_test_suite(Session)
#message_strategy_test = st.strategy_test_suite(Message)
