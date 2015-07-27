"""
    This file stores all of the configurable variables for the node controller. 

"""

#TODO Need to make sure this file can be updated by other classes
#This contains a dictionary mapping GN device priority data cache queue location. 
#The dictionary is used by both internal and external comms for message storage.
#TODO Need to add or remove devices as needed
#TODO Devices should be added when they register to NC

#Node's hostname
with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    
#Node's queuename
with open('/etc/waggle/queuename','r') as file_:
    QUEUENAME = file_.read().strip() 
    
#The IP address of the node controller is stored here
with open('/etc/waggle/NCIP','r') as file_:
    NCIP = file_.read().strip()
    
#Maps the device ID to the queue location in DC 
DEVICE_DICT = {
    '1244' : 1, #test GN
    HOSTNAME : 5 #NC
    }

#lists the order of device priority. Each device corresponds with a location in the data cache
#The highest priority position is at the front of the list, the lowest priority is at the end.
PRIORITY_ORDER = [5,4,3,2,1] 

#This specifies the maximum RAM available to the data cache
#Here, we assume that each message stored is no larger than 1K
AVAILABLE_MEM = 299,999


#The params used to connect to the cloud are stored here
CLOUD_ADDR = 'amqps://waggle:waggle@10.10.10.110:5671/%2F'

def update_device_dict(new_dev):
    DEVICE_DICT.update(new_dev)
    
    
    