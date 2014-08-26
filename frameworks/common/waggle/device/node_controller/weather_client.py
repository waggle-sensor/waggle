#!/usr/bin/env python
#
# A data client that connects to the RabbitMQ Weather queue
#

from waggle.device.node_controller.data_client import NodeDataClient

# RabbitMQ Connection information
RMQ_ip = '149.165.149.3'
RMQ_port = 5672
RMQ_user = 'clients'
RMQ_passwd = 'Ruza3que'
RMQ_exchange = ''
RMQ_routing_key = 'weather'

# Set up a Data Client connection
data_client = NodeDataClient(RMQ_ip, RMQ_port, RMQ_user, 
                             RMQ_passwd, RMQ_exchange, RMQ_routing_key)

#if __name__ == "__main__":
#    print "won't show up"
#print "will show up"
