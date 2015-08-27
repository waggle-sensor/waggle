class register(object):
	def __init__(self, name, man):
		man[name] = 1
		#self.sensor_read()

		import time, serial, sys

		print 'Beginning sensor script...'
		while True:
			while (man[name] == 1):
				print man
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
			
			if (man[name] == 0):
				print name,"exiting."
				break
			elif (man[name] == -1):
				print name,"paused."
				while(man[name] == -1):
					pass
			elif (man[name] != 1):
				print "Error in",name,"- Run value must be -1, 0, or 1"
				time.sleep(2)
