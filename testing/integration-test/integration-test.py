#!/usr/bin/env python

import os.path
import glob
import json


#Test serial connection with XU4 and with C1+
#use minicom


wagman_device='/dev/waggle_sysmon'

coresense_device='/dev/waggle_coresense'


alphasense_device='/dev/alphasense'


# cameras, see https://github.com/waggle-sensor/waggle_image/blob/master/device_rules/wwan_modems/75-wwan-net.rules
camera_pantech_device_prefix='/dev/vzwwan'
camera_other_device_prefix='/dev/attwwan'


summary = {}

def wagman_connected():
    return os.path.exists(wagman_device)
    
    

def coresense_connected():
    return os.path.exists(coresense_device)


def list_pantech_modems():
    return glob.glob('/dev/%s[0-9]' % (camera_pantech_device_prefix))


def list_other_modems():
    return glob.glob('/dev/%s[0-9]' % (camera_other_device_prefix))




###############################################################



### WagMan
summary['wagman']={}
summary['wagman']['connected']=wagman_connected()
print "wagman connected:", summary['wagman']['connected']

# TODO later: talk with wagman


### Extension node


# TODO: something like: ssh extensionnode ls


###Coresence
summary['coresense']={}
summary['coresense']['connected']=coresense_connected()
print "coresense connected:", summary['coresense']['connected']


# TODO: Read sensor values ?
#(get values? use waggle-plugin log ?)



### Cameras

# TODO: parse lsusb
summary['cameras']={}
summary['cameras']['list'] = []



### modem

summary['modems']={}
summary['modems']['list'] = list_pantech_modems()
summary['modems']['list'].append(list_other_modems())
print "modems:" , summary['modems']['list']

### Microphone in USB bus

# TODO: parse lsusb


 
 
print json.dumps(summary, indent=4)



