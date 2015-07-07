# TestPacking.py

import sys
sys.path.append("..")
from PacketHandler import *
from utilities.packetassembler import *



msg = ""

for i in range(0,1001):
	msg = msg + str(i) + " "
print "Message is %i bytes long." % len(msg)

packets = []

assembler = PacketAssembler()
transfer_num = assembler.reserve_channel(4)

header_data = {
	"msg_mj_type" : 67,
	"msg_mi_type" : transfer_num
}


for packet in pack(header_data,msg):
	packets.append(packet)


for packet in packets:
	assembler.add_packet(packet)

print assembler.get_complete()
