import serial
import time

while 1:
    try:
	link = serial.Serial("/dev/waggle_coresense", 115200)
	print "connected"
        break
    except:
	print "no connection"
        time.sleep(1)

#When a link is found  
try:
	while 1:
	    link.write("a")#link.write(line)
	    print "a"
	    time.sleep(10)

	    link.write("b")#link.write(line)
	    print "b"
	    time.sleep(10)

except KeyboardInterrupt:
	link.write("b")
	print "b"
	link.close()


link.close()
