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
import time

with open('/etc/waggle/cassandra_ip','r') as f:
	CASSANDRA_IP = f.read().strip()

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
		self.session = None
		self.cluster = None

	def callback(self,ch,method,props,body):
		try:
			header,data = unpack(body)
			data = un_gPickle(data)
			# Send the data off to Cassandra
			self.cassandra_insert(header,data)
			ch.basic_ack(delivery_tag=method.delivery_tag)
		except Exception as e:
			# Cassandra isn't connected or something. Shove it back in the queue for another process
			# Then try to re-establish a connection
			ch.basic_nack(delivery_tag=method.delivery_tag)
			print "Cassandra connection failed. Attempting to reconnect..."
			# Wait a few seconds before trying to connect (to prevent this from taking up a ton of power)
			time.sleep(1)
			self.cassandra_connect()

	def cassandra_insert(self,header,data):
		try:
			prepared_statement = self.session.prepare("INSERT INTO sensor_data" + \
				" (node_id, sensor_name, timestamp, data_types, data, units, extra_info)" + \
				" VALUES (?, ?, ?, ?, ?, ?, ?)")
			bound_statement = prepared_statement.bind([header["s_uniqid"],data[0],data[1]*1000,data[2],data[4],data[5],data[6]])
			self.session.execute(bound_statement)
		except Exception as e:
			raise

	def cassandra_connect(self):
		try:
			self.cluster.shutdown()
		except:
			pass
		self.cluster = Cluster(contact_points=[CASSANDRA_IP])

		try: # Might not immediately connect. That's fine. It'll try again if/when it needs to.
			self.session = self.cluster.connect('waggle')
		except:
			print "WARNING: Cassandra connection to " + CASSANDRA_IP + " failed."
			print "The process will attempt to re-connect at a later time."

	def run(self):
		self.cassandra_connect()
		self.channel.start_consuming()

	def join(self):
		super(DataProcess,self).terminate()
		self.connection.close(0)
		self.cluster.shutdown()