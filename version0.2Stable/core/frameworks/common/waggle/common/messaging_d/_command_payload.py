#!/usr/bin/env python2.7
from _message_payload import MessagePayload
from _util import test_eq

class CommandPayload(MessagePayload):
    """ Payload class to be used for commands. """
    PAYLOAD_ID = 2 # ID of this payload type


    def __init__(self):
        """ Default "constructor", creates placeholder variables. """
        self.instance_id = str()
        self.command = str()


    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv =("instance_id = " + self.instance_id + "\n"
           + "command = " + self.command)
        return rv


    def _convert_to_list(self):
        """ Return the contents of the message in the form of a list for use
                in superclass' encode.
        """
        return [self.instance_id, self.command]


    def _restore_from_list(self, restore_list):
        """ Restore the contents of the payload from a list that is of the same
                format as the value returned from _convert_to_list.
            Parameters
            ----------
            restore_list (list): the list to restore from
        """
        self.instance_id = restore_list[0]
        self.command = restore_list[1]

    def verify(self):
        """ Perform an integrity check on local variables. Returns True if
                values are valid, and False otherwise.
        """
        raise NotImplementedError


###############################################################################
# Unit testing

if __name__ == "__main__":
    a = CommandPayload()

    a.instance_id = "instance_id"
    a.command = "command"

    b = CommandPayload.decode(a.encode())

    print "\nTest Print:"
    print a

    print "\nTesting:"
    test_eq(a, b, "Encode/Decode")
    test_eq(eval(repr(a)), a, "Eval/Repr")
