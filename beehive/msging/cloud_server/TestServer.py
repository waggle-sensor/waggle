
import sys
sys.path.append("../../../devtools/protocol_common")
import pika
from protocol.PacketHandler import *
import logging
import time
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)


header_dict = {
    "msg_mj_type"      : ord('r'),
    "msg_mi_type"      : ord('r'),
}


connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()
print("Channel to RabbitMQ opened.")

queue = "jf93kod93j0fu3kd93hf9hy309gtu"

packet = pack(header_dict,queue)
channel.exchange_declare("waggle_in")
channel.queue_declare(queue)
for i in range(1,1001):
    channel.basic_publish(exchange="waggle_in",routing_key="in",body=packet)


def callback(ch,method,props,body):
    global connection
    msg = unpack(body)[1]
    print msg
    ch.basic_ack(delivery_tag = method.delivery_tag)


channel.basic_consume(callback,queue = queue)
channel.start_consuming()