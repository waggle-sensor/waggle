#!/usr/bin/env python2.7
from _message_payload import MessagePayload
from _util import test_eq

class ReplyPayload(MessagePayload):
    """ Payload class to be used for reply messages. """
    PAYLOAD_ID = 3 # ID of this payload type


    def __init__(self):
        """ Default "consutrctor", creates placeholder variables. """
        self.return_value = int()
        self.output = str()


    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv =("return_value = " + str(self.return_value) + "\n"
           + "output = " + self.output)
        return rv


    def _convert_to_list(self):
        """ Return the contents of the message in the form of a list for use 
                in superclass' encode.
        """
        return [str(self.return_value), self.output]


    def _restore_from_list(self, restore_list):
        """ Restore the contents of the payload from a list that is of the same
                format as the value returned from _convert_to_list.
            Parameters
            ----------
            restore_list (list): the list to restore from
        """
        self.return_value = int(restore_list[0])
        self.output = str(restore_list[1])
        return


    def verify(self):
        """ Perform an integrity check on local variables. Returns True if
                values are valid, and False otherwise.
        """
        raise NotImplementedError


###############################################################################
# Unit testing

if __name__ == "__main__":
    a = ReplyPayload()

    a.return_value = 10
    a.output = "output"

    b = ReplyPayload().decode(a.encode())

    print "\nTest Print:"
    print a

    print "\nTesting:"
    test_eq(a, b, "Encode/Decode")
    test_eq(eval(repr(a)), a, "Eval/Repr")
