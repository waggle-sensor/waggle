import serial
import time
import commands
port = serial.Serial('/dev/waggle_coresense', 115200)
while (1):
    line = port.readline()
    if (line.startswith("4. Unique Board ID -")):
        print line.split("-")[1].strip()
        break;

