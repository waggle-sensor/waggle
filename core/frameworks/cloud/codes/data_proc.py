from pika_connections import Consume, Connect, Send, CreateQueue
from waggle.common.messaging_d import *
from localconfig import *
import time



def run():
    queues = dict()

    con = Connect()
    CreateQueue(con, "malformed_data")
    Consume(callback, "data")
    

def write_to_file(dataStr, filePath):
    bufsize = 0 #100000000
    fileStream = open(filePath, 'a+', bufsize)
    fileStream.write(dataStr.encode("UTF-8"))
    pass

def callback(ch, method, properties, body):
    global con
    global queues

    msg = Message.decode(body)

    queue_name = "outbound_" + msg.header.instance_id
    if not queue_name in queues:
        CreateQueue(con, queue_name)
        queues[queue_name] = "" #because access time

    Send(con, queue_name, "ack")

def callback(ch, method, properties, body):

    print "\n############################################################################################\n"
    print "Begin %.4f" % time.time()

    try:
        print "Raw Data:\n'%s'" % repr(body)
    except:
        print "Raw unprintable."

    print "\n--------------------\n"

    try:
        a = Message.decode(body)
        print type(body)
        seq_id = 0
        for i in a.header.sequence_id:
#            print i, type (i), repr(i), ord(i)
            seq_id = (seq_id << 8) + ord(i)
        a.header.sequence_id = str(seq_id)
        writeString = a.encode()
    except:
        Send(con, "malformed_data", body)
        return
    
    try:
        print "Processed Data:\n'%s'" % repr(writeString)
    except:
        print "Processed unprintable."
    write_to_file(writeString.replace('\n', '\\n') + '\n', RAW_DATA_FILE)

    print "End   %.4f" % time.time()
    ch.basic_ack(delivery_tag = method.delivery_tag)

if __name__ == "__main__":
    run()
