#!/bin/bash

set -e
set -x 

source ./requirements.sh 

if [ ${CASSANDRA_SERVER}x == "x" ] ; then
  read -p "Enter the IP address or hostname of the Cassandra server you want to use: " c_ip
else
  export c_ip=${CASSANDRA_SERVER}
fi

mkdir -p /etc/waggle/
echo $c_ip > /etc/waggle/cassandra_ip


# test if cassandra client can connect
if [ $(./cqlsh.py ${c_ip} -e "quit;" > /dev/null 2>&1 ; echo $? ) != 0 ] ; then 
  echo "error: could not connect to cassandra using address ${c_ip}."
  exit 1
fi

if [ ${REQUIRED_CASSANDRA_VERSION}x != "x" ] ; then
  export GOT_CASS_VERSION=$(./cqlsh.py cassandra -e "SELECT release_version FROM system.local" | grep -o "[0-9.]\{3,7\}")
  if [ ${REQUIRED_CASSANDRA_VERSION}x != ${GOT_CASS_VERSION}x ] ; then
    echo "error: Cassandra version ${REQUIRED_CASSANDRA_VERSION} is required. Found ${GOT_CASS_VERSION}."
    exit 1
  fi
fi



# check if tables already exist, otherwise create them
export GREP_TABLES=$(./cqlsh.py cassandra -e "use waggle; describe tables;" | grep "node_info" | grep "sensor_data" | wc -l)
if [ ${GREP_TABLES} != 1 ] ; then
  # create tables in cassandra
  ./cqlsh.py ${c_ip} -f ./waggle_cassandra_setup.cql
fi

