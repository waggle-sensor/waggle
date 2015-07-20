
import sys
sys.path.append("../devtools/protocol_common")
import pika
from protocol.PacketHandler import *
import logging
import time
from utilities.gPickler import *
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)


header_dict = {
    "msg_mj_type"      : ord('s'),
    "msg_mi_type"      : ord('d'),
}

data = [3,1,4,5,9,2,6,5,3,5]
params = pika.connection.URLParameters("amqp://waggle:waggle@localhost:5672/%2F")
connection = pika.BlockingConnection(params)
channel = connection.channel()
print("Channel to RabbitMQ opened.")

queue = "BenT240" 
packer = pack(header_dict,gPickle(data))
for thing in packer:
    packet = thing
channel.exchange_declare("waggle_in")
channel.queue_declare(queue)
channel.basic_publish(exchange="waggle_in",routing_key="in",body=packet)


def callback(ch,method,props,body):
    print "Got something."
    global connection
    try:
        msg = time.ctime(float(unpack(body)[1]))
        print msg
    except Exception as e:
        print str(e)
    finally:
        ch.basic_ack(delivery_tag = method.delivery_tag)


channel.basic_consume(callback,queue = queue)
channel.start_consuming()
