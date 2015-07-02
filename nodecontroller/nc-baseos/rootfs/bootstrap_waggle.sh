#!/bin/bash

set -x
PACKAGE_LIST=(openssh-server monit nano cpuset)

ifconfig eth0 up
dhclient eth0

apt-get -y --force-yes update
apt-get -y --force-yes upgrade
apt-get -y --force-yes install ${PACKAGE_LIST[*]}

/etc/init.d/monit stop && update-rc.d -f monit remove

tar --no-same-owner -xzf init_pack.tar.gz

chmod 744 /usr/bin/waggle.py
chmod 755 /etc/monit/scripts/launch_waggle.d
chmod 600 /etc/monit/monitrc
