#!/usr/bin/env python2.7

from _util import WaggleDefaults
from _message_header import MessageHeader
from _message_payload import MessagePayload
from _util import _encode
from _util import _decode
from _util import PAYLOAD_SEP_DELIM_INDEX
from _util import DELIMITERS
from _util import ROOT_DELIM_INDEX
from _util import indented
from _util import table
from binascii import crc32
from _registration_payload import RegistrationPayload
from _data_payload import DataPayload
from _reply_payload import ReplyPayload
from _command_payload import CommandPayload

class Message(WaggleDefaults):
    assert ROOT_DELIM_INDEX != PAYLOAD_SEP_DELIM_INDEX
    def __init__(self):
        """ Default "constructor", creates placeholder variables. """
        self.header = MessageHeader()
        self.payloads = list()


    def append(self, new_payload):
        """ This function appends more payloads entry to the message """
        if len(self.payloads) == 0:
            self.header.message_type = str(new_payload.PAYLOAD_ID)
            self.payloads.append(new_payload)
        elif self.payloads[0].PAYLOAD_ID == new_payload.PAYLOAD_ID:
            self.payloads.append(new_payload)
        else:
            raise TypeError("Mismatching payload type")


    def encode(self):
        """ Create a properly formatted message as a string. """
        header_str = self.header.encode()

        payloads_str = _encode([x.encode() for x in self.payloads], PAYLOAD_SEP_DELIM_INDEX)

        checksum = str(crc32(payloads_str))

        return _encode([header_str, payloads_str, checksum], ROOT_DELIM_INDEX)


    @staticmethod
    def decode(to_decode):
        """ takes a string and parses it to construct a message class """
        """ needs better methods for reinstantiating """
        # verify checksum
        rv = Message()
        decoded_list = to_decode.split(DELIMITERS[ROOT_DELIM_INDEX])

        rv.header = MessageHeader.decode(decoded_list[0])

        rv.payloads = [MessagePayload.decode(x, int(rv.header.message_type))
           for x in decoded_list[1].split(DELIMITERS[PAYLOAD_SEP_DELIM_INDEX])]


        checksum = str(crc32(decoded_list[1]))
        if checksum == decoded_list[2]:
            pass
        else:
            print ("Bad Checksum")
            #raise Exception("Bad Checksum") # should be more informative

        return rv
    
    @staticmethod
    def _DA_decode(to_decode, db_connector):
        """ This decode function should be used by data agent ONLY!!
            It introduces the db_connector so to enable unified database write function.

        """
        obj = Message.decode(to_decode)
        obj.db_connector = db_connector
        return obj

    def _push_to_db(self):
        type_num = int(self.header.message_type)

        part1 = "insert into sensor_data( protocol_version, inst_id, sequence_id, sensor_id"
        part2 = "self.protocol_version, self.instance_id, self.sequence_id, self.timestamp"
        #print 'Type:' +str(type_num)
        #self.payloads
        if RegistrationPayload.PAYLOAD_ID == type_num:
            print type_num
            pass
            #
        if DataPayload.PAYLOAD_ID == type_num: #
            print type_num # print "data------------------"
            
           
           
           
           #TODO: the database write function should be implemented in message or payload, if the payload can represent all information.
            
            '''
            leng = len(recs)
            print 'record obj done, records list len = ' + str(leng)
            for rec in recs:
                rec.insert_to_cassandra(self.db_connector)
                pass
            '''
        if ReplyPayload.PAYLOAD_ID == type_num:
            print type_num
            pass
        if CommandPayload.PAYLOAD_ID == type_num:
            print type_num
            pass



    def __str__(self):
        """ Print a user friendly version of the payload. """
        rv = str(self.header)
        for i in xrange(len(self.payloads)):
            rv = rv + "\nPayload[" + str(i) + "]:\n"
            rv = rv + indented(str(self.payloads[i]))
        return rv


###############################################################################
# Unit testing

if __name__ == "__main__":
    from _command_payload import CommandPayload
    from _registration_payload import RegistrationPayload
    from _reply_payload import ReplyPayload
    from _data_payload import DataPayload
    from _util import test_eq
    cmd_payload = CommandPayload()
    cmd_payload.instance_id = "inst_id"
    cmd_payload.command = "ls -arg1 -arg2 -arg3"

    rep_payload = ReplyPayload()
    rep_payload.return_value = 100
    rep_payload.output = "file1 file2 file3"







    reg_payload = RegistrationPayload()
    reg_payload.instance_id = "instnace_id"
    reg_payload.sys_info = dict({1: 2})

    data_payload = DataPayload()
    for i in xrange(4):
        data_payload.add_item("name" + str(i), "s", "valu" + str(i),
                           "unit" + str(i), "note" + str(i))

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

    msg6 = Message()
    msg6.append(rep_payload)
    msg6.append(rep_payload)

    msg_str6 = msg6.encode()
    msg7 = Message.decode(msg_str6)


    test_eq(msg6, msg7, "Message (Rep) Encode/Decode")

