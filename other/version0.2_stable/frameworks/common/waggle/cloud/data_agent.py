#!/usr/bin/env python
import pika
from waggle.common.util import *
from waggle.common.messaging import *
import logging
from waggle.cloud.connectors import *
from waggle.common.messaging_d import *

logging.basicConfig()
class DataAgent():
    credentials = None
    RABBITMQ_USER = 'clients'
    RABBITMQ_PASSWORD = 'Ruza3que'
    queueName = 'weather'
    RMQHOST = ''
    
    def __init__(self, filePath, db_connector):
        self.RABBITMQ_USER = 'clients'
        self.RABBITMQ_PASSWORD = 'Ruza3que'
        self.queueName = 'weather'
        self.RMQHOST = getLanIP()
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
        #path = os.environ['PWD']
        #self.dataStore = stateManagerClient(self.role, self.storeType, 
        #filePath, socket.gethostname(), 
        #self.myIP, 9160, self.delimiter)
        #global VECTOR_CLOCK
        #VECTOR_CLOCK = VectorClock(self.delimiter)

    def consume_func_old(self, ch, method, properties, body):
        print "GOT: '%s'" % body
        #TODO: send feed-back/commands to client (v3 or later)
        #TODO: file writer.
        writeString = body + DELIMITERS[2] + str(time.time()) + '\n'
	write_to_file(writeString, self.filePath)
        #TODO: Cassandra adaptor.
        recs = Record.msg_parse(body)
        leng = len(recs)
        print 'record obj done, records list len = ' + str(leng)
        for rec in recs:
            rec.insert_to_cassandra(self.db_connector)
            pass
        #print rec.instID
        #print rec.sensorID
        #print rec.paramNote
        #rec.insert_to_cassandra() 
        #VECTOR_CLOCK.updateMasterClockByLocal()
        #self.dataStore.put('cloud-key', body, VECTOR_CLOCK) # key, value, vectorClock. Now only value

    def consume_func(self, ch, method, properties, body):
        #print "GOT: '%s'" % body
        #writeString = body  + '\n'

        print "\n############################################################################################\n"

        try:
            print "Raw Data:\n'%s'" % body
        except:
            print "Raw unprintable."

        print "\n--------------------\n"

        try:
            a = Message.decode(body)
            seq_id = 0
            for i in a.header.sequence_id:
    #            print i, type (i), repr(i), ord(i)
                seq_id = (seq_id << 8) + ord(i)
            a.header.sequence_id = str(seq_id)
            body = a.encode()
            writeString = body
        except:
            print "\n\n", repr(body)
            exit()
        
        try:
            print "Processed Data:\n'%s'" % writeString
        except:
            print "Processed unprintable."
	write_to_file(writeString.replace('\n', '\\n') + '\n', self.filePath)

        msg_type = ""
        #try:
        #recs = Record.msg_parse(body)
        msgObj = Message._DA_decode(writeString, self.db_connector)
        msgObj._push_to_db()
        '''
        msg_type = msgObj.header.message_type
        print "msgObj.header.msg_type =  " + msg_type
        print  msgObj.payloads
        type_num = int(msg_type)
        #msg_type: 0 for reg, 1 for data, 2 command_reply
        if RegistrationPayload.PAYLOAD_ID == type_num:
            pass
            #

        if DataPayload.PAYLOAD_ID == type_num: #
            print "data------------------"
            #TODO: the database write function should be implemented in message or payload, if the payload can represent all information.
            
            
            leng = len(recs)
            print 'record obj done, records list len = ' + str(leng)
            for rec in recs:
                rec.insert_to_cassandra(self.db_connector)
                pass
            
        if ReplyPayload.PAYLOAD_ID == type_num:
            pass
        if CommandPayload.PAYLOAD_ID == type_num:
            pass
        '''    
        #except:
        #    print "consume_func() error, msg_type = " + msg_type
        #print rec.instID
        #print rec.sensorID
        #print rec.paramNote
        #rec.insert_to_cassandra() 
        #VECTOR_CLOCK.updateMasterClockByLocal()
        #self.dataStore.put('cloud-key', body, VECTOR_CLOCK) # key, value, vectorClock. Now only value


    def consumeLoop(self, ):
        print "Consuming..."
        try:
            #self.channel.basic_consume(self.consume_func, queue = self.consume_queue.method.queue, no_ack = True)
            self.channel.basic_consume(self.consume_func, queue = 'weather', no_ack = True)
            self.channel.start_consuming()
        except KeyboardInterrupt:
            self.connection.close()

if __name__ == '__main__':
    pathPrefix = '/home/ubuntu/waggleData/'
    filePath = os.path.join(pathPrefix + socket.gethostname() +'_states.dat')
    print 'outPut filePath = ' + filePath
    hosts = ['149.165.149.25', '149.165.149.8']
    keyspace = 'weatherdb'
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
