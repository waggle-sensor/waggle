FROM ubuntu:14.04

RUN apt-get update ; apt-get install -y git \
  rabbitmq-server python-dev python-pip

RUN cd / ; git clone https://github.com/waggle-sensor/waggle.git
# TODO: replace "git clone" with "ADD" this later
# e.g. ADD . /beehive

RUN cd /waggle/server && ./configure

