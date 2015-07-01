#!/usr/bin/env python
from _message_payload import MessagePayload
from _util import WaggleDefaults
from _util import get_mac_addr
from _util import _encode
from _util import encode_prim
from _util import decode_prim


class RegistrationPayload(MessagePayload):
    """ Payload class to be used for commands. """
    PAYLOAD_ID = 0


    def __init__(self):
        """ Default "Constructor", creates placeholder variables. """
        self.instance_id = str()
        self.sys_info = dict()


    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv = "This is a regsitration payload"
	rv = rv + self.sys_info#dict_table(self.sys_info) + "\n"
        return rv


    def _convert_to_list(self):
        """ Return the contents of the message in the form of a list for use
                in superclass' encode.
        """
        return [self.instance_id, encode_prim(self.sys_info, 0)]

        
    def _restore_from_list(self, restore_list):
        """ Restore the contents of the payload from a list that is of the same
                format as the value retrned from _convert_to_list.
            Parameters
            ----------
            restore_list (list): the list to restore from
        """
        self.instance_id = restore_list[0]
        self.sys_info = decode_prim(restore_list[1], 0)


    def verify(self):
        """ Perform an integrity check on local variables. Returns True if
                values are valid, and False otherwise.
        """
        raise NotImplementedError


###############################################################################
# Unit testing

if __name__ == "__main__":
    from _util import test_eq
    a = RegistrationPayload()

    #Instance data filling goes here

    a.instance_id = "instnace_id"
    a.sys_info = dict({1: 2})

    b = RegistrationPayload.decode(a.encode())

    print "\nTest Print:"
    print a

    print "\nTesting:"
    test_eq(a, b, "Encode/Decode")
    print "repr", repr(a)
    test_eq(eval(repr(a)), a, "Eval/Repr")
