import serial
import time
Link_unavailable = True


while Link_unavailable:
    try:
        link = serial.Serial('/dev/ttyACM1',115200)
        Link_unavailable = False
        link.flushInput()
        link.flushOutput()
    except:
        print "Waiting for device...",str(time.asctime())
        time.time(3)

while 1:
    data = link.readline()
    data_bytes = data.split(',')[:-1]
    try:
        if data_bytes[0x00] == '170':
            protocol = data_bytes[1]
            print "------------------------"

            if protocol == '0':
                print 'protocol version:', protocol,
                length_of_packet = int(data_bytes[0x02])
                print "Packet Length:",length_of_packet
                if len(data_bytes) > length_of_packet+4:
                    if data_bytes[length_of_packet+4] == '85':
                        consume_ptr = 0x03
                        while consume_ptr < length_of_packet:
                            This_id = data_bytes[consume_ptr]
                            This_id_msg_size_valid = int(data_bytes [consume_ptr+1])
                            This_id_msg_size = This_id_msg_size_valid & 0x7F
                            This_id_msg_valid = (This_id_msg_size_valid & 0x80) >> 7
                            This_id_msg = data_bytes [consume_ptr+2:consume_ptr+2+This_id_msg_size]
                            print "ID:", This_id,
                            print "Length:", This_id_msg_size,
                            print "Validity:", This_id_msg_valid,
                            print "Data:", This_id_msg
                            consume_ptr = consume_ptr + 2 + This_id_msg_size
    except:
        pass