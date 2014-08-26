#!/usr/bin/env python

# A data client that connects to the RabbitMQ Weather queue

# RabbitMQ Connection information
rmq_ip = '149.165.149.8'
rmq_port = 5672
rmq_user = 'clients'
rmq_passwd = 'Ruza3que'
rmq_exchange = ''
rmq_routing_key = 'weather'

# Packaged into one variable
CLOUD_SERVER_INFO = (rmq_ip, rmq_port, rmq_user, 
                     rmq_passwd, rmq_exchange, rmq_routing_key)
