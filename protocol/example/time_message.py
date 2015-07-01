#!/usr/bin/env python

import pika
import time

from src.cli import command_line
from src.message import Message
from src.message_type import MessageType
from src.session import Session
from src.spec import spec

def with_channel(config, channel):
    inbox_id = str(config["id"]) + '-in'
    inbox = channel.queue_declare(
        callback = lambda x: x,
        queue = inbox_id
    )

    message = Message(
        payload = '',
        message_type = spec.message_type["request_current_time"],
        timestamp = int(time.time()),
        sender_session = Session(
            session_number = config["session_number"],
            sequence_number = 1,
            id = config["id"]
        ),
        # we don't know the recipient session number or sequence number,
        # so we set them to zero.
        recipient_session = Session(
            session_number = 0,
            sequence_number = 0,
            id = 0
        )
    )

    # receive responses
    channel.queue_bind(
        callback = with_queue,
        queue = inbox_id,
        exchange = config["exchange"] + "-inbox",
        routing_key = str(config["id"])
    )

    # Consume messages from the callback queue.
    channel.basic_consume(
        handle_response,
        queue   = inbox_id
    )

    # Send a message
    channel.basic_publish(
        exchange = config["exchange"],
        routing_key = str(config["id"]),
        body = message.serialize()
    )

def with_connection(config, connection):
    connection.channel(
        on_open_callback = lambda channel: with_channel(config, channel)
    )

def with_queue(queue):
    pass

def main(config):
    # Establish an SSL connection with the RabbitMQ broker.
    connection = pika.SelectConnection(
        pika.ConnectionParameters(
            host = 'localhost', # set to the actual host in production
            port = config["port"]
        ),
        on_open_callback = lambda conn: with_connection(config, conn)
    )

    connection.ioloop.start()

def handle_response(channel, method, props, body):
    print Message.parse(body).payload
    channel.basic_ack(delivery_tag = method.delivery_tag)

if __name__ == '__main__':
    command_line(main, 'Run the Waggle client.')
