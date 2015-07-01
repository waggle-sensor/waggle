import serial
import time
Link_unavailable = True
while Link_unavailable:
    try:
        link = serial.Serial('/dev/ttyACM0',57600)
        print link
        Link_unavailable = False
    except:
        print "Waiting for device...",str(time.asctime())
        time.time(3)

while 1:
    try:
        print str(time.asctime()),link.readline(),
    except:
        print 'Lost device, reclaiming...',str(time.asctime())
        Link_unavailable = True
        while Link_unavailable:
            try:
                link = serial.Serial('/dev/ttyACM0',57600)
                Link_unavailable = False
            except:
                print "Waiting for device...",str(time.asctime())
                time.time(3)

