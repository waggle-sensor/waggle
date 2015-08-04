# utilitiesprocess.py
import sys
sys.path.append("..")
sys.path.append("/usr/lib/waggle/")
from multiprocessing import Process, Manager
import pika
from protocol.PacketHandler import *
import logging
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)

class UtilProcess(Process):
	"""
		This class handles the processing of several types of utility requests that nodes can
		send to the server.
	"""

	def __init__(self):
		"""
			Initializes the utility process
		"""
		super(UtilProcess,self).__init__()

		#Make the connection to RabbitMQ
		self.connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
		self.channel = self.connection.channel()
		self.channel.basic_qos(prefetch_count=1)
		# Declare the relevant incoming queue and exchange
		self.channel.queue_declare("util")
		self.channel.exchange_declare("waggle_in")
		self.channel.basic_consume(self._callback, queue = 'util')

	def _callback(self,ch,method,props,body):
		"""
			Called when a packet contianing a utility request is recieved
		"""
		#Here body is our full packet - header, message and CRC, and one can technically
		#throw this back in the waggle_in and get it routed again.
		header = get_header(body)


		if(header['msg_mj_type'] == ord('p') and header["msg_mi_type"] == ord('r')): # It's a ping request
			#Create a response header
			resp_header = {
				"msg_mj_type" : ord('p'),
				"msg_mi_type" : ord('a'),
				"r_uniqid"    : header["s_uniqid"],
				"resp_session": header["snd_session"]
			}
			packer = pack(resp_header,"Pong!")
			# Need to use a for each loop because packer yields packets, it doesnt return them
			for packet in packer:
				response = packet
			self.channel.basic_publish(exchange='waggle_in', routing_key = "in", body=response)


		elif(header['msg_mj_type'] == ord('t') and header["msg_mi_type"] == ord('r')): # It's a time request
			# Make a response header
			resp_header = {
				"msg_mj_type" : ord('t'),
				"msg_mi_type" : ord('a'),
				"r_uniqid"    : header["s_uniqid"],
				"resp_session": header["snd_session"]
			}
			packer = pack(resp_header,str(time.time())) # Stuff the time in a packet and send it to the router
			for packet in packer:
				response = packet
			self.channel.basic_publish(exchange='waggle_in',routing_key="in",body=response)
		ch.basic_ack(delivery_tag = method.delivery_tag)



	def run(self):
		self.channel.start_consuming()

	def join(self):
		super(UtilProcess,self).terminate()
		self.connection.close()