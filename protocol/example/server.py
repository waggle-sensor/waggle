import pika

from src.cli import command_line

from src.handle_message import handle_message

class Server:
    def __init__(self, config):
        self.config = config

        self.connection = pika.SelectConnection(
            pika.ConnectionParameters(
                host = 'localhost',
                port = config["port"]
            ),
            on_open_callback = self.with_connection
        )

    def with_connection(self, connection):
        connection.channel(on_open_callback = self.with_channel)

    def with_channel(self, channel):
        self._channel = channel

        # exchange for incoming messages
        exchange = channel.exchange_declare(
            callback = self.with_exchange,
            exchange = self.config["exchange"],
            exchange_type = 'fanout'
        )

        # exchange for outgoing messages (responses).
        inbox = channel.exchange_declare(
            callback = self.empty,
            exchange = self.config["exchange"] + "-inbox",
            exchange_type = "direct"
        )

    def with_exchange(self, exchange):
        print "listen on " + self.config["exchange"] + " exchange."
        self._channel.queue_declare(
            callback = self.empty,
            queue = self.config["exchange"]
        )

        self._channel.queue_bind(
            callback = self.with_queue,
            queue = self.config["exchange"],
            exchange = self.config["exchange"],
        )

    def with_queue(self, queue):
        print "start consuming from incoming queue"
        self._channel.basic_consume(
            consumer_callback = self.respond,
            queue = self.config["exchange"]
        )

    def respond(self, channel, method, properties, body):
        print "publish response"
        channel.basic_publish(
            exchange = self.config["exchange"] + "-inbox",
            routing_key = method.routing_key,
            body = handle_message(body)
        )
        channel.basic_ack(delivery_tag = method.delivery_tag)

    def empty(self, x):
        pass

    def start(self):
        self.connection.ioloop.start()

    def stop(self):
        pass

if __name__ == '__main__':
    command_line(
        callback = lambda config: Server(config).start(), 
        description = 'Run the Waggle server'
    )