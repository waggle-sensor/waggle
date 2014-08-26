#!/usr/bin/env python2.7

#from waggle.common.util import Record
#from waggle.common.util import * # this is bad, and temporary

'''
        DELIMITERS[i]:
        [0]: used only for string message type
        [1]: used to separage different msg in a string
        [2]: for data fields in a msg
        [3]: for sub fields in a data field
'''
global DELIMITERS
NUM_DELIM = 10
DELIMITERS = [unichr(200+i) for i in xrange(NUM_DELIM)]
    # Unicode DELIMITERS, for real use.
DELIMITERS = [' [' + str(i) + '] ' for i in xrange(NUM_DELIM)]
    # DELIMITERS for test only. 

def arrayToStr(array, delimiterIndex):
    string = ''
    for it in array:
        string = string + DELIMITERS[int(delimiterIndex)] + it
    #print string
    return string


def msg_parse(msg):
    """ Take a string message, parse it to an *ARRAY* of record objects for further use. 
    Parameters
    ----------
    msg: str
    """
    record = None
    records = {}
    tokenL0 = msg.split(DELIMITERS[0])
    msgBody = tokenL0[1]
    records = []
    if '1' == tokenL0[0]:
        print 'msg type 1 found:'
        records.append( _single_msg_parse(msgBody) )
        return records
    elif '2' == tokenL0[0]:
        print 'msg type 2 found:'
        subMsgs = msgBody.split(DELIMITERS[1]) # return a list
        subMsgs.remove('')
        print 'length of subMsgs = ' + str(len(subMsgs))
        arrayLen = len(subMsgs)
        #print 'subMsgs[0]: ' + subMsgs[0]
        #print 'subMsgs[1]: ' + subMsgs[1]
        i = 0
        for it in subMsgs:
            #print 'subMsgs['+ str(i) + ']: ' + it
            records.append( _single_msg_parse(it) ) #problem!
            #print 'records-' + str(i) 
            #print 'records[i].paramNote:'
            #print records[i].paramUnit[0]
            #print records[i].paramNote[0]
            i = i + 1
        return records
    elif '3' == tokenL0[0]:
        print 'msg type 3 found: blob info processed.'
        records.append( _single_msg_parse(msgBody) )
        return records

    elif 0 > int(tokenL0[0]):
        print 'Error report msg found: tag = ' + int(tokenL0[0])
        rec = _single_msg_parse(msgBody)
        rec.status = tokenL0[0]
    return records


def _single_msg_parse(msgBody):
    if '' == msgBody:
        print 'Empty string, parer failed and exit.'
        return 'Error'
    dataFields = msgBody.split(DELIMITERS[2])
    ip = dataFields[0]
    instID = dataFields[1]
    sensorID = dataFields[2]
    readTime = dataFields[3]
    paramName = dataFields[4].split(DELIMITERS[3])
    paramType = dataFields[5].split(DELIMITERS[3])
    paramVal = dataFields[6].split(DELIMITERS[3])
    paramUnit = dataFields[7].split(DELIMITERS[3])#.remove('')
    paramNote = dataFields[8].split(DELIMITERS[3]) #.remove('')
    paramName.remove('')
    paramType.remove('')
    paramVal.remove('')
    paramUnit.remove('')
    paramNote.remove('')
    #print paramName
    #print paramType
    #print paramVal
    #print paramUnit
    #print paramNote
    record = (ip, instID, sensorID, readTime, paramName, paramType, paramVal, paramUnit, paramNote)
    return record


def msg_gen(instID, sensorID, readTime, paramName, 
            paramType, paramVal, paramUnit, paramNote):
    """
    This function takes data input and generate a string message for
        transferring. Note that this function generates msg for ONE
        reading from ONE sensor, while the sensor can have multiple values.
    Parameters
    ----------
    instID: str
        Instance ID
    readTime: str
        time stamp of reading, please use time.time() for it.
    paramName: array of str
        defined as paramName[], name list ofdata items in the data body.
            eg: paramName[2] = 'Temperature'
    paramType: array of str
        defined as dataItemTypeList[], type list of the data body. 
            eg: (string, int, float, raw_data_in_blob, image_blob) should
            be presented as typeList = ['s','i','f','R','I'], all blob
            data should use CAPS. We can define a dictionary of this later.
            eg: paramType[2] = 'i' for int. 
    paramVal: array of str
        data values; eg: paramVal[2] = '102'
    paramUnit: array of str
        units for data items. eg: paramUnit[2] = 'F'  
    paramNote: array of str
        any extra information for the particular data item
    """
    str_paramType = arrayToStr(paramType, 3)
    str_paramName = arrayToStr(paramName, 3)
    str_paramVal = arrayToStr(paramVal, 3)
    str_paramUnit = arrayToStr(paramUnit, 3)
    str_paramNote = arrayToStr(paramNote, 3)
    delimHeader1 = DELIMITERS[2]
    str_msg = getLanIP() \
            + delimHeader1 + instID        + delimHeader1 + sensorID \
            + delimHeader1 + readTime      + delimHeader1 + str_paramName \
            + delimHeader1 + str_paramType + delimHeader1 + str_paramVal \
            + delimHeader1 + str_paramUnit + delimHeader1 + str_paramNote
    return str_msg


