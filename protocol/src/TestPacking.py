import PacketHandler
from PacketHandler import *
header_dict = {
    "msg_mj_type"      : ord('p'),
    "msg_mi_type"      : ord('r'),
}

body = "This is a much longer sample message that might be sent to the RabbitMQ broker to be used for waggle stuff."

print PacketHandler.SEQUENCE
packet = pack(header_dict,body)
print PacketHandler.SEQUENCE
header_dict.update(get_header(packet))
unpacked = unpack(packet)
if (header_dict,body) == (unpacked[0],unpacked[1]):
    print "TestPacking succeeded"
else:
    print "TestPacking failed"
    print unpacked[0]
    print header_dict
    print unpacked[1]
    print body