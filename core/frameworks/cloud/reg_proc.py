from pika_connections import Consume, Connect, Send, CreateQueue
from waggle.common.messaging_d import *
import time

queues = dict()

con = Connect()

def run():
    CreateQueue(con, "malformed_registration")
    Consume(callback, "registration")
    

def write_to_file(dataStr, filePath):
    bufsize = 0 #100000000
    fileStream = open(filePath, 'a+', bufsize)
    fileStream.write(dataStr.encode("UTF-8"))
    pass

def callback(ch, method, properties, body):
    #print "GOT: '%s'" % body
    #writeString = body  + '\n'

    try:
        a = Message.decode(body)
        seq_id = 0
        for i in a.header.sequence_id:
            seq_id = (seq_id << 8) + ord(i)
        a.header.sequence_id = str(seq_id)
        writeString = a.encode()
        write_to_file(writeString.replace('\n', '\\n') + '\n', "/home/rajesh/waggleData/beehive.dat-reg")
        ch.basic_ack(delivery_tag = method.delivery_tag)
    except:
        Send(con, "malformed_registration", body)
        ch.basic_ack(delivery_tag = method.delivery_tag)
        return
    
if __name__ == "__main__":
    run()
