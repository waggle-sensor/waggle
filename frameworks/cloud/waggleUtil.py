#!/usr/bin/env python
import os
import socket
import commands
import time
import string
import random
from datetime import timedelta, datetime



class Record():
    def __init__(self, ip, instID, sensorID, readTime, paramName, paramType, paramVal, paramUnit, paramNote):
        self.status = '0' #state that the event/command associated to this record is succefully executed
	self.ip = ip
        self.instID = instID
        self.sensorID = sensorID
        self.readTime = readTime
        self.paramName = paramName
        self.paramType = paramType
        self.paramVal = paramVal
        self.paramUnit = paramUnit
        self.paramNote = paramNote
        self.recvTime = str(time.time())
    
    def _unitTest(self, param):
        print self.ip
        self.insert_to_cassandra(param)

    @staticmethod
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
        record = Record(ip, instID, sensorID, readTime, paramName, paramType, paramVal, paramUnit, paramNote)
        return record
         
    @staticmethod
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
            records.append( Record._single_msg_parse(msgBody) )
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
                records.append( Record._single_msg_parse(it) ) #problem!
                #print 'records-' + str(i) 
                #print 'records[i].paramNote:'
                #print records[i].paramUnit[0]
                #print records[i].paramNote[0]
                i = i + 1
            return records
        elif '3' == tokenL0[0]:
            print 'msg type 3 found: blob info processed.'
            records.append( Record._single_msg_parse(msgBody) )
            return records

	elif 0 > int(tokenL0[0]):
            print 'Error report msg found: tag = ' + int(tokenL0[0])
	    rec = Record._single_msg_parse(msgBody)				 
            rec.status = tokenL0[0]
        return records
	
    def insert_to_cassandra(self, cass_connector): #wrong here
	#"insert into test (instid, sensorid, ip, readtime, recvTime, paramname, paramType, paramV    al, paramUnit, paramNote) values ('inst-100003', 'sensor-2187', '149.165.149.19', '1503703571.15',     '1893103571.15',['name1', 'name2', 'name3'], ['type1','type2','type3'], ['val1','val2','val3'], ['u    nit1', 'unit2', 'unit3'], ['note1', 'note2', 'note3'])"
        print 'insert_to_cassandra() start...'
        part1 = "insert into test (instid, sensorid, ip, readtime, recvTime, paramname, paramType, paramVal, paramUnit, paramNote, status) values ( "
	part2 = "'" + self.instID + "', '" + self.sensorID + "', '" + self.ip + "', '" + self.readTime + "', '" + self.recvTime + "', " 
	part3  = _converToStr(self.paramName) + ', ' +  _converToStr(self.paramType) + ', ' + _converToStr(self.paramVal) + ', ' + _converToStr(self.paramUnit) + ', ' + _converToStr(self.paramNote)  + ", '"  + self.status + "'"

	statement = part1 +	part2 + part3 + ")"	
	print statement
        cass_connector._executeCQL(statement)
        #TODO: make a insert CQL statement from a Record obj

def _converToStr(paramList):
    """
    Convert a list or array to a string that can be used in preparing a query statement:

    """
    string = '['
    for it in paramList:
        string = string + "'" + it + "',"
    string = string[:-1]
    string = string + ']'
    return string



if os.name != "nt":
    import fcntl
    import struct

    def getInterfaceIP(ifname):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        return socket.inet_ntoa(fcntl.ioctl(s.fileno(), 0x8915, struct.pack('256s',
                                ifname[:15]))[20:24])


def getLanIP():
    try:
        ip = socket.gethostbyname(socket.gethostname())
    except:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(("gmail.com",80))
        ip = s.getsockname()[0]
        s.close()

    if ip.startswith("127.") and os.name != "nt":
        interfaces = [
            "eth0",
            "eth1",
            "eth2",
            "wlan0",
            "wlan1",
            "wifi0",
            "ath0",
            "ath1",
            "ppp0",
            ]
        for ifname in interfaces:
            try:
                ip = getInterfaceIP(ifname)
                break
            except IOError:
                pass
    return ip


def randomStringGen(length):
    charSet = string.letters + string.digits
    return ''.join(random.choice(charSet) for x in range(length))


'''
	DELIMITERS[i]:
	[0]: used only for string message type
	[1]: used to separage different msg in a string
	[2]: for data fields in a msg
	[3]: for sub fields in a data field
'''
global DELIMITERS
#DELIMITERS = [unichr(200), unichr(201), unichr(202), unichr(203), unichr(204), unichr(205), unichr(206), unichr(207),unichr(208),unichr(209)] # Unicode DELIMITERS, for real use.
DELIMITERS = [' [0] ',' [1] ',' [2] ',' [3] ',' [4] ',' [5] '] # DELIMITERS for test only. 

def arrayToStr(array, delimiterIndex):
    string = ''
    for it in array:
        string = string + DELIMITERS[int(delimiterIndex)] + it
    #print string
    return string

def write_to_file(dataStr, filePath):
    bufsize = 0 #100000000
    fileStream = open(filePath, 'a+', bufsize)
    fileStream.write(dataStr.encode("UTF-8"))
    pass

def runLinuxCMD(cmd):
    ret = str(commands.getstatusoutput(cmd))
    return ret

'''
Test case.

print runLinuxCMD('ls -lah')
a = ['j','f','hgjd','vzc','123']
arrayToStr(a, 0)
arrayToStr(a, 1)
arrayToStr(a, 2)

for it in DELIMITERS:
    print it

'''
