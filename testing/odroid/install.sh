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

./install-stress-ng.sh


# install label_printing

git clone https://github.com/waggle-sensor/label_printing.git
cd label_printing/
./install.sh

cd ${CURRENT_DIR}

# reconfigure udev rules

sed -e "s:\[% SCRIPT %\]:`pwd`/print_status.sh:" label_printing/75-Dymo-LabelWriter-450.rules_template > /etc/udev/rules.d/75-Dymo-LabelWriter-450.rules


sed -e "s:\[% SCRIPT %\]:`pwd`/label_printing/print_mac.sh:" print_status.sh_tmpl > print_status.sh
chmod +x print_status.sh


### TODO: write print_status.sh
