""" This file contains a dictionary mapping GN device priority data cache queue location. The dictionary is used by both internal and external comms for message storage. """ 

#TODO Need to add or remove devices as needed
#TODO Devices should be added when they register to NC

with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    
#Maps the device ID to the queue location in DC 
DEVICE_DICT = {
    '1244' : 1, #test GN
    HOSTNAME : 5 #NC
    
    }
    