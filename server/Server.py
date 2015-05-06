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

# The number of processes of each type to run on this server instance
NUM_ROUTER_PROCS = 1
NUM_DATA_PROCS = 1
NUM_REGISTRATION_PROCS = 1
NUM_UTIL_PROCS = 1

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
		if line and line != '\n':
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
router_procs = []
for i in range (0,NUM_ROUTER_PROCS):
	new_router = WaggleRouter(routing_table)
	new_router.start()
	router_procs.append(new_router)
print "Routing processes online."

util_procs = []
for i in range (0,NUM_UTIL_PROCS):
	new_util = UtilProcess()
	new_util.start()
	util_procs.append(new_util)
print "Utility processes online."

reg_procs = []
for i in range (0,NUM_REGISTRATION_PROCS):
	new_reg = RegProcess(routing_table)
	new_reg.start()
	reg_procs.append(new_reg)
print "Registration processes online."

data_procs = []
for i in range (0,NUM_DATA_PROCS):
	new_data = DataProcess()
	new_data.start()
	data_procs.append(new_reg)
print "Data forwarding processes online."




print("All processes online. Server is fully operational.")



# Future work: This is where server commands should be processed.
# This could be accomplished by reading from something like a multiprocessing queue
# and then performing whatever needs to be done right here.
# A separate command-line process might be a good way to do this, making sure that
# it has sole control over standard in/out.
while True:
	for i in range(0,len(router_procs)):
		if not router_procs[0].is_alive():
			new_router = WaggleRouter(routing_table)
			router_procs[i] = new_router
	for i in range(0,len(data_procs)):
		if not data_procs[i].is_alive():
			new_data = DataProcess()
			data_procs[i] = new_data

	for i in range(0,len(reg_procs)):
		if not reg_procs[i].is_alive():
			new_reg = RegProcess(routing_table)
			reg_procs[i] = new_reg

	for i in range(0,len(util_procs)):
		if not util_procs[i].is_alive():
			new_util = UtilProcess()
			util_procs[i] = new_util

	time.sleep(3)
