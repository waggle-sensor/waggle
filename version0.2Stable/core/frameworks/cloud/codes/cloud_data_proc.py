from cloud_pika_connections import Consume, Connect, Send, CreateQueue
from waggle.common.messaging_d import *
from cloud_localconfig import *
import time

def run():
    queues = dict()
    con = Connect()
    CreateQueue(con, "malformed_data")
    Consume(callback, "data")

def write_to_file(dataStr, filePath):
    bufsize = 0
    fileStream = open(filePath, 'a+', bufsize)
    fileStream.write(dataStr.encode("UTF-8"))

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
    try:
        a = Message.decode(body)
        seq_id = 0
        for i in a.header.sequence_id:
            seq_id = (seq_id << 8) + ord(i)
        a.header.sequence_id = str(seq_id)
        writeString = a.encode()
    except:
        Send(con, "malformed_data", body)
        return
    try:
        #print time.asctime(),
        #print "%s" % repr(writeString)
        pass
    except:
        print "Processed unprintable."
    write_to_file(writeString.replace('\n', '\\n') + '\n', SENSOR_DATA_EXCHANGE_FILE)
    ch.basic_ack(delivery_tag = method.delivery_tag)

if __name__ == "__main__":
    run()
