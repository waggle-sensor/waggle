#!/usr/bin/env python3

import os.path
import glob
import json
import os
import subprocess
import re

import sys
sys.path.append('/usr/lib/waggle/nodecontroller/wagman')
from wagman_client import *

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
    print("read_file: "+str)
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
    command = ['bash', '-c', 'source %s && env' % (script)]
    environment={}
    proc = subprocess.Popen(command, stdout = subprocess.PIPE)

    for line in proc.stdout:
        (key, _, value) = line.decode().partition("=")
        environment[key] = value.rstrip()

    proc.communicate()
    
    return environment
    

def get_command_output(command):
    
    result = ''
    
    try:
        result = subprocess.check_output(command, shell=True)
    except:
        pass
    
    return result.decode("utf-8").rstrip()
        
    
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
summary['wagman']['id']=''
summary['wagman']['connected']=wagman_connected()

if summary['wagman']['connected']:
    try:
        summary['wagman']['id'] = wagman_client(['id'])[1].strip()
    except:
        pass
    
    print("wagman_id: \"%s\"" % (summary['wagman']['id']))


# TODO thermistors
# TODO wagman reset (SRE line)



### Extension node

# TODO: recursive call (scp and ssh) (only one recursion!!!)



### Coresense
summary['coresense']={}
summary['coresense']['connected']=coresense_connected()
print("coresense connected:", summary['coresense']['connected'])

# TODO: Read sensor values ?
#(get values? use waggle-plugin log ?)

# TODO: Read UUIDs from Airsense, Lightsense and Chemsense (also use log ?)
summary['airsense']={}
summary['airsense']['UUID']='NA'

summary['lightsense']={}
summary['lightsense']['UUID']='NA'

summary['chemsense']={}
summary['chemsense']['UUID']='NA'




### Cameras


# issue: found no way to map lsusb and /dev/videoX devices

summary['cameras']={}
summary['cameras']['list'] = []




# known cameras:
# 05a3:9520 -- ELP-USB500W02M-{L21,L170} ; Sorry, there's no way to distiguish lenses.
# 05a3:9830 -- ELP-USB8MP02G-L75   Sonix_Technology_Co.__Ltd._USB_2.0_Camera_SN0001


for vendor_product in ['05a3:9830', '05a3:9520']:

    # example output os lsusb: "Bus 003 Device 006: ID 05a3:9520 ARC International"
    lsusb_result=''
    
    lsusb_result = get_command_output(["lsusb", "-d", vendor_product])
    
    for line in lsusb_result.split("\n"):
        #print "line:", line
        matchObj = re.match( r'Bus (\d{3}) Device (\d{3}): ID (\S{4}):(\S{4}) (.*)$', line, re.M|re.I)
        if matchObj:
            #print "matchObj.group() : ", matchObj.group()
        
            camera={}
            camera['bus']           =matchObj.group(1).rstrip()
            camera['device']        =matchObj.group(2).rstrip()
            camera['idVendor']      =matchObj.group(3).rstrip()
            camera['idProduct']     =matchObj.group(4).rstrip()
            camera['vendor_name']   =matchObj.group(5).rstrip()
        
            bus_device = "%s:%s" % (camera['bus'], camera['device'])
        
            for line in get_command_output(["lsusb", "-s", bus_device , "-v" ]).split("\n"):
                #print line
                for key in ['wHeight','wWidth']:
                    matchObj = re.match( r'.*%s\( 0\)\s+(\d+)' % (key), line, re.M|re.I)
                    if matchObj:
                        #print "got:", key, matchObj.group(1).rstrip()
                        camera[key] = matchObj.group(1).rstrip()
            
            # TODO: try v4l2 to extract resolution
            # v4l2-ctl --list-formats-ext -d /dev/video? works , BUT: I do not know which video device that would be!!!
        
            print(json.dumps(camera, indent=4))
            summary['cameras']['list'].append(camera)
        
            # TODO:  fswebcam -r 2592x1944 --jpeg 95 -D 0 best.jpg
            # apt-get install fswebcam
       

#TODO install fswebcam  and v4l-utils on image

#TODO fswebcam and confirm image

# list devices
#ls -1 /dev/ | grep "^video"
video_devices = get_command_output('ls -1 /dev/ | grep "^video"').split('\n')

summary['video_devices']={}
summary['video_devices']['list'] = []

for video_device in video_devices:
    print("--------------------------- %s", video_device)
    command  = 'udevadm info --query=all /dev/%s | grep "P: /devices/virtual" | wc -l' % (video_device)
    print(command)
    count_virtual = get_command_output(command)
    print("\"%s\"" % (count_virtual))
    if count_virtual == "1":
        # video device is virtual
        print("virtual device")
        continue
    print("NOT virtual device")
    
    video_device_obj={}
    video_device_obj['device']='/dev/%s' % (video_device)
    
    #TODO list all possible resolutions (rightv now this just extracts the highest resolution and ignores the Pixel Format)
    # alternative to extract resolution might be: ffmpeg -f v4l2 -list_formats all -i /dev/video0
    resolutions = get_command_output('v4l2-ctl --list-formats-ext -d /dev/%s | grep -o "Size: Discrete [0-9]*x[0-9]*" | grep -o "[0-9]*x[0-9]*"' % (video_device)).split('\n')
    print(resolutions)
    max_resolution_size = 0
    max_resolution_x = 0
    max_resolution_y = 0
    for resolution in resolutions:
        print("resolution:", resolution)
        (x, _, y) = resolution.partition('x')
        try:
            size = int(x)*int(y)
        except Exception:
            print("error: could not parse resolution", resolution)
            continue
        print(x,y, size)
        if size > max_resolution_size:
            max_resolution_size = size
            max_resolution_x = x
            max_resolution_y = y
    print(max_resolution_x, max_resolution_y , max_resolution_size)
    video_device_obj['max_resolution_x'] = max_resolution_x
    video_device_obj['max_resolution_y'] = max_resolution_y
    video_device_obj['max_resolution_size'] = max_resolution_size
    summary['video_devices']['list'].append(video_device_obj)
# get highest resolution
# v4l2-ctl --list-formats-ext -d /dev/video0

# v4l2-ctl --list-formats-ext -d /dev/video0 | grep -o "Size: Discrete [0-9]*x[0-9]*" | grep -o "[0-9]*x[0-9]*"



### modem

summary['modems']={}
summary['modems']['list'] = list_pantech_modems()
summary['modems']['list'].append(list_other_modems())
print("modems:" , summary['modems']['list'])

summary['modems']['IMEI']='NA'




### Microphone in USB bus

# TODO: parse lsusb


 
 
print(json.dumps(summary, indent=4))



