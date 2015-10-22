FROM ubuntu:14.04

RUN apt-get update ; apt-get install -y \
  rabbitmq-server python-dev python-pip

# does not really work: RUN cd / ; git clone https://github.com/waggle-sensor/waggle.git

ADD ./server /waggle/server
ADD ./devtools/protocol_common /waggle/devtools/protocol_common

# python modules
RUN cd /waggle/server/packages_o/ && \
  pip install blist && \
  pip install cassandra-driver && \
  cd pika-0.9.14/ && \
  python setup.py install

# cqlshlib for the cassandra client
RUN cd /waggle/server/cassandra-pylib/ && \
  python ./setup.py install  

ENV CASSANDRA_SERVER cassandra 


