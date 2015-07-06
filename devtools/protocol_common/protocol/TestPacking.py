# TestPacking.py

import sys
sys.path.append("..")
from PacketHandler import *

header_data = {
	"msg_mj_type" : 67,
	"msg_mi_type" : 0
}

msg = "hi"

"""
for i in range(0,1001):
	msg += str(i)
	"""
print "Message is %i bytes long." % len(msg)
packets = []

for packet in pack(header_data,msg):
	packets.append(packet)

for packet in packets:
	data = unpack(packet)
	print packet
	print "\n\n\n"