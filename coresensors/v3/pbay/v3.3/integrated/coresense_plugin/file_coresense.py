import sys
import serial

if __name__ == '__main__':
	# if (len(sys.argv) != 2):
	# 	sys.exit()

	# filename = sys.argv[1]
	filename = "shdata.txt"

	ser = serial.Serial("/dev/ttyACM1", baudrate = 115200)

	with open(filename, 'r') as f:
		for l in f:
			data = l.split(' ', 1)[1].strip()
			length = len(data)
			# b = ''.join('{:02x}'.format(int("0x" + data, 16)))
			# print b[0]
			# print b[1]
			# print b[2]
			# ser.write(b)
			for i in range(0, length, 2):
				nibble1 = data[i]
				nibble2 = data[i + 1]

				# byte = "".join("{:02x}".format(int("0x" + nibble1 + nibble2, 16)))
				byte = chr(int("0x" + nibble1 + nibble2, 16))
				print byte
				ser.write(byte)
			# break
	# ser.write("hello\r\n")
	ser.close()



# import serial
# s = serial.Serial("/dev/ttyACM0", baudrate=115200)

# s.flushInput()
# s.flushOutput()

# s.readline()


# import serial
# s = serial.Serial("/dev/ttyACM1", baudrate=115200)

# s.flushInput()
# s.flushOutput()

# s.write("hello\r\n")