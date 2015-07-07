# WaggleRouter.py
import sys
sys.path.append("../../devtools/protocol_common")
from multiprocessing import Process, Manager
import pika
from protocol.PacketHandler import *
import logging
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)

class WaggleRouter(Process):
	"""
		The WaggleRouter class receives all messages from the incoming queue in the RabbitMQ server.
		It then reads the packet header to learn the message type, and forwards it to the appropriate
		queue for processing.
	"""
	def __init__(self,routing_table):
		print "Initializing Routing Process"
		super(WaggleRouter,self).__init__()
		print "Superclass initialization complete."
		
		self.routing_table = routing_table

		self.routeQueues	= {
			'r' : 'registration',
			't' : 'util',
			'p' : 'util',
			's' : 'data'
		}
		print "Establishing connection"
		#Create a connection to the RabbitMQ server.
		self.rabbitConn = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
		self.channel = self.rabbitConn.channel()
		self.channel.basic_qos(prefetch_count=1)

		print "Connection to rabbitMQ broker succeeded."
		#Load all of the existing registered node queues
		with open('registrations/nodes.txt','r') as nodes:
			for line in nodes:
				info = line.strip().split(":")
				self.channel.queue_declare(info[1])

		#declare the default queues
		queue_list = ["incoming","registration","util"]
		for queueName in queue_list:
			self.channel.queue_declare(queueName)

		#Start consuming things from the incoming queue
		self.channel.basic_consume(self.gotPacket,queue='incoming')


	def gotPacket(self,ch,method,props,body):
		try:
			header = get_header(body)
		except Exception as e:
			print str(e)
			ch.basic_ack(delivery_tag = method.delivery_tag)
			return
		if(header['r_uniqid'] == 0): # If the message is intended for the cloud...
			msg_type = chr(header["msg_mj_type"]),chr(header["msg_mi_type"])
			#Figure out which queue this message belongs in.
			msg_dest = self.routeQueues.get(msg_type[0],'invalid')

			if(msg_dest == 'invalid'):
				ch.basic_ack(delivery_tag = method.delivery_tag)
				return
			self.channel.basic_publish(exchange='internal',routing_key=msg_dest, body=body)
			ch.basic_ack(delivery_tag=method.delivery_tag)

		else: # This is a message for someone else. Send it along.
			try:
				recipient = self.routing_table[header['r_uniqid']]
				self.channel.basic_publish(exchange='internal', routing_key = recipient, body=body)
			except Exception as e:
				print str(e)
			finally:
				ch.basic_ack(delivery_tag =method.delivery_tag)




	def run(self):
		self.channel.start_consuming()

	def join(self):
		super(WaggleRouter,self).terminate()
		self.rabbitConn.close()


