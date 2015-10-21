FROM ubuntu:14.04

RUN apt-get update ; apt-get install -y \
  rabbitmq-server python-dev python-pip

# does not really work: RUN cd / ; git clone https://github.com/waggle-sensor/waggle.git

ADD ./server /waggle/server
ADD ./devtools/protocol_common /waggle/devtools/protocol_common

ENV CASSANDRA_SERVER cassandra 
RUN cd /waggle/server && ./configure

