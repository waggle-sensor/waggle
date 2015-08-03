import sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities.packetmaker import *
sys.path.append('../Communications/')
from internal_communicator import send

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
    
with open('/etc/waggle/server_ip','r') as file_:
    CLOUD_IP = file_.read().strip()
    
def create_dev_dict():
    #Maps the device ID to the queue location in DC 
    with open('/etc/waggle/devices', 'r') as file_:
        lines = file_.readlines()

    #the third line in the devices file contains a mapping of devices to their priority
    #that is used to contruct the dictionary
    mapping = []
    while True:
        if not lines[2].find(',') == -1:
            device, lines[2] = lines[2].split(',', 1)
            device, priority = device.split(':',1)
            mapping.append((device,int(priority)))
        else:
            break
    #print 'create dev dict: ', mapping
    return dict(mapping)


DEVICE_DICT = create_dev_dict()

def update_dev_dict():
    DEVICE_DICT = create_dev_dict()
    return DEVICE_DICT
        
#lists the order of device priority. Each device corresponds with a location in the data cache
#The highest priority position is at the front of the list, the lowest priority is at the end.
PRIORITY_ORDER = [5,4,3,2,1] 

#This specifies the maximum RAM available to the data cache
#Here, we assume that each message stored is no larger than 1K
AVAILABLE_MEM = 576482


#The params used to connect to the cloud are stored here
#CLOUD_ADDR = 'amqps://waggle:waggle@10.10.10.134:5671/%2F'
CLOUD_ADDR = 'amqps://waggle:waggle@' + CLOUD_IP + ':5671/%2F'

def send_config():
    """ 
    This function sends all of the stored information to the cloud.
    
    """
    #add all the configuration
    config ='Hostname: ' + HOSTNAME + '\n'
    config = config + 'Queuename: ' + QUEUENAME + '\n'
    config = config + 'Node Controller IP: ' + NCIP + '\n'
    config = config + 'Device dictionary: ' + str(DEVICE_DICT) + '\n'
    config = config + 'Priority order: ' + str(PRIORITY_ORDER) + '\n'
    config = config + 'Available memory for data cache: ' + str(AVAILABLE_MEM) + '\n'
    config = config + 'Cloud IP address and parameters: ' + CLOUD_ADDR + '\n'

    packet = make_config_reg(config)
    for pack in packet:
        send(pack)
    
    
    
    
    
    
    
    
    