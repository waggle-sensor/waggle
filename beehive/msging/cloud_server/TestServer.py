
import sys
sys.path.append("../../../devtools/protocol_common")
import pika
from protocol.PacketHandler import *
import logging
import time
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)


header_dict = {
    "msg_mj_type"      : ord('t'),
    "msg_mi_type"      : ord('r'),
}

creds = pika.PlainCredentials('guest1','guest1')
params = pika.ConnectionParameters('10.10.10.139',5672,'/',creds)
connection = pika.BlockingConnection(params)
channel = connection.channel()
print("Channel to RabbitMQ opened.")

queue = "ppppjf93kod93j0fu3kd93hf9hy309gtu"

packet = pack(header_dict,queue)
channel.exchange_declare("waggle_in")
channel.queue_declare(queue)
for i in range(1,1001):
	channel.basic_publish(exchange="waggle_in",routing_key="in",body=packet)
print "All time requests received!"


def callback(ch,method,props,body):
    global connection
    msg = time.ctime(float(unpack(body)[1]))
    print msg
    ch.basic_ack(delivery_tag = method.delivery_tag)


channel.basic_consume(callback,queue = queue)
channel.start_consuming()