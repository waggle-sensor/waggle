#!/usr/bin/env python
import pika
from waggleUtil import *
import logging
from connectors import *

logging.basicConfig()
class DataAgent():
    credentials = None
    RABBITMQ_USER = 'clients'
    RABBITMQ_PASSWORD = 'Ruza3que'
    queueName = 'sizeTest'
    RMQHOST = ''
    
    def __init__(self, filePath, db_connector):
        self.RABBITMQ_USER = 'clients'
        self.RABBITMQ_PASSWORD = 'Ruza3que'
        self.queueName = 'sizeTest'
        self.RMQHOST = getLanIP() #'192.168.1.26' # '149.165.149.8'
        self.credentials = pika.PlainCredentials(self.RABBITMQ_USER, self.RABBITMQ_PASSWORD)
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(self.RMQHOST, credentials=self.credentials))
        self.channel = self.connection.channel()
        #self.consume_stream = sys.argv[1]
        self.filePath = filePath
        self.channel.queue_declare(queue = self.queueName, auto_delete = True)
        self.db_connector = db_connector
        self.myIP = getLanIP()
        self.storeType = 'file'
        self.delimiter = DELIMITERS[2]
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
        try:
            start = time.time()
            db_connector._executeCQL(exp)
            end = time.time()
            self.timeCounter1 = self.timeCounter1 + (end - start)
            #print "Latency_avg = " + str(1000*self.timeCounter1/self.msgNum)
        except (InvalidRequest, Unavailable, Timeout, AlreadyExists, OperationTimedOut, Unauthorized, WriteTimeout, ReadTimeout):
            print 'something wrong... \n\n\n'
        '''
            print 'InvalidRequest'
        except Unavailable:
            print 'Unavailable'
        except Timeout:
            print 'Timeout'
        except AlreadyExists:
            print 'AlreadyExists'
        except OperationTimedOut:
            print 'OperationTimedOut'
        except Unauthorized:
            print 'Unauthorized'
        '''

        

    def consume_func(self, ch, method, properties, body):
        self.msgNum = self.msgNum + 1
        #print self.msgNum
        self.insertDB(self.db_connector, 15, 85)
        pass
        #self.msgNum = self.msgNum + 1
        #size = len(str(body))
        
        #print "blob received, size = " + str(size) + 'bytes'
        #print "GOT: '%s'" % body
        #print "msg received: " + str(self.msgNum) + ", size = " + str(size)
	
        #write_to_file(writeString, self.filePath)
        # Cassandra adaptor.
        #recs = Record.msg_parse(body)
        #leng = len(recs)
        #TODO: measure db latency
        #TODO: calculate average latency for every 100 write request
        #print 'record obj done, records list len = ' + str(leng)
        #for rec in recs:
            #rec.insert_to_cassandra(self.db_connector)
        #print rec.instID
        #print rec.sensorID
        #print rec.paramNote
        #rec.insert_to_cassandra() #wrong here!!!!
        #VECTOR_CLOCK.updateMasterClockByLocal()
        #self.dataStore.put('cloud-key', body, VECTOR_CLOCK) # key, value, vectorClock. Now only value

    def consumeLoop(self, ):
        print "Consuming..."
        try:
            #self.channel.basic_consume(self.consume_func, queue = self.consume_queue.method.queue, no_ack = True)
            self.channel.basic_consume(self.consume_func, queue = 'sizeTest', no_ack = True)
            self.channel.start_consuming()
        except KeyboardInterrupt:
            self.connection.close()

if __name__ == '__main__':
    pathPrefix = '/home/ubuntu/working/'
    filePath = os.path.join(pathPrefix + socket.gethostname() +'_states.dat')
    print 'outPut filePath = ' + filePath
    hosts = ['149.165.149.25', '149.165.149.8']
    keyspace = 'load_test'  #'weatherdb'
    myConn = CassConnector(hosts, keyspace)
    agent = DataAgent(filePath, myConn)
    agent.consumeLoop()
   
    '''
    msg = '1 [0] 192.168.1.39 [2] instance-123 [2] sensor-456 [2] 1403232946.66 [2]  [3] name1 [3] name2 [3] name3 [3] name4 [2]  [3] type1 [3] type2 [3] type3 [3] type4 [2]  [3] data1 [3] data2 [3] data3 [3] data4 [2]  [3] unit1 [3] unit2 [3] unit3 [3] unit4 [2]  [3] note1 [3] note2 [3] note3 [3] note4'
    rec = Record.msg_parse(msg)
    print len(rec)
    rec[0].unitTest(myConn)
    '''    

'''
def callback(ch, method, properties, body):
    print " [x] Received %r" % (body,)


connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()


channel.queue_declare(queue='hello')

channel.basic_consume(callback,
                      queue='hello',
                      no_ack=True)


print ' [*] Waiting for messages. To exit press CTRL+C'
channel.start_consuming()
'''
