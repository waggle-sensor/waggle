from nose.tools import nottest
from hypothesis import given

from test.strategies import *

from src.message import Message
from src.spec import spec

# Parse inverts serialize.
@given(Message)
def test_parse_inverts_serialize(msg):
    assert Message.parse(msg.serialize()) == msg

# Serialize inverts parse.
@given(Message)
def test_serialize_inverts_parse(msg):
    msg_str = msg.serialize()
    
    assert Message.parse(msg_str).serialize() == msg_str
