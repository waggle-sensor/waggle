from nose.tools import assert_equal
from hypothesis import given

from src.message_type import MessageType
from src.spec import spec
from src.serialize_header import SerializeHeader
from strategies import message_data

def header_size_test():
    assert spec.header_size == 44

# Each field should be serialized to a binary blob 
# no longer than its byte length in the spec.
@given(message_data)
def serialize_field_length_test(data):
    header = SerializeHeader(data)

    for field, byte_length in spec.header.iteritems():
        assert len(header.serialize_field(field)) <= byte_length

