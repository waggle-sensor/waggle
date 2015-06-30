import serial
import time  
port_ard = serial.Serial('/dev/ttyACM0', 1200,timeout=1)
print port_ard
port_ard.readline()
port_ard.close()
