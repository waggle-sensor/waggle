"""
	This module sets up and runs the waggle server.
"""
import pika
from WaggleRouter import WaggleRouter
from utilitiesprocess import UtilProcess
from multiprocessing import Manager
from registrationprocess import RegProcess
from dataprocess import DataProcess
import time
# Queues and exchanges the server will always need.
exchage_list = ["waggle_in","internal"]

# Permanant queue bindings
queue_bindings = {
	"incoming"     : ("waggle_in","in"),
	"registration" : ("internal","registration"),
	"util"         : ("internal","util"),
	"data"         : ("internal","data")
}

# Create a manager to handle some shared memory, like the routing table.
manager = Manager()
#The shared routing table that all routers use
routing_table = manager.dict()


# Add node queue bindings that are already registered
with open('registrations/nodes.txt') as file_:
	for line in file_:
		line = line[:-1] #Cut off the newline character
		info = line.split(":")
		queue_bindings[info[1]] = ("internal",info[1])
		routing_table[int(info[0])] = info[1]

#Connect to rabbitMQ
rabbitConn = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
rabbitChannel = rabbitConn.channel()

#Declare all of the appropriate exchanges, queues, and bindings

for queueName in queue_bindings.keys():
	rabbitChannel.queue_declare(queueName)

for exchName in exchage_list:
	rabbitChannel.exchange_declare(exchName)
for key in queue_bindings.keys():
	bind = queue_bindings[key]
	rabbitChannel.queue_bind(exchange=bind[0], queue=key, routing_key=bind[1])


#start the processes
router = WaggleRouter(routing_table)
router.start()
print("Router online.")

util = UtilProcess()
util.start()
print("Utility process online.")

reg = RegProcess(routing_table)
reg.start()
print("Registration process online.")

data = DataProcess()
data.start()
print("Data process online.")




print("All processes online. Server is fully operational.")

# Make sure all the processes stay alive. This will be
# cleaned up once all the processes are complete, including
# having Cassandra running.
while True:
	if not router.is_alive():
		print "The router has died. RIP In Peace."
		print "Attempting to bring it back from the dead..."
		router = WaggleRouter(routing_table)
		router.start()
		print "The router has risen from the grave!"

	if not util.is_alive():
		print "The utilProcess has died. RIP In Peace."
		print "Attempting to bring it back from the dead..."
		util = UtilProcess()
		util.start()
		print "The utilProcess has risen from the grave!"

	if not reg.is_alive():
		print "The registrar has died. RIP In Peace."
		print "Attempting to bring it back from the dead..."
		reg = RegProcess(routing_table)
		reg.start()
		print "The registrar has risen from the grave!"

	if not data.is_alive():
		print "The data process has died. RIP In Peace."
		print "Attempting to bring it back from the dead..."
		data = DataProcess()
		data.start()
		print "The router has risen from the grave!"

	time.sleep(3)

data.join()
reg.join()
util.join()
router.join()
print("Server has shut down cleanly.")
