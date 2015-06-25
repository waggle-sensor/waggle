# packetmaker.py
"""
	This module contains a few utilities that autogenerate complete simple packets,
	such as ping and time request packets.
"""

import sys
sys.path.append("..")
from protocol.src.PacketHandler import *

# TODO: Find a way around two separate sequence sequences when using this module


def make_ping_packet():
	"""
		Returns a simple ping request packet.

		:rtype: string
	"""
	header_dict = {
		"msg_mj_type" : ord('p'),
		"msg_mi_type" : ord('r')
	}
	return pack(header_dict)

def make_time_packet():
	"""
		Returns a simple time request packet.

		:rtype: string
	"""
	header_dict = {
		"msg_mj_type" : ord('t'),
		"msg_mi_type" : ord('r')
	}
	return pack(header_dict)