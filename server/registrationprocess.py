# registrationprocess.py
import sys
sys.path.append("..")
sys.path.append("/usr/lib/waggle/")
from multiprocessing import Process, Manager
import pika
from protocol.PacketHandler import *
import logging
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)

class RegProcess(Process):
	"""
		This process handles all registration requests.
		It is responsible to receiving all requests, updating the routing table,
		and writing the routing information to a permanent file.
	"""


	def __init__(self,routing_table):
		"""
			Starts up the Registration Process
		"""
		super(RegProcess,self).__init__()
		self.routing_table = routing_table

		# Set up the Rabbit connection
		self.connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
		self.channel = self.connection.channel()
		self.channel.basic_qos(prefetch_count=1)
		# Declare this process's queue
		self.channel.queue_declare("registration")
		self.channel.basic_consume(self.callback, queue='registration')

	def callback(self,ch,method,props,body):
		print ("Received a registration request.")

		# Unpack the header and see if it is already registered
		header,msg = unpack(body)
		if header["s_uniqid"] in self.routing_table:
			pass
		else:
			print "Registering new node."
			# Add the node to the registration file and make and bind its queue
			with open('registrations/nodes.txt','a+') as nodeList:
				nodeList.write("{}:{}\n".format(str(header["s_uniqid"]),msg))
			self.channel.queue_declare(msg)
			self.channel.queue_bind(exchange='internal',queue=msg,routing_key=msg)
			self.routing_table[header["s_uniqid"]] = msg

		# Send the node a registration confirmation.
		resp_header = {
				"msg_mj_type" : ord('r'),
				"msg_mi_type" : ord('c'),
				"r_uniqid"    : header["s_uniqid"],
				"resp_session": header["snd_session"]
		}
		msg = "Congratulations node {}! You are registered under the queue {}!".format(header["s_uniqid"],msg)
		for packet in pack(resp_header,msg):
			response = packet
		self.channel.basic_publish(exchange='waggle_in',routing_key="in",body=response)
		ch.basic_ack(delivery_tag = method.delivery_tag)

	def run(self):
		self.channel.start_consuming()

	def join(self):
		super(RegProcess,self).terminate()
		self.connection.close()
