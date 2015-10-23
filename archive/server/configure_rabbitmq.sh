#!/bin/bash

set -e
set -x 

if [ $(service rabbitmq-server status 2&>1 /dev/null  ; echo $? ) != 0 ] ; then 
  service rabbitmq-server start
fi


# Create a user that all nodes can use to send info to.
# Feel free to fiddle with rabbitmq if you want to have other users and accounts.
if [ $(rabbitmqctl list_users | grep -c waggle) -eq 0 ] ; then 
  echo "add waggle user"  
  rabbitmqctl add_user waggle waggle
  rabbitmqctl set_permissions waggle ".*" ".*" ".*"
fi

