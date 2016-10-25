#!/bin/bash

set -x
set -e

CURRENT_DIR=$(pwd)


if [ ! -e ${CURRENT_DIR}/stress-test.sh ] ; then
  echo "${CURRENT_DIR}/stress-test.sh not found"
  echo "please run install.sh in the same directory where stress-test.sh is installed."
  exit 1
fi


sed -e 's:\[location\]:'${CURRENT_DIR}'/:' stress-test.conf_tmpl > /etc/init/stress-test.conf
sed -e 's:\[location\]:'${CURRENT_DIR}'/:' stress-timeout.conf_tmpl > /etc/init/stress-timeout.conf

./install-stress-ng.sh


# install label_printing

if [ -e label_printing ] ; then
  cd label_printing
  git pull
else
  git clone https://github.com/waggle-sensor/label_printing.git
  cd label_printing/
fi

./install.sh

cd ${CURRENT_DIR}

# reconfigure udev rules

#sed -e "s:\[% SCRIPT %\]:`pwd`/print_status.sh:" label_printing/75-Dymo-LabelWriter-450.rules_template > /etc/udev/rules.d/75-Dymo-LabelWriter-450.rules

#RUNNING_TIME=180
RUNNING_TIME=60
sed -e "s:\[% RUN_DURATION %\]:${RUNNING_TIME}:" stress-test.sh_tmpl > stress-test.sh
chmod +x stress-test.sh

# WAIT_TIME=360
WAIT_TIME=120
sed -e "s:\[% WAIT_DURATION %\]:${WAIT_TIME}:;s:\[% SCRIPT %\]:`pwd`/label_printing/print_mac.sh:" stress-timeout.sh_tmpl > stress-timeout.sh
chmod +x stress-timeout.sh

sed -e "s:\[% SCRIPT %\]:`pwd`/label_printing/print_mac.sh:" print_status.sh_tmpl > print_status.sh
chmod +x print_status.sh


### TODO: write print_status.sh
