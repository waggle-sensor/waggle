#!/usr/bin/env python

import os.path
import glob
import json
import os
import subprocess


#Test serial connection with XU4 and with C1+
#use minicom


wagman_device='/dev/waggle_sysmon'

coresense_device='/dev/waggle_coresense'


alphasense_device='/dev/alphasense'


# cameras, see https://github.com/waggle-sensor/waggle_image/blob/master/device_rules/wwan_modems/75-wwan-net.rules
camera_pantech_device_prefix='/dev/vzwwan'
camera_other_device_prefix='/dev/attwwan'


summary = {}


def read_file( str ):
    print "read_file: "+str
    if not os.path.isfile(str) :
        return ""
    with open(str,'r') as file_:
        return file_.read().strip()
    return ""
    



def wagman_connected():
    return os.path.exists(wagman_device)
    
    

def coresense_connected():
    return os.path.exists(coresense_device)


def list_pantech_modems():
    return glob.glob('/dev/%s[0-9]' % (camera_pantech_device_prefix))


def list_other_modems():
    return glob.glob('/dev/%s[0-9]' % (camera_other_device_prefix))


def read_sourced_env(script):
    command = ['bash', '-c', 'source init_env && env']
    environment={}
    proc = subprocess.Popen(command, stdout = subprocess.PIPE)

    for line in proc.stdout:
      (key, _, value) = line.partition("=")
      environment[key] = value

    proc.communicate()
    
    return environment
    
    
def get_mac_address():
    environment = read_sourced_env('/usr/lib/waggle/waggle_image/scripts/detect_mac_address.sh')
    return environment['MAC_ADDRESS'] if 'MAC_ADDRESS' in environment else "NA"
    
    
def get_odroid_model():
    environment = read_sourced_env('/usr/lib/waggle/waggle_image/scripts/detect_odroid_model.sh')
    return environment['ODROID_MODEL'] if 'ODROID_MODEL' in environment else "NA"


###############################################################


### MAC
summary['MAC-address']=get_mac_address()


### Odroid model
summary['odroid-model']=get_odroid_model()



### WagMan
summary['wagman']={}
summary['wagman']['connected']=wagman_connected()
print "wagman connected:", summary['wagman']['connected']

# TODO later: talk with wagman




### Extension node

# TODO: something like: ssh extensionnode cat /etc/hostname  ???
# TODO: Odroid model and mac-address, e.g. ssh extensionnode /usr/lib/waggle/waggle_image/scripts/detect_odroid_model.sh



### Coresence
summary['coresense']={}
summary['coresense']['connected']=coresense_connected()
print "coresense connected:", summary['coresense']['connected']

# TODO: Read sensor values ?
#(get values? use waggle-plugin log ?)

# TODO: Read UUIDs from Airsense, Lightsense and Chemsense (also use log ?)
summary['airsense']={}
summary['airsense']['UUID']='NA'

summary['lightsense']={}
summary['lightsense']['UUID']='NA'

summary['Chemsense']={}
summary['Chemsense']['UUID']='NA'




### Cameras

# TODO: parse lsusb
summary['cameras']={}
summary['cameras']['list'] = []

#TODO: collect vendor ID and device ID

#TODO: get picture for verification





### modem

summary['modems']={}
summary['modems']['list'] = list_pantech_modems()
summary['modems']['list'].append(list_other_modems())
print "modems:" , summary['modems']['list']

summary['modems']['IMEI']='NA'




### Microphone in USB bus

# TODO: parse lsusb


 
 
print json.dumps(summary, indent=4)



