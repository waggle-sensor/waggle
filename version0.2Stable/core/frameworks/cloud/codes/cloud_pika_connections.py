import pika
from cloud_localconfig import *

class Consumer:
    global _connections
    pass

class Producer:
    def __init__(self, ip = BEEHIVE_IP, port = BEEHIVE_PORT, username = BEEHIVE_UNAME, password = BEEHIVE_PWD, routing_key = BEEHIVE_RTK, exchange = BEEHIVE_EXCHANGE):
        print "Producer.__init__()"

        self._ip = ip
        self._port = port
        self._username = username
        self._password = password
        self._routing_key = routing_key
        self._exchange = exchange

        self._exchange = exchange                    # needed by send
        self._routing_key = routing_key               # needed by send
        self._channel = None                         # needed by send
        self._properties = pika.BasicProperties(content_type='text/plain', delivery_mode=1)
        self.connect()


    def connect(self):
        print "Producer.connect()"
        """ Connect to the RabbitMQ server and a create a channel from that
                connection. Returns True if there were no immediate errors.
        """
        try:
            credentials = pika.PlainCredentials(self._username, self._password)
            parameters = pika.ConnectionParameters(self._ip, self._port, credentials = credentials)
            self._connection = pika.BlockingConnection(parameters)
            self._channel = self._connection.channel()
        except:
            return False
        return True


    def disconnect():
        print "Producer.disconnect()"
        """ Close the connection and the channel created from it. """
        self._channel.close()
        self._connection.close()


    def reconnect(self):
        print "Producer.reconnect()"
        """ Attempt to reconnect and restablish both the connection and the
                channel. Returns True if there were no immediate errors.
        """
        try:
            self._connection.connect()
            self._channel = self._connection.channel()
        except:
            return False
        return True


    def send(self, msg):
        print "Producer.send()"
        """ Attempt to send a message, if the connect is non-functioning, attempt
                to fix it and send the message. Returns True if there were no
                immediate errors.
            Parameters
            ----------
            msg (str): The message to send
        """
        try:
            self._send(msg)
        except (pika.exceptions.ConnectionClosed, pika.exceptions.ChannelClosed):
            try:
                self.connect()
                self._send(msg)
            except:
                return False
        return True


    def _send(self, msg):
        print "Producer._send()"
        """ Call to send a message wrapped up to be more concise.
            Parameters
            ----------
            msg (str): The message to send
        """
        return self._channel.basic_publish(self._exchange, self._routing_key,
                                           msg, properties = self._properties)

def Consume(callback, routing_key, ip = BEEHIVE_IP, port = BEEHIVE_PORT, username = BEEHIVE_UNAME, password = BEEHIVE_PWD):
    credentials = pika.PlainCredentials(username, password)
    parameters = pika.ConnectionParameters(ip, port, credentials = credentials)
    connection = pika.BlockingConnection(parameters)
    channel = connection.channel()

    channel.queue_declare(queue=routing_key) #auto_delete = true?
    channel.basic_consume(callback, queue=routing_key, no_ack = False) #no_ack?
    channel.start_consuming()
    connection.close()


def Connect(ip = BEEHIVE_IP, port = BEEHIVE_PORT, username = BEEHIVE_UNAME, password = BEEHIVE_PWD):
    credentials = pika.PlainCredentials(username, password)
    parameters = pika.ConnectionParameters(ip, port, credentials = credentials)
    connection = pika.BlockingConnection(parameters)
    channel = connection.channel()
    return channel

def Send(connection, routing_key, msg):
    properties = pika.BasicProperties(content_type='text/plain', delivery_mode=1)
    connection.basic_publish('', routing_key, msg, properties = properties)


def CreateQueue(connection, routing_key):
    connection.queue_declare(queue=routing_key)


if __name__ == "__main__":
    con = Connect(BEEHIVE_IP, BEEHIVE_PORT, BEEHIVE_UNAME, BEEHIVE_PWD)
    print con
