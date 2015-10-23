#!/bin/bash

set -e
set -x 


# Set up the SSL files, and generate a new SSL Certificate Authority
# For the Certificate Authority setup, see waggle/server/SSL/caconfig.sh
echo Setting up SSL
mkdir -p /usr/lib/waggle/SSL
cp -r /usr/lib/waggle/server/SSL/* /usr/lib/waggle/SSL
cd /usr/lib/waggle/SSL/
source caconfig.sh

chmod 777 -R /usr/lib/waggle

