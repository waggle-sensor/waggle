# -*- coding: utf-8 -*-
"""
list returned by reference ..how returning a class object is better than a list
"""


'''
	DELIMITERS[i]:
	[0]: used only for string message type
	[1]: used to separage different msg in a string
	[2]: for data fields in a msg
	[3]: for sub fields in a data field
'''

from waggle.common.util import *


global DELIMITERS
DELIMITERS = [' [0] ',' [1] ',' [2] ',' [3] ',' [4] ',' [5] '] # DELIMITERS for test only. 



def get_single_sensor_info(msgBody):
    if '' == msgBody:
            print 'Empty string, parer failed and exit.'
            return 'Error'
    dataFields = msgBody.split(DELIMITERS[2])
    sensorID = dataFields[2]
    readTime = dataFields[3]
    paramNames = dataFields[4].split(DELIMITERS[3])
    paramTypes = dataFields[5].split(DELIMITERS[3])
    paramVals = dataFields[6].split(DELIMITERS[3])
    paramUnits = dataFields[7].split(DELIMITERS[3])#.remove('')
    paramNotes = dataFields[8].split(DELIMITERS[3]) #.remove('')
    paramNames.remove('')
    paramTypes.remove('')
    paramVals.remove('')
    paramUnits.remove('')
    paramNotes.remove('')
    return [sensorID, readTime, paramNames, paramTypes, paramVals, paramUnits, paramNotes]
        
        
def parse_multi_sensor_info(msgs):
    sensors_info = []
    for single_msg in msgs:
        single_sensor_info = Record._single_msg_parse(single_msg)
        single_sensor_info = convert_record_to_list(single_sensor_info)
        sensors_info.append(single_sensor_info)
    return sensors_info


def convert_record_to_list(record):
    return [record.sensorID, record.readTime, record.paramName, record.paramType, record.paramVal, record.paramUnit, record.paramNote]

    
def convert_to_string(msgs, delimiter_indx):
    string_msg = '*'
    for msg in msgs:
       string_msg += msg + DELIMITERS[delimiter_indx]
    string_msg += '*'
    print "msg in string form:"+string_msg+"\n"
    return string_msg
    
def string_to_list(string, delimiter_indx):
    string.split()
    
