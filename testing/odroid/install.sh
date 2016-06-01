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