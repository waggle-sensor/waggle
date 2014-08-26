from uuid import getnode as get_mac

from waggle.device.common.message_packer import MessagePacker
#from waggle.device.node_controller.weather_client import data_client
from commands import getoutput as bash
import time
import sensors
import logging

logging.basicConfig(level=logging.DEBUG,
                    format='%(name)s: %(message)s',
                    )
logger = logging.getLogger("sensor_data")
 

def LocalTime():
    local_time = time.localtime()
    return str(local_time.tm_year) + "." + str(local_time.tm_mon) + "." + \
           str(local_time.tm_mday) + "." + str(local_time.tm_hour) + "." + \
           str(local_time.tm_min) + "." + str(local_time.tm_sec)
           
def get_sensors_info():
    
    
    sensors.init()
    
    message = MessagePacker()
    
    # requires grep, sed, head, cut, ifconfig
    
    mac_address = str(get_mac())
    proccessor_id = bash("grep 'model name' /proc/cpuinfo | head -1 | sed 's/.*:\(.*\)/\\1/' | sed 's/  *//g'")
    
    
    instance_id = mac_address + "#" + proccessor_id
    messages = []
    message = MessagePacker()
    try:
        for chip in sensors.iter_detected_chips():
    #        print '%s at %s' % (chip, chip.adapter_name)
            message = MessagePacker()
            message.instance_id = str(instance_id)
            message.sensor_id = str(chip)
            message.read_time = LocalTime()
            for feature in chip:
                try:
    #                print '  %s: %.2f' % (feature.label, feature.get_value())
                    message.add_item(str(feature.label), 'f', feature.get_value(),
                                     str(feature.type), "")
                except:
                    pass
    
    #        print "Going to send:\n", message
            messages.append(message.generate())
    finally:
        sensors.cleanup()
    return messages
    

print "done here"
    
    
    
    #data_client.multi_send(messages)
    
    #print message
