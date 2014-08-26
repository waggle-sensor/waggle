#!/usr/bin/env python2.7
#!! HeaderStuffs

from binascii import crc32
from waggle.common.util import get_instance_id
from waggle.common.util import get_current_time
from waggle.common.util import get_mac_addr
from waggle.common.util import table
#from waggle.common.util import Record
#from waggle.common.util import * # this is bad, and temporary

'''
        DELIMITERS[i]:
        [0]: used only for string message type
        [1]: used to separage different msg in a string
        [2]: for data fields in a msg
        [3]: for sub fields in a data field
'''
NUM_DELIMITERS = 20
#DELIMITERS = [unichr(200+i) for i in xrange(NUM_DELIMITERS)]
    # Unicode DELIMITERS, for real use.
DELIMITERS = [' [' + str(i) + '] ' for i in xrange(NUM_DELIMITERS)]
    # DELIMITERS for test only. 

NONE = -1
API_VERSION = 2

ROOT_DELIM_INDEX = 0
PAYLOAD_SEP_DELIM_INDEX = 0#1
HEADER_ROOT_DELIM_INDEX = 1
PAYLOAD_ROOT_DELIM_INDEX = 1#2


def indented(string):
    """ Might be used in pretty printing. """
#    print str(string)
    return ("\t" + str(string).replace('\n','\n\t'))[:-1]

class WaggleDefaults:
    def __eq__(self,other):
        try:
            return all(getattr(self,key)==getattr(other,key)
                       for key in self.__dict__ if not key.startswith('_'))
        except AttributeError:
            return False

def _encode(to_encode, index):
    """ Takes a list containing only strings and lists, inserts delimiters
        and returns the encoding.
    """
    # print "List = ", to_encode
    # int/float/long/complex?
    if type(to_encode) is str:
        return to_encode

    # tuple?
    if type(to_encode) is list:
        return DELIMITERS[index].join(
                    [_encode(piece, index+1) for piece in to_encode])

    raise TypeError("Expected string or list, got " + str(type(to_encode))
                    + "(" + str(to_encode) + ").")
    
def _decode(to_decode, index):
    split = to_decode.split(DELIMITERS[index])
    
    if len(split) == 1:
        return to_decode
    else:
        return [_decode(item, index+1) for item in split]

    
def type_to_int(payload_type):
    if payload_type == RegistrationPayload:
        return 0
    if payload_type == DataPayload:
        return 1
    if payload_type == CommandPayload:
        return 2
    if payload_type == ReplyPayload:
        return 3

def int_to_type(payload_type):
    if payload_type == 0:
        return RegistrationPayload
    if payload_type == 1:
        return DataPayload
    if payload_type == 2:
        return CommandPayload
    if payload_type == 3:
        return ReplyPayload

###############################################################################
#!! MessageHeader

class MessageHeader(WaggleDefaults):
    def __init__(self,
                 protocol_version = API_VERSION,
                 msg_type = NONE,
                 instance_id = get_instance_id(),
                 timestamp = get_current_time(),
                 seq_id = -1,
                 reply_to_id = -1):
        """ Default construction, currently fills payload with sample data. """
        self.protocol_version = str(protocol_version)
        self.msg_type = str(msg_type)
        self.instance_id = str(get_instance_id())
        self.timestamp = str(get_current_time())
        self.seq_id = str(seq_id)
        self.reply_to_id = str(reply_to_id)

        ## The following two fields are reserved for future use or debugging
        self.user_field1 = 'UF1'
        self.user_field2 = 'UF2'

    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv = ""
        rv =("protocol version = " + str(self.protocol_version) + "\n"
           + "message_type = " + str(self.msg_type) + "\n"
           + "instance_id = " + str(self.instance_id) + "\n"
           + "timestamp = " + str(self.timestamp) + "\n"
           + "seq_id = " + str(self.seq_id) + "\n"
           + "reply_to_id = " + str(self.reply_to_id) + "\n"
           + "user_field1 = " + str(self.user_field1) + "\n"
           + "user_field2 = " + str(self.user_field2) + "\n")
        return rv

    def __repr__(self):
        """ Return a str representation of the class sufficient to reconstruct 
            the payload.
        """
        return "MessageHeader.decode(" + self.encode() + ")"

    @staticmethod
    def decode(encoded_msg):
        """ Likely depreciated. """
        rv = MessageHeader()
        fields = encoded_msg.split(DELIMITERS[HEADER_ROOT_DELIM_INDEX])
        assert len(fields) == 8
        rv._restore_from_list(fields)
        return rv
    

    def _restore_from_list(self, fields):
        self.protocol_version = fields[0]
        self.msg_type = fields[1]
        self.instance_id = fields[2]
        self.timestamp = fields[3]
        self.seq_id = fields[4]
        self.reply_to_id = fields[5]
        self.user_field1 = fields[6]
        self.user_field2 = fields[7]
        return self

    def encode(self):
        """ This function concatenates the header information into a string,
            with attributes been separeted by the default header delimiter, 
            and returns the string
        """

        msg = ''
        msg = DELIMITERS[HEADER_ROOT_DELIM_INDEX].join([
                                                str(self.protocol_version),
                                                str(self.msg_type),
                                                str(self.instance_id),
                                                str(self.timestamp),
                                                str(self.seq_id),
                                                str(self.reply_to_id),
                                                str(self.user_field1),
                                                str(self.user_field2)])
        return msg

    @staticmethod
    def from_string(header_str, delimiter =DELIMITERS[HEADER_ROOT_DELIM_INDEX]):
        """ This function is generating a MessageHeader object by decoding the
            provided string 'header_str' using the provided or default 
            delimiter character 
            Parameters
            ----------
            header_str: str
              encoded message header
            delimiter: char
              delimiter character for spliting string
        """

        token = header_str.split(delimiter)
        
        # Assert number of tokens matches number of argumenrts at MessageHeader
        # constructor
        assert(6 == len(token)) 
        new_header = MessageHeader(*token[:])

        return new_header

    def reset_timestamp():
        """ This function reset the timestamp on the calling header """
        self.timestamp = util.get_current_time()


###############################################################################
#!! MessagePayload

class MessagePayload(WaggleDefaults):

    def __init__(self):
        """ Instianiate self and verify that self is valid. """
        if not self.verify():
            raise TypeError


    def __repr__(self):
        """ Return a str representation of the class sufficient to reconstruct 
            the payload.
        """
        return self.__class__.__name__ + ".decode" + \
            "(" + self.encode() + ", " + str(self.payload_type())  + ")"


    def __str__(self):
        """ Print a user friendly version of the payload. """
        raise NotImplementedError


    def encode(self):
        """ Created a properly formatted payload as a string. """
        to_encode = self._convert_to_list()
        return _encode(to_encode, PAYLOAD_ROOT_DELIM_INDEX)


    @staticmethod
    def decode(to_decode, payload_type):
        """ Takes a list, and constructs a MessagePayload subclass from it.
            Note: Currently needs more thought.
        """
#        raise NotImplementedError
        list_from_decode = _decode(to_decode, PAYLOAD_ROOT_DELIM_INDEX)
        rv = MessagePayload.new_payload(payload_type)
        
        rv._restore_from_list(list_from_decode)
#        if rv.verify():
        return rv
#        else:
#            raise TypeError("Message was not valid.")

    @staticmethod
    def new_payload(payload_type):
        if payload_type == 0:
            return RegistrationPayload()
        if payload_type == 1:
            return DataPayload()
        if payload_type == 2:
            return CommandPayload()
        if payload_type == 3:
            return ReplyPayload()

    def verify():
        """ Returns a True when the payload is considered to be valid, false
            otherwise.
        """
        raise NotImplementedError
        # should not be implemented either



###############################################################################
#!! CommandPayload

class CommandPayload(MessagePayload):
    def __init__(self):
        """ Default construction, currently fills payload with sample data. """
        self.instance_id = "inst_id_tmp"
        self.command = "tml -arg1 -arg2"

    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv =("instance_id = " + self.instance_id + "\n"
           + "command = " + self.command + "\n")
        return rv

    def __repr__(self):
        """ Return a str representation of the class sufficient to reconstruct 
            the payload.
        """
        rv = "CommandPayload.decode(" + self.encode() + ")"
        return rv

    def _convert_to_list(self):
        return [self.instance_id, self.command]

    def _restore_from_list(self, restore_list):
        self.instance_id = restore_list[0]
        self.command = restore_list[1]

    @staticmethod
    def decode(to_decode):
        return MessagePayload.decode(to_decode, 2)


###############################################################################
#!! DataPayload

class DataPayload(MessagePayload):
    def __init__(self, inst_id = "", sens_id = "", read_tm = ""):
        self.inst_id = inst_id
        self.sens_id = sens_id
        self.read_tm = read_tm
        self.data_name = []
        self.data_type = []
        self.data_valu = []
        self.data_unit = []
        self.data_note = []


    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv =("instance id = " + self.inst_id + "\n"
           + "sensor id = " + self.sens_id + "\n"
           + "read time = " + self.read_tm + "\n"
           + table([(self.data_name, "Identifier", '<'),
                    (self.data_type, "Type", '>'),
                    (self.data_valu, "Value", '>'), 
                    (self.data_unit, "Units", '>'),
                    (self.data_note, "Notes", '<')]))
        return rv


    def __repr__(self):
        """ Return a str representation of the class sufficient to reconstruct 
            the payload.
        """
        rv = "DataPayload.decode(" + self.encode() + ")"
        return rv

    def _convert_to_list(self):
        """ Return the contents of the message in the form of a list for use
            in superclass' encode.
        """
        return [self.inst_id, self.sens_id, self.read_tm, self.data_name, self.data_type, [str(i) for i in self.data_valu], self.data_unit, self.data_note]
   
 
    def _restore_from_list(self, restore_list):
        """ Restore the contents of the payload from a list intended the be of
            the same format as _convert_to_list.
        """
        self.inst_id = restore_list[0]
        self.sens_id = restore_list[1]
        self.read_tm = restore_list[2]
        self.data_name = restore_list[3]
        self.data_type = restore_list[4]
        self.data_valu = restore_list[5]
        self.data_unit = restore_list[6]
        self.data_note = restore_list[7]


    def __encode(self):
        raise PendingDeprecationWarning
        """ Likely depreciated. """
        rv = DELIMITERS[2].join([self.inst_id,
                                 self.sens_id,
                                 self.read_tm,
                                 DELIMITERS[3].join(self.data_name),
                                 DELIMITERS[3].join(self.data_type),
                                 DELIMITERS[3].join(self.data_valu),
                                 DELIMITERS[3].join(self.data_unit),
                                 DELIMITERS[3].join(self.data_note)])
        return rv

    @staticmethod
    def decode(to_decode):
        return MessagePayload.decode(to_decode, 1)

    #Should be static?
    @staticmethod
    def __decode(data_string):
        """ Likely depreciated. """
        raise PendingDeprecationWarning
        """
        payloads_list = payloads_string.split(DELIMITERS[2])
        if len(payloads_list) != 8:
            return False
        
        tmp_inst_id = payloads_list[0]
        tmp_sens_id = payloads_list[1]
        tmp_read_tm = payloads_list[2]
        tmp_data_name = payloads_list[3].split(DELIMITERS[3])
        tmp_data_type = payloads_list[4].split(DELIMITERS[3])
        tmp_data_valu = payloads_list[5].split(DELIMITERS[3])
        tmp_data_unit = payloads_list[6].split(DELIMITERS[3])
        tmp_data_note = payloads_list[7].split(DELIMITERS[3])
        if (len(data_name) != len(data_type)
                or len(data_type) != len(data_valu)
                or len(data_valu) != len(data_unit)
                or len(data_unit) != len(data_note)):
            return False
        
        # Validate the consistency of each entry
        for i in xrange(len(data_name)):
            if not check_item(tmp_data_name[i], tmp_data_type[i], 
                              tmp_data_valu[i], tmp_data_unit[i],
                                                tmp_data_note[i]):
                return False
        
        self.inst_id = tmp_inst_id
        self.sens_id = tmp_sens_id
        self.read_tm = tmp_read_tm
        self.data_name = tmp_data_name
        self.data_type = tmp_data_type
        self.data_valu = tmp_data_valu
        self.data_unit = tmp_data_unit
        self.data_note = tmp_data_note
        return True
        """


    def add_item(self, data_name, data_type, data_valu, data_unit, data_note):
        """ This function simply appends a "data point" to the existing
                message. True is returned on success, and False otherwise. 
            Paramaters
            ----------
            data_name (str): the name of the data point
            data_type (str): one letter abbreviation for type of value
            data_valu (int/str/float): the actual value of the data point
            data_unit (str): the unit associated with the value
            data_note (str): any noteworthy information about the data point
        """
        if DataPayload.check_item(data_name, data_type, data_valu, 
                                             data_unit, data_note):
            self.data_name.append(data_name)
            self.data_type.append(data_type)
            self.data_valu.append(data_valu)
            self.data_unit.append(data_unit)
            self.data_note.append(data_note)
            return True
        else:
            return False


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
        if DataPayload.check_type(identifier) \
                        and DataPayload.check_type(data_type) \
                        and DataPayload.check_type(value, data_type) \
                        and DataPayload.check_type(unit) \
                        and DataPayload.check_type(note) \
                        and DataPayload.check_length(identifier) \
                        and DataPayload.check_length(data_type) \
                        and DataPayload.check_length(str(value)) \
                        and DataPayload.check_length(unit) \
                        and DataPayload.check_length(note):
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
#!! RegistrationPayload

class RegistrationPayload(MessagePayload):
    """ This class and subclass as a whole need more thought, currently exists
        as a stub for development.
    """
    def __init__(self, mac_address = "ma", cpu_version = "cpu_v", hw_version = "hw_v", sw_version ="sw_v"):
        self.mac_address = mac_address
        self.cpu_version = cpu_version
        self.hw_version = hw_version
        self.sw_version = sw_version
        self.sensors = []

    def __str__(self):
        """ pretty print """
        rv = ""
        rv = rv + "mac_address = " + str(self.mac_address) + "\n"
        rv = rv + "cpu_version = " + str(self.cpu_version) + "\n"
        rv = rv + "hw_version = " + str(self.hw_version) + "\n"
        rv = rv + "sw_version = " + str(self.sw_version) + "\n"
        for i in xrange(len(self.sensors)):
            rv = rv + "Sensor [" + str(i) + "]:\n"
            rv = rv + indented(str(self.sensors[i]))
        return rv

        
    def add_sensor(self):
        """ Add space for additional sensor payload """
        self.sensors.append(_RegistrationSubPayload())

    def _convert_to_list(self):
        return [self.mac_address, self.cpu_version, self.hw_version, self.sw_version,
                    [sensor._convert_to_list() for sensor in self.sensors]]
        
    def _restore_from_list(self, restore_list):
        self.mac_address = restore_list[0]
        self.cpu_version = restore_list[1]
        self.hw_version = restore_list[2]
        self.sw_version = restore_list[3]
        self.sensors = []
        i = 0
        for sensor in restore_list[4]:
            self.add_sensor()
            self.sensors[i]._restore_from_list(sensor)
            i = i + 1
    
    @staticmethod
    def decode(to_decode):
        return MessagePayload.decode(to_decode, 0)
            


##############################################################################
#!! _RegistrationSubPayload():

class _RegistrationSubPayload(WaggleDefaults):
    """ This class as a whole need more thought, currently exists
        as a stub for development.
    """
    def __init__(self):
        self.sensor_id = ""
        self.communication_direction = 0
        self.time_interval = 0
        self.time_interval_type = 0
        self.field_value_name = []
        self.field_parameter_name = []
        self.field_parameter_type = []
        self.field_parameter_value = []

    def __str__(self):
        rv = ""
        rv = rv + "sensor_id = " + str(self.sensor_id) + "\n"
        rv = rv + "communication_direction = " + str(self.communication_direction) + "\n"
        rv = rv + "time_interval = " + str(self.time_interval) + "\n"
        rv = rv + "time_interval_type = " + str(self.time_interval_type) + "\n"
        rv = rv + table([(self.field_value_name, "Value Name", "<"),
                        (self.field_parameter_name, "Param Name", "<"),
                        (self.field_parameter_type, "Param Type", "<"),
                        (self.field_parameter_value, "Param Value", ">")])
        return rv

    def _convert_to_list(self):
        self.sensor_id = str(self.sensor_id)
        self.communication_direction = str(self.communication_direction)
        self.time_interval = str(self.time_interval)
        self.time_interval_type = str(self.time_interval_type)
        
        return [self.sensor_id, self.communication_direction, self.time_interval, self.time_interval_type, self.field_value_name, self.field_parameter_name, self.field_parameter_type, self.field_parameter_value]

    def _restore_from_list(self, restore_list):
        self.sensor_id = restore_list[0]
        self.communication_direction = restore_list[1]
        self.time_interval = restore_list[2]
        self.time_interval_type = restore_list[3]
        self.field_value_name = restore_list[4]
        self.field_parameter_name = restore_list[5]
        self.field_parameter_type = restore_list[6]
        self.field_parameter_value = restore_list[7]
    
    def add_field(self, value_name, parameter_name, parameter_type, parameter_value):
        self.field_value_name.append(value_name)
        self.field_parameter_name.append(parameter_name)
        self.field_parameter_type.append(parameter_type)
        self.field_parameter_value.append(parameter_value)




###############################################################################
#!! ReplyPayload

class ReplyPayload(MessagePayload):
    def __init__(self):
        self.return_value = 101
        self.output = "file1 file2 file3"

    def _convert_to_list(self):
        return [self.return_value, self.output]

    def _restore_from_list(self, restore_from):
        self.return_value = restore_from[0]
        self.output = restore_from[1]
        return

    @staticmethod
    def decode(to_decode):
        return MessagePayload.decode(to_decode, 3)


###############################################################################
#!! Message

class Message(WaggleDefaults):
    def __init__(self, header = MessageHeader(), apayloads = []):
        self.payloads = list(apayloads)
        self.header = header


    def append(self, new_payloads):
        """ This function appends more payloads entry to the message """
        self.header.msg_type = str(type_to_int(new_payloads.__class__))
        self.payloads.append(new_payloads)


    def clear(self):
        """ This function clears the content of the Message """
        raise NotImplementedError


    def encode(self):
        """ This function encodes the content of the Message and returns them
            as a string
        """
        header_str = self.header.encode()

        payloads_str = _encode([x.encode() for x in self.payloads], PAYLOAD_SEP_DELIM_INDEX)

        checksum = str(crc32(payloads_str))

        return _encode([header_str, checksum, payloads_str], ROOT_DELIM_INDEX)


    @staticmethod
    def decode(to_decode):
        """ takes a string and parses it to construct a message class """
        """ needs better methods for reinstantiating """
        rv = Message()
        decoded_list = _decode(to_decode, ROOT_DELIM_INDEX)
        rv.header = MessageHeader()
        rv.header = rv.header._restore_from_list(decoded_list[0])

        for i in xrange(len(decoded_list)-2):
            cur_payload = MessagePayload.new_payload(int(rv.header.msg_type))
            cur_payload._restore_from_list(decoded_list[i+2])
            rv.payloads.append(cur_payload)

        return rv
            

    @staticmethod
    def create_from_string(msg_str):
        return decode()


    def __str__(self):
        """ pretty print """
        rv = ""
        rv = rv + str(self.header)
        for i in xrange(len(self.payloads)):
            rv = rv + "Payload[" + str(i) + "]:\n"
            rv = rv + indented(str(self.payloads[i]))
        return rv


###############################################################################
#!! Send

def Send(message):
    """STUB"""
    #assert type(1) == type(int)
    print "Sent:", message.encode()
    
###############################################################################
#!! Tests

if __name__ == "__main__":
    def test_eq(a, b, msg):
        if a == b:
            print msg, "success"
        else:
            print msg, "failure"
            exit()
    
    #######################################################
    #!! Data Payload
    data_payload = DataPayload("inst_id", "sens_id", "time_read")
    for i in xrange(4):
        data_payload.add_item("name" + str(i), "s", "valu" + str(i),
                           "unit" + str(i), "note" + str(i))

    data_str = data_payload.encode()
    data_payload1 = DataPayload.decode(data_str)
    test_eq(data_payload, data_payload1, "DataPayload Encode/Decode")

    #######################################################
    #!! Registration Payload

    reg_payload = RegistrationPayload(str(get_mac_addr()), "cpu_version", "hw_v", "sw_v")
    for j in xrange(3):
        reg_payload.add_sensor() # may take arguments later
        reg_payload.sensors[j].sensor_id = "sens_id"
        reg_payload.sensors[j].communication_direction = "0 (ping-only)"
        reg_payload.sensors[j].time_interval = 123
        reg_payload.sensors[j].time_interval_type = "settable"
        for i in xrange(5-j):
            reg_payload.sensors[j].add_field("name" + str(i), "s", "valu" + str(i),
                               "unit" + str(i))
   
    reg_str = reg_payload.encode()
    reg_payload1 = RegistrationPayload.decode(reg_str)

    test_eq(reg_payload, reg_payload1, "RegistrationPayload Encode/Decode")

    #######################################################
    #!! Command Payload

    cmd_payload = CommandPayload()
    cmd_payload.instance_id = "inst_id"
    cmd_payload.command = "ls -arg1 -arg2 -arg3"

    cmd_str = cmd_payload.encode()
    cmd_payload1 = CommandPayload.decode(cmd_str)

    test_eq(cmd_payload, cmd_payload1, "Command Encode/Decode")
    
    #######################################################
    #!! Reply Payload

    rep_payload = ReplyPayload()
    rep_payload.return_value = "100"
    rep_payload.output = "file1 file2 file3"

    rep_str = rep_payload.encode()
    rep_payload1 = ReplyPayload.decode(rep_str)

    test_eq(rep_payload, rep_payload1, "Reply Encode/Decode")

    #######################################################
    #!! Message Header

    msg_header = MessageHeader()
    
    header_str = msg_header.encode()
    msg_header1 = MessageHeader.decode(header_str)

    test_eq(msg_header, msg_header1, "Header Encode/Decode")

    #######################################################
    #!! Message

    msg = Message()
    msg.append(data_payload)
    msg.append(data_payload)

    msg_str = msg.encode()
    msg1 = Message.decode(msg_str)

    test_eq(msg, msg1, "Message (Data) Encode/Decode")



    msg2 = Message()
    msg2.append(reg_payload)
    msg2.append(reg_payload)

    msg_str2 = msg2.encode()
    msg3 = Message.decode(msg_str2)

    test_eq(msg2, msg3, "Message (Reg) Encode/Decode")

    msg4 = Message()
    msg4.append(cmd_payload)
    msg4.append(cmd_payload)

    msg_str4 = msg4.encode()
    msg5 = Message.decode(msg_str4)

    test_eq(msg4, msg5, "Message (Cmd) Encode/Decode")

    msg4 = Message()
    msg4.append(rep_payload)
    msg4.append(rep_payload)

    msg_str4 = msg4.encode()
    msg5 = Message.decode(msg_str4)

    test_eq(msg4, msg5, "Message (Rep) Encode/Decode")








