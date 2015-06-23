from PacketHandler import *
header_dict = {
    "prot_ver"         : "0.3",
    "flags"            : (5,6,True),
    "len_body"         : 42,
    "time"             : 42,
    "msg_mj_type"      : 42,
    "msg_mi_type"      : 42,
    "snd_session"      : 42,
    "s_uniqid"         : 42,
    "ext_header"       : 42,
    "resp_session"     : 42,
    "r_uniqid"         : 42,
    "snd_seq"          : 42,
    "resp_seq"         : 42
}

body = "This is a much longer sample message that might be sent to the RabbitMQ broker to be used for waggle stuff."

packet = pack(header_dict,body)
unpacked = unpack(packet)
if (header_dict,body) == (unpacked[0],unpacked[1]):
    print "TestPacking succeeded"
else:
    print "TestPacking failed"
    print unpacked[0]
    print header_dict
    print unpacked[1]
    print body