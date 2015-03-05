#!/usr/bin/env python
import pika
from waggleUtil import *
import logging
from connectors import *
global timeCounter1
timeCounter1=0
global msgNum
msgNum =0
'''
def insertDB(db_connector, key_len, val_len):
    key = randomStringGen(key_len)
    value = randomStringGen(val_len)
    exp1 = "insert into load_data (key, value) values ( "
    exp2 = "'" + key + "', '" + value + "');"
    exp =  exp1 + exp2
    #print exp
    try:
        start = time.time()
        db_connector._executeCQL(exp)
        end = time.time()
        timeCounter1 = timeCounter1 + (end - start)
        print "Latency_avg = " + str(1000*timeCounter1/msgNum)
    except (InvalidRequest, Unavailable, Timeout, AlreadyExists, OperationTimedOut, Unauthorized, WriteTimeout, ReadTimeout):
        print 'something wrong... \n\n\n'
'''
class Tester():
    credentials = None
    RABBITMQ_USER = 'clients'
    RABBITMQ_PASSWORD = 'Ruza3que'
    queueName = 'sizeTest'
    RMQHOST = ''

    def __init__(self, db_connector):
        #self.RABBITMQ_USER = 'clients'
        #self.RABBITMQ_PASSWORD = 'Ruza3que'
        #self.queueName = 'sizeTest'
        #self.RMQHOST = getLanIP() #'192.168.1.26' # '149.165.149.8'
        #self.credentials = pika.PlainCredentials(self.RABBITMQ_USER, self.RABBITMQ_PASSWORD)
        #self.connection = pika.BlockingConnection(pika.ConnectionParameters(self.RMQHOST, credentials=self.credentials))
        #self.channel = self.connection.channel()
        #self.consume_stream = sys.argv[1]
        #self.filePath = filePath
        #self.channel.queue_declare(queue = self.queueName, auto_delete = True)
        self.db_connector = db_connector
        self.myIP = getLanIP()
        #self.storeType = 'file'
        #self.delimiter = DELIMITERS[2]
        self.msgNum = 0
        self.timeCounter1 = 0
        #path = os.environ['PWD']
        #self.dataStore = stateManagerClient(self.role, self.storeType,
        #filePath, socket.gethostname(),
        #self.myIP, 9160, self.delimiter)
        #global VECTOR_CLOCK
        #VECTOR_CLOCK = VectorClock(self.delimiter)

    def insertDB(self, db_connector, key_len, val_len):
        key = randomStringGen(key_len)
        value = randomStringGen(val_len)
        exp1 = "insert into load_data (key, value) values ( "
        exp2 = "'" + key + "', '" + value + "');"
        exp =  exp1 + exp2
        #print exp
        #self.msgNum = self.msgNum +1
        try:
            #start = time.time()
            db_connector._executeCQL(exp)
            #end = time.time()
            #self.timeCounter1 = self.timeCounter1 + (end - start)
            #print "Latency_avg = " + str(1000*self.timeCounter1/self.msgNum)
        except (InvalidRequest, Unavailable, Timeout, AlreadyExists, OperationTimedOut, Unauthorized, WriteTimeout, ReadTimeout):
            print 'something wrong... \n\n\n'

if __name__ == '__main__':
    pathPrefix = '/home/ubuntu/working/'
    filePath = os.path.join(pathPrefix + socket.gethostname() +'_states.dat')
    print 'outPut filePath = ' + filePath
    hosts = ['149.165.149.3', '149.165.149.8']
    keyspace = 'load_test'  #'weatherdb'
    myConn = CassConnector(hosts, keyspace)
    tester = Tester(myConn)
    timeCounter1 = 0
    opNum =1000
    start = time.time()
    for i in range(0, opNum):
        tester.insertDB(myConn, 15, 85)
    end = time.time()
    latency = (end - start)*1000/opNum
    print "Average latency = " + str(latency)
