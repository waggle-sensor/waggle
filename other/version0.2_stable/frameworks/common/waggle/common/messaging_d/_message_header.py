#!/usr/bin/env python
from _util import WaggleDefaults
from _util import API_VERSION
from _util import NONE
from _util import get_api_version
from _util import get_instance_id
from _util import get_current_time
from _util import DELIMITERS
from _util import HEADER_ROOT_DELIM_INDEX
from _util import _encode
from _util import _decode

class MessageHeader(WaggleDefaults):
    def __init__(self):
        """ Default "constructor", creates placeholder variables. """
        self.protocol_version = str(get_api_version())
        self.message_type = str(-1)
        self.instance_id = str(get_instance_id())
        self.timestamp = str(get_current_time())
        self.sequence_id = str(-1)
        self.reply_to_id = str(-1)

        ## The following two fields are reserved for future use or debugging
        self.user_field1 = 'UF1'
        self.user_field2 = 'UF2'


    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv =("protocol version = " + str(self.protocol_version) + "\n"
           + "message_type = " + str(self.message_type) + "\n"
           + "instance_id = " + str(self.instance_id) + "\n"
           + "timestamp = " + str(self.timestamp) + "\n"
           + "sequence_id = " + str(self.sequence_id) + "\n"
           + "reply_to_id = " + str(self.reply_to_id) + "\n"
           + "user_field1 = " + str(self.user_field1) + "\n"
           + "user_field2 = " + str(self.user_field2) + "\n")
        return rv


    def __repr__(self):
        """ Return a str representation of the class sufficient to reconstruct 
            the payload.
        """
        return "MessageHeader.decode(\"" + self.encode() + "\")"


    def _convert_to_list(self):
        """ Return the contents of the message in the form of a list for use
                in encode.
        """
        return [self.protocol_version, self.message_type, self.instance_id,
                        self.timestamp, self.sequence_id, self.reply_to_id, 
                                        self.user_field1, self.user_field2]
    

    def _restore_from_list(self, restore_list):
        """ Restore the contents of the header from a list that is of the same
                format as the value returned from _convert_to_list.
            Parameters
            ----------
            restore_list (list): the list to restore from
        """
        self.protocol_version = restore_list[0]
        self.message_type = restore_list[1]
        self.instance_id = restore_list[2]
        self.timestamp = restore_list[3]
        self.sequence_id = restore_list[4]
        self.reply_to_id = restore_list[5]
        self.user_field1 = restore_list[6]
        self.user_field2 = restore_list[7]
        return


    def encode(self):
        """ Created a properly formatted header as a string. """
        return _encode(self._convert_to_list(), HEADER_ROOT_DELIM_INDEX)


    @classmethod
    def decode(cls, to_decode):
        """ Create a header from a encoded message.
            Parameters
            ----------
            to_decode(str): the message to decode
        """
        list_from_decode = _decode(to_decode, HEADER_ROOT_DELIM_INDEX)
        rv = MessageHeader()
        rv._restore_from_list(list_from_decode)
        return rv


###############################################################################
# Unit testing

if __name__ == "__main__":
    from _util import test_eq
    a = MessageHeader()

    b = MessageHeader.decode(a.encode())

    print "\nTest Print:"
    print a

    print "\nTesting:"
    test_eq(a, b, "Encode/Decode")
    test_eq(eval(repr(a)), a, "Eval/Repr")
