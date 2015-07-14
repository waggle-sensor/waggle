
import sys
sys.path.append("../../devtools/protocol_common")
import pika
from protocol.PacketHandler import *
import logging
import time
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)


header_dict = {
    "msg_mj_type"      : ord('t'),
    "msg_mi_type"      : ord('r'),
}


params = pika.connection.URLParameters("amqp://guest1:guest1@10.10.10.148:5672/%2F")
connection = pika.BlockingConnection(params)
channel = connection.channel()
print("Channel to RabbitMQ opened.")

queue = "ppppjf93kod93j0fu3kd93hf9hy309gtu" 
packer = pack(header_dict,queue)
for thing in packer:
    packet = thing
channel.exchange_declare("waggle_in")
channel.queue_declare(queue)
channel.basic_publish(exchange="waggle_in",routing_key="in",body=packet)
print "All time requests received!"


def callback(ch,method,props,body):
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