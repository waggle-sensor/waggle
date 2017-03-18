#!/bin/bash

set -x
set -e

CURRENT_DIR=$(pwd)


if [ ! -e ${CURRENT_DIR}/stress-test.sh_tmpl ] ; then
  echo "${CURRENT_DIR}/stress-test.sh_tmpl not found"
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

./configure.sh

