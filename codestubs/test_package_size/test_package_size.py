#!/usr/bin/env python
import logging
import pika
import time
import os
import socket
import uuid
import psutil

logging.basicConfig()


class TestPackageSizeClient:

    def __init__(self, RMQ_ip, port, user, passwd, exch, rout_key):
        """ Initializer of data client, all parameters needed to be filled so to access the remote server. Please see example at the bottom for use.
        """
        self.RMQHost = RMQ_ip
        self.RMQPort = int(port)
        self.RMQUser = user
        self.RMQPassWd = passwd
        self.RMQExchange = exch
        self.RMQRoutingKey = rout_key
        credentials = pika.PlainCredentials(self.RMQUser, self.RMQPassWd) #'clients','Ruza3que'
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(host = self.RMQHost, port = self.RMQPort, credentials= credentials)) #host='192.168.1.29', port= 5672
        self.channel = self.connection.channel()
        #self.channel.queue_declare(queue = self.RMQRoutingKey) #'hello'
    
    def send(self, msg):
        self.channel.basic_publish(exchange = self.RMQExchange,
                                   routing_key = self.RMQRoutingKey,
                                   body = msg)
   

    def close(self):
        """ 
        Close connection. Call this after you finish use client to save server side resource.
        You need to recreate the DataClient object to send data if you called this, so put this at the end of your logic session.

        Note: you may get warning like this:
        WARNING:pika.adapters.base_connection:Unknown state on disconnect: 0
        This is due to a known pika bug, the warning is printed when connection.close() is called, but won't affect the behavior of the program.
        """
        self.connection.close()
   
def memory_usage_psutil():
    process = psutil.Process(os.getpid())
    mem = process.get_memory_info()[0] / float(2 ** 20)
    return mem


#============================================================
if __name__ == "__main__":
    #Test case and example
    RMQ_ip = '149.165.149.8'
    RMQ_port = 5672
    RMQ_user = 'clients'
    RMQ_passwd = 'Ruza3que'
    RMQ_exchange = ''
    RMQ_routing_key = 'sizeTest'
    client = TestPackageSizeClient(RMQ_ip, RMQ_port, RMQ_user, RMQ_passwd, RMQ_exchange, RMQ_routing_key)
    
    for i in range(1, 20):
        msg = "F" * 256 * (2**i)
        print "sending message of size: ", len(msg), " memory usage is: ", client.memory_usage_psutil(), "MB"
        time.sleep(5)
        client.msg_send(msg)
    
    client.connection.close()
