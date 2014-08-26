from message_packer import MessagePacker
from weather_client import data_client
from commands import getoutput as bash
import sensors

sensors.init()

message = MessagePacker()

# requires grep, sed, head, cut, ifconfig

mac_address = bash("ifconfig | grep HWaddr | sed 's/  */ /g' | cut -d ' ' -f 5")
proccessor_id = bash("grep 'model name' /proc/cpuinfo | head -1 | sed 's/.*:\(.*\)/\\1/' | sed 's/  *//g'")


instance_id = mac_address + "#" + proccessor_id
#print instance_id, " - continue:"

messages = []
message = MessagePacker()
try:
    for chip in sensors.iter_detected_chips():
#        print '%s at %s' % (chip, chip.adapter_name)
        message = MessagePacker()
        message.instance_id = str(instance_id)
        message.sensor_id = str(chip)
        message.read_time = "now"
        for feature in chip:
            try:
#                print '  %s: %.2f' % (feature.label, feature.get_value())
                message.add_item(str(feature.label), 'f', feature.get_value(), 
                                 str(feature.type) + "<-- Not correct" , "")
            except:
                pass

#        print "Going to send:\n", message
        messages.append(message.generate())
finally:    
    sensors.cleanup()

data_client.multi_send(messages)
    
#print message
