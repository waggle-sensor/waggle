# dataprocess.py

import sys
sys.path.append("..")
sys.path.append("/usr/lib/waggle/")
from multiprocessing import Process, Manager
import pika
from protocol.PacketHandler import *
from utilities.gPickler import *
import logging
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)
from cassandra.cluster import Cluster

CASSANDRA_IP = 'localhost'

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
		self.channel.basic_qos(prefetch_count=1)
		# Declare this process's queue
		self.channel.queue_declare("data")
		self.channel.basic_consume(self.callback, queue='data')
		# Set up the Cassandra connection
		print "Connected to cassandra."

	def callback(self,ch,method,props,body):
		print "In Data Process now."
		try:
			cluster = Cluster(contact_points=[CASSANDRA_IP])
			cassandra = cluster.connect('waggle')
			header,data = unpack(body)
			data = un_gPickle(data)
			print data
			# Send the data off to Cassandra

			prepared_statement = cassandra.prepare("INSERT INTO sensor_data" + \
				" (node_id, sensor_name, timestamp, data_types, data, units, extra_info)" + \
				" VALUES (?, ?, ?, ?, ?, ?, ?)")
			print "Binding insert statement"
			bound_statement = prepared_statement.bind([header["s_uniqid"],data[0],data[1],data[2],data[4],data[5],data[6]])
			print "Statement bound."
			cassandra.execute(bound_statement)
			print "Inserted data into Cassandra."
			cluster.shutdown()
		except Exception as e:
			print str(e)
		ch.basic_ack(delivery_tag = method.delivery_tag)

	def run(self):
		self.channel.start_consuming()

	def join(self):
		super(DataProcess,self).terminate()
		self.connection.close()