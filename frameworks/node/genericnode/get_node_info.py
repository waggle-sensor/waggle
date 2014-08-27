from commands import getoutput as bashit
from config_file_functions import initialize_config_file, ConfigObj
from gn_global_definition_section import logger

##!/bin/bash
#echo "Hostname: $(hostname"
#echo "No, of CPU: $(cat /proc/cpuinfo  | grep -i  processor | wc -l"
#echo "CPU: $(cat /proc/cpuinfo  | grep -i  model\ name | uniq | tr -s " " | cut -d ":" -f 2"
#echo "CPU Vendor: $(cat /proc/cpuinfo | grep -i  vendor_id | uniq | cut -d ":" -f 2"
#echo "CPU Capabilities: $(cat /proc/cpuinfo | grep -i  flags | tr ' ' '\n' | sort | uniq | grep -i  -v flag | tr '\n' ' '"
#echo "Memory: $("
#echo "Network: $(ifconfig | tr " " "\n" | grep -i "[a-z,0-9][a-z,0-9]:[a-z,0-9][a-z,0-9]:[a-z,0-9][a-z,0-9]:[a-z,0-9][a-z,0-9]:[a-z,0-9][a-z,0-9]:[a-z,0-9][a-z,0-9]""


def get_node_info(config_file_name):
        
    config_object = ConfigObj(config_file_name)
    config = config_object["Systems Info"]
    
    
    list_of_keywords = ["hostname", "noOfProcessors", "cpuModelName", "cpuVendorID", "extensions", "hardware", "interfaces",
                        "memTotal", "osName", "osVersion", "osID", "osPrettyName", "osVersionID", "osKernelRelease", "machineName", "kernelVersion", "diskStorage"]
    
    list_of_cmds = [
                    "hostname", 
                    "cat /proc/cpuinfo  | grep -i  processor | wc -l", 
                    "cat /proc/cpuinfo  | grep -i  model\ name | uniq | tr -s ' ' | cut -d ':' -f 2",
                    "cat /proc/cpuinfo | grep -i  vendor_id | uniq | cut -d ':' -f 2",
                    ["cat /proc/cpuinfo | grep -i  flags | tr ' ' '\n' | sort | uniq | grep -i  -v flag | tr '\n' ' '", "cat /proc/cpuinfo | grep -i  features | tr ' ' '\n' | sort | uniq | grep -i  -v features | tr '\n' ' '"],
                    "cat /proc/cpuinfo | grep -i hardware | cut -d ':' -f 2",
                    ["ls /sys/class/net/", "cat /sys/class/net/"],
                    'cat /proc/meminfo | tr -s " "  | grep -i  MemTotal | cut -d ":" -f 2',
                    'cat /etc/os-release | grep -i NAME | grep -vi "pretty_name" | cut -d "=" -f 2 ',
                    'cat /etc/os-release | grep -i VERSION | grep -vi "version_id" |cut -d "=" -f 2',
                    'cat /etc/os-release | grep -i ID=ubuntu | cut -d "=" -f 2',
                    'cat /etc/os-release | grep -i PRETTY_NAME | cut -d "=" -f 2',
                    'cat /etc/os-release | grep -i VERSION_ID | cut -d "=" -f 2',
                    'uname -r',
                    'uname -m',
                    'cat /proc/version',
                    "df -h  | tr -s ' ' | cut -d ' ' -f 1,2,5,6 | tr '\n' ';' | sed 's/;/\ ;\ /g'"
                   ]
                   
    for key, cmd in zip(list_of_keywords, list_of_cmds):
        try:
            if not isinstance(cmd, list):
                config[key] = bashit(cmd)
            else:
                if key == "interfaces":
                    interfaces = bashit(cmd[0])
                    interfaces=interfaces.split('\n')
                    config[key] = interfaces
                    if interfaces:
                        interface_details = ''
                        for i in interfaces:
                            if i <> 'lo':
                                interface_details += str(i) + ',' + bashit(cmd[1]+str(i)+"/address") + '\n'
                        interface_details = interface_details.split('\n')
                        config[key] = interface_details
                elif key == 'extensions':
                    config[key] = bashit(cmd[0])
                    if not config[key]:
                        config[key] = bashit(cmd[1])
            if not config[key]:
                    del config[key]  
        except Exception as inst:
            logger.critical("Exception in get_system_info: " + str(inst) + "while executing command " + str(cmd) +"\n\n")
            return 1 
    config_object.write()        
    return 0