import serial
import time
import os
DEVICE = "/dev/waggle_coresense"
ready = 1
while 1:
    if os.path.exists(DEVICE):
        if ready == 1:
            ready = 0
            time.sleep(1)
            os.system("make program >> /dev/null")
            time.sleep(3)
            macaddr = ''
            ser = serial.Serial(DEVICE,115200)  # open serial port
            macaddr=ser.readline()
            macaddr=ser.readline()
            ser.close()  
            if macaddr <> '':
                id_num = raw_input('Please 3 digit ID:') #check if this is valid number
                print id_num,macaddr
                
    else:
        ready = 1

    time.sleep(1)