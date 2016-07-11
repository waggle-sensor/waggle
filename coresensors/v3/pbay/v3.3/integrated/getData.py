import serial
import time

while 1:
    try:
        link = serial.Serial("/dev/ttyACM0", 115200)
        #link = serial.Serial("/dev/ttyUSB0", 19200)
        print "connected"
        break
    except:
        print "no connection"
	time.sleep(1)

print "nothing"
f = open('superpacket_assembler.bin', 'w+')
try:
    while 1:
        data = link.readline()
        # Write binary data to a file
    #    f.write(data)
    #    print data[:3]
    #    data.index('\r')
    #	print time.asctime()
        print data
    #    print ":".join("{:02x}".format(ord(c)) for c in data)
    #    hex_data = data.decode('hex')
    #    print " "
    #    print hex_data
except (KeyboardInterrupt, SystemExit):
    link.close()
    f.close()

f.close()
link.close()
