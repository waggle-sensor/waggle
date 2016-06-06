import serial
import string

while 1:
	try:
		link = serial.Serial("/dev/waggle_due_program", 115200)
		print "connected"
		break
	except:
		print "no connection"
		time.sleep(1)

buffer_string = ""
while 1:
	get_string = link.readline()
	buffer_string += get_string

	if 'BAD' in buffer_string:
		if '\r\n' in buffer_string:
			idx_beg = buffer_string.index('B')
			#print idx_beg
			idx_end = buffer_string.index('\r\n')
			#print idx_end
			packet = buffer_string[idx_beg:idx_end]
			#print packet
			buffer_string = buffer_string[idx_end+1:]
			Parse(packet)

	print "readline"
			
#	print data_string
#	print ":".join("{:02x}".format(ord(c)) for c in data)
#	hex_data = data.decode('hex')
#	print hex_data

#	if data = "\r"
#		idx = 0
#	if data = 

def Signed_int(hex_int, bits):
	move = hex_int >> (bits - 1)
	remain = (1 << (bits - 1)) - 1
	if move == 1:
		return -1 * (hex_int & remain)
	else:
		return hex_int

def Parse(packet):
	print packet.encode('hex')
	print_data = ""
	KEY_string = packet[0:3]
	print_data += KEY_string + "="
	value_string = packet[3:9]
	print_data += value_string.encode('hex') + " "

	KEY_string = packet[9:12]
	print_data += KEY_string + "="
	value_string = packet[12:13]
	print_data += value_string.encode('hex') + " "
	SQ = int(value_string.encode('hex'), 16) % 4
	#print SQ
	packet = packet[13:]
	#print packet.encode('hex')

	while len(packet) > 2:
		KEY_string = packet[0:3]
		print_data += KEY_string + "="

		if KEY_string == 'SHH':
			value_string = packet[3:5]
			hex_int = int(value_string.encode('hex'), 16)
			print_data += str(hex_int) + " "  
			packet = packet[5:]
			#print 'form1'

		elif KEY_string == 'SUV' or KEY_string == 'SVL' or KEY_string == 'SIR':
			value_string = packet[3:5]
			hex_int = int(value_string.encode('hex'), 16)
			print_data += str(hex_int) + " "  
			packet = packet[5:]
			#print 'hex, form1: ',
			#print KEY_string

		elif SQ == 1:
			value_string = packet[3:6]
			hex_int = int(value_string.encode('hex'), 16)
			hex_int = Signed_int(hex_int, 24)
			print_data += str(hex_int) + " " 						 # signed int
			packet = packet[6:]
			#print 'form5'

		elif KEY_string == 'VIX' or KEY_string == 'OIX' or KEY_string == 'LPP':
			value_string = packet[3:6]
			hex_int = int(value_string.encode('hex'), 16)
			print_data += str(hex_int) + " "  
			packet = packet[6:]
			#print 'form4'

		else:
			#print packet.encode('hex')	
			#print print_data

			value_string = packet[3:5]
			hex_int = int(value_string.encode('hex'), 16)
			hex_int = Signed_int(hex_int, 16)
			print_data += str(hex_int) + " " 						# signed int
			packet = packet[5:]
			#print 'form2'

	print print_data
	print ""
"""
			hex_int = value_string.encode('hex')
			hex_int_int = string.atol(hex_int, 16)
			print hex_int
			print hex_int_int
"""


