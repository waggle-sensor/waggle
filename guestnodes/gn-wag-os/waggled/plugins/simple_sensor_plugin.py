class register(object):
    def __init__(self):
	sensor_read()


def sensor_read():
    import time, serial, sys

    print 'Beginning sensor script...'

    try:
	while True:
	    wxconnection = False
	    while wxconnection == False:
		try:
		    wxsensor = serial.Serial('/dev/ttyACM0',9600,timeout=300)
		    wxconnection = True
		    time.sleep(1)
		except:
		    print "Still waiting for connection. Is the sensor board plugged in?"
		    time.sleep(1)
	    try:
		wxsensor.flushInput()
		wxsensor.flushOutput()
	    except:
		wxsensor.close()
		wxconnection = False
	    while wxconnection == True:
		try:
		    readData = ' '
		    readData=wxsensor.readline()
		    print readData
		except:
		    wxsensor.close()
		    wxconnection = False
    except KeyboardInterrupt, k:
	try:
	    wxsensor.close()
	except:
	    pass
