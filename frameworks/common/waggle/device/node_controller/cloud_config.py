#!/usr/bin/env python

# A data client that connects to the RabbitMQ Weather queue

# RabbitMQ Connection information
rmq_ip = "140.221.14.151"
rmq_port = 23181
rmq_user = 'honeybee'
rmq_passwd = 'buzz'
rmq_exchange = ''
rmq_routing_key = 'weather'

# Packaged into one variable
CLOUD_SERVER_INFO = (rmq_ip, rmq_port, rmq_user, 
                     rmq_passwd, rmq_exchange, rmq_routing_key)
