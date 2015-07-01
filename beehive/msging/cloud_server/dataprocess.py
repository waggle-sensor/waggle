# dataprocess.py

import sys
sys.path.append("../../../devtools/protocol_common")
from multiprocessing import Process, Manager
import pika
from protocol.PacketHandler import *
from utilities.gPickler import *
import logging
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)

class DataProcess(Process):
	"""
		This process handles all data submissions
	"""


	def __init__(self):
		"""
			Starts up the Data handling Process
		"""
		super(DataProcess,self).__init__()
		# Set up the Rabbit connection
		self.connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
		self.channel = self.connection.channel()

		# Declare this process's queue
		self.channel.queue_declare("data")
		self.channel.basic_consume(self.callback, queue='data')

	def callback(self,ch,method,props,body):
		try:
			data = un_gPickle(unpack(body)[1])
			print data
		except Exception as e:
			print unpack(body)[1]
		ch.basic_ack(delivery_tag = method.delivery_tag)

	def run(self):
		self.channel.start_consuming()

	def join(self):
		super(DataProcess,self).terminate()
		self.connection.close()