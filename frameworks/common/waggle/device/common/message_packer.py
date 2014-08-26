#!/usr/bin/env python
#
# This is a module that allows for the ease of packing data into a message
#   Ideally, this will be used by sensors to send data through the NCR
#
# In this class (in this order):
#   __init__
#   static:
#       check_item
#       check_type
#       check_length
#   public:
#       add_item
#       del_item
#       generate
#   operators:
#       __getitem__
#       __str__
#   private:
#       _swap
#
#*token[0:1]

from waggle.device.node_controller.data_client import NodeDataClient

class MessagePacker:
    def __init__(self):
        """ Basic initialization for the message.
        """
        self.instance_id = ""
        self.sensor_id = ""
        self.read_time = "-1"
        self._data_identifiers = []
        self._data_types = []
        self._data_values = []
        self._data_units = []
        self._data_notes = []
        self._data_ref_id = []
        self._last_ref_id = -1
        self._id_indice_dict = {}


    @staticmethod
    def check_item(identifier, data_type, value, unit, note=""):
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
        if MessagePacker.check_type(identifier) \
                        and MessagePacker.check_type(data_type) \
                        and MessagePacker.check_type(value, data_type) \
                        and MessagePacker.check_type(unit) \
                        and MessagePacker.check_type(note) \
                        and MessagePacker.check_length(identifier) \
                        and MessagePacker.check_length(data_type) \
                        and MessagePacker.check_length(str(value)) \
                        and MessagePacker.check_length(unit) \
                        and MessagePacker.check_length(note):
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


    def add_item(self, identifier, data_type, value, unit, note = ""):
        """ This function simply appends a "data point" to the existing
                message. Each time add_item is called a unique reference id is
                returned that is associated with the data point. A reference id
                of "-1" is returned on failure.
            Paramaters
            ----------
            identifier (str): the name of the data point
            data_type (str): the first letter of the type of the value in
                lowercase
            value (?): the actual value of the data point
                will be cast to string
            unit (str): the unit associated with the value
            note (str): any noteworthy information about the data point
        """
        if MessagePacker.check_item(identifier, data_type, value, unit, note):
            self._last_ref_id = self._last_ref_id + 1
            self._data_ref_id.append(self._last_ref_id)
        
            self._data_identifiers.append(identifier)
            self._data_types.append(data_type)
            self._data_values.append(str(value))
            self._data_units.append(unit)
            self._data_notes.append(note)
        
            self._id_indice_dict[self._last_ref_id] = len(self._data_types) - 1
            return self._last_ref_id
        else:
            return -1


    def del_item(self, ref_id):
        """ This function deletes an item using it's reference id. A reference
                (hopefully unique) reference id is generated each time an item
                is added to the message. A copy of the deleted message is 
                returned.
            Parameters
            ----------
            ref_id (int): the reference id of the element that is to be deleted
        """

        # collect indices to swap
        index = self._id_indice_dict[ref_id]
        swap_index = len(self._data_ref_id) -1

        # swap the bad item to the end of the array to prevent holes
        self._swap(index, swap_index)

        # prepare the item that was deleted to be returned
        deleted_item = [self._data_identifiers[swap_index],
                              self._data_types[swap_index],
                             self._data_values[swap_index],
                              self._data_units[swap_index],
                              self._data_notes[swap_index]]
        
        # delete the data within the class
        del(self._data_identifiers[swap_index])
        del(self._data_types[swap_index])
        del(self._data_values[swap_index])
        del(self._data_units[swap_index])
        del(self._data_notes[swap_index])
        del(self._data_ref_id[swap_index])

        return deleted_item


    def generate(self):
        """ This function takes all of the data that was inserted into the
                class and turns it into a message that can be sent through the
                NodeDataClient.
        """
        return NodeDataClient.msg_gen(str(self[0]), str(self[1]), str(self[2]),
                                   self[3], self[4], self[5], self[6], self[7])


    def __getitem__(self, index):
        """ This function is primarily used to simplify the sending of
                arguments to the generate method, it can also be used to
                investigate individual elements of data of the message.
            Parameters
            ----------
            index (int): an index used to determine the value returned
                0: instance id
                1: sensor id
                2: read time
                3: array of data indentifiers 
                4: array of data types
                5: array of data values
                6: array of data units
                7: array of data notes
        """
        if index < 0 or index > 7:
            print "Invalid index of ", index
            return ""
        if index == 0:
            return self.instance_id
        elif index == 1:
            return self.sensor_id
        elif index == 2:
            return self.read_time
        elif index == 3:
            return self._data_identifiers
        elif index == 4:
            return self._data_types
        elif index == 5:
            return self._data_values
        elif index == 6:
            return self._data_units
        elif index == 7:
            return self._data_notes


    def __str__(self):
        """ Returns the data as a string in the form of a table. Intance id,
                sensor id, and read time appear above the table. The table
                should match the size of the data within.
        """
        rv = ""
 
        #header information
        rv = rv + "Instance ID: " + str(self.instance_id) + "\n" \
                + "Sensor ID: " + str(self.sensor_id) + "\n" \
                + "Time: " + str(self.read_time) + "\n"

        num_values = len(self._data_values)

        if (num_values == 0):
            rv = rv + "NO DATA"
        else:
            #obtaining width for columns
            max_identifier_length = len("Field Name")
            max_type_length = len("Type")
            max_value_length = len("Value")
            max_unit_length = len("Unit")
            max_note_length = len("Notes")
            i = 0;
            while i < num_values:
                if len(self._data_identifiers[i]) > max_identifier_length:
                    max_identifier_length = len(self._data_identifiers[i])
                if len(self._data_types[i]) > max_type_length:
                    max_type_length = len(self._data_types[i])
                if len(self._data_values[i]) > max_value_length:
                    max_value_length = len(self._data_values[i])
                if len(self._data_units[i]) > max_unit_length:
                    max_unit_length = len(self._data_units[i])
                if len(self._data_notes[i]) > max_note_length:
                    max_note_length = len(self._data_notes[i])
                i = i + 1

            #table header information
            rv = rv + "Field Name".ljust(max_identifier_length) \
                    + " | " + "Type".rjust(max_type_length) \
                    + " | " + "Value".rjust(max_value_length) \
                    + " | " + "Unit".rjust(max_unit_length) \
                    + " | " + "Notes".ljust(max_note_length) \
                    + "\n"

            i = 0
            while i < num_values:
                #print lines in the table
                rv = rv + "-" * max_identifier_length + "-+-" \
                        + "-" * max_type_length + "-+-" \
                        + "-" * max_value_length + "-+-" \
                        + "-" * max_unit_length + "-+-" \
                        + "-" * max_note_length + "\n"
                #print data of the table
                rv = rv \
                   + self._data_identifiers[i].ljust(max_identifier_length) \
                   + " | " + self._data_types[i].rjust(max_type_length) \
                   + " | " + self._data_values[i].rjust(max_value_length)\
                   + " | " + self._data_units[i].rjust(max_unit_length) \
                   + " | " + self._data_notes[i].ljust(max_note_length) \
                   + "\n"
                i = i + 1
        return rv


    def _swap(self, a, b):
        """ This function allows for the swapping of two elements within a
                message. Swaps the arrays as well as corrects the indices of
                the reference id dictionary.
            Parameters
            ----------
            a (int): the indice of an element
            b (int): the indice of another element
        """
        # Don't need to swap
        if (a == b):
            return

        # Fix reference ID dictionary
        self._id_indice_dict[self._data_ref_id[b]] = a
        self._id_indice_dict[self._data_ref_id[a]] = b

        # Swap all 6 arrays
        self._data_identifiers[b], self._data_identifiers[a] = \
              self._data_identifiers[a], self._data_identifiers[b]
        self._data_types[b], self._data_types[a] = \
                          self._data_types[a], self._data_types[b]
        self._data_values[b], self._data_values[a] = \
                        self._data_values[a], self._data_values[b]
        self._data_units[b], self._data_units[a] = \
                          self._data_units[a], self._data_units[b]
        self._data_notes[b], self._data_notes[a] = \
                          self._data_notes[a], self._data_notes[b]
        self._data_ref_id[b], self._data_ref_id[a] = \
                        self._data_ref_id[a], self._data_ref_id[b]

        return


