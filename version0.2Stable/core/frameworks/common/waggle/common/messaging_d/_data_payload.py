#!/usr/bin/env python2.7
from _message_payload import MessagePayload
from _util import table
from _util import test_eq

class DataPayload(MessagePayload):
    """ Payload class to be used for data. """
    PAYLOAD_ID = 1 # ID of this payload type


    def __init__(self):
        """ Default "constructor", creates placeholder variables. """
        self.inst_id = str()
        self.sens_id = str()
        self.read_tm = float()
        self.data_name = list()
        self.data_type = list()
        self.data_valu = list()
        self.data_unit = list()
        self.data_note = list()


    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv =("instance id = " + self.inst_id + "\n"
           + "sensor id = " + self.sens_id + "\n"
           + "read time = " + str(self.read_tm) + "\n"
           + table([(self.data_name, "Identifier", '<'),
                    (self.data_type, "Type", '>'),
                    (self.data_valu, "Value", '>'), 
                    (self.data_unit, "Units", '>'),
                    (self.data_note, "Notes", '<')]))
        return rv


    def _convert_to_list(self):
        """ Return the contents of the message in the form of a list for use
                in superclass' encode.
        """
        return [self.inst_id, self.sens_id, str(self.read_tm), self.data_name,
                self.data_type, [str(i) for i in self.data_valu], 
                self.data_unit, self.data_note]
   
 
    def _restore_from_list(self, restore_list):
        """ Restore the contents of the payload from a list that is of the same
                format as the value returned from _convert_to_list.
            Parameters
            ----------
            restore_list (list): the list to restore from
        """
        self.inst_id = restore_list[0]
        self.sens_id = restore_list[1]
        self.read_tm = float(restore_list[2])

        if restore_list[3] == '':
            self.data_name = []
        elif not type(restore_list[3]) is list:
            self.data_name = [restore_list[3]]
        else:
            self.data_name = restore_list[3]

        if restore_list[4] == '':
            self.data_type = []
        elif not type(restore_list[4]) is list:
            self.data_type = [restore_list[4]]
        else:
            self.data_type = restore_list[4]

        if restore_list[5] == '':
            self.data_valu = []
        elif not type(restore_list[5]) is list:
            self.data_valu = [restore_list[5]]
        else:
            self.data_valu = restore_list[5]

        if restore_list[6] == '':
            self.data_unit = []
        elif not type(restore_list[6]) is list:
            self.data_unit = [restore_list[6]]
        else:
            self.data_unit = restore_list[6]

        if restore_list[7] == '':
            if len(restore_list[3]) == 0:
                self.data_note = []
            else:
                self.data_note = ['']
        elif not type(restore_list[7]) is list:
            self.data_note = [restore_list[7]]
        else:
            self.data_note = restore_list[7]


    def verify(self):
        """ Perform an integrity check on local variables. Returns True if
                values are valid, and False otherwise.
        """
        raise NotImplementedError


    def add_item(self, data_name, data_type, data_valu, data_unit, data_note):
        """ This function simply appends a "data point" to the existing
                message. True is returned on success, and False otherwise. 
            Paramaters
            ----------
            data_name (str): the name of the data point
            data_type (str): one letter abbreviation for type of value i/s/f
            data_valu (int/str/float): the actual value of the data point
            data_unit (str): the unit associated with the value
            data_note (str): any noteworthy information about the data point
        """
        if self.__class__.check_item(data_name, data_type, data_valu,
                                                data_unit, data_note):
            self.data_name.append(data_name)
            self.data_type.append(data_type)
            self.data_valu.append(data_valu)
            self.data_unit.append(data_unit)
            self.data_note.append(data_note)
            return True
        else:
            return False


    @classmethod
    def check_item(cls, identifier, data_type, value, unit, note=""):
        """ Allows checking of whether an item is valid for use, this function
                checks both length and type requirements. Returns True if valid
            Parameters
            ----------
            identifier (str): the name of the data point
            data_type (str): the first letter of the type of the value in
                lowercase
            value (?): the actual value of the data point
            unit (str): the unit associated with the value
            note (str): any noteworthy information about the data point
        """
        if all([cls.check_type(identifier),       cls.check_length(identifier),
                cls.check_type(data_type),        cls.check_length(data_type),
                cls.check_type(value, data_type), cls.check_length(str(value)),
                cls.check_type(unit),             cls.check_length(unit),
                cls.check_type(note),             cls.check_length(note)]):
            return True
        return False


    @staticmethod
    def check_type(value, data_type = 's'):
        """ A simple routine that performs type checking. Returns True if valid
                and False otherwise.
            Parameters
            ----------
            value (?): a value to perform type checking on
            data_type (str): the first letter of the type of the value in
                lowercase
        """
        if data_type == 's':
            data_type = str
        elif data_type == 'f':
            data_type = float
        elif data_type == 'i':
            data_type = int
        else:
            return False

        if type(value) is data_type:
            return True
        return False


    @staticmethod
    def check_length(value, max_length = 255):
        """ A simple routine that performs length checking. Returns True if
                valid and False otherwise.
            Parameters
            ----------
            value (str): a value to perform length checking on 
            max_length (int): the maximum length accepted
        """
        if len(value) > max_length:
            return False
        return True


###############################################################################
# Unit testing

if __name__ == "__main__":
    a = DataPayload()

    a.inst_id = "inst_id"
    a.sens_id = "sens_id"
    a.read_tm = 3.14
    for i in xrange(1):
        a.add_item("name" + str(i), "s", "valu" + str(i), 
                        "unit" + str(i), "note" + str(i))

    b = DataPayload.decode(a.encode())

    print "\nTest Print:"
    print a
    print b

    print "\nTesting:"
    test_eq(a, b, "Encode/Decode")
    test_eq(eval(repr(a)), a, "Eval/Repr")
