import serial
import time

while 1:
    try:
	link = serial.Serial("/dev/ttyACM0", 115200)
	print "connected"
	break
    except:
	print "no connection"
	time.sleep(1)

print "nothing"
while 1:
    data = link.readline()
#    print data[:3]
#    data.index('\r')
    print data
#    print ":".join("{:02x}".format(ord(c)) for c in data)
#    hex_data = data.decode('hex')
#    print " "
#    print hex_data

link.close()
