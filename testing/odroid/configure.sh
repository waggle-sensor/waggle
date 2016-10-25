#!/bin/bash

CURRENT_DIR=$(pwd)

if [ ! -e ${CURRENT_DIR}/label_printing/print_mac.sh ] ; then
  echo "label printing script does not exist"
  echo "please install label_printing first"
  exit 1
fi

RUNNING_TIME=180
sed -e "s:\[% RUN_DURATION %\]:${RUNNING_TIME}:" stress-test.sh_tmpl > stress-test.sh
chmod +x stress-test.sh

WAIT_TIME=360
sed -e "s:\[% WAIT_DURATION %\]:${WAIT_TIME}:;s:\[% SCRIPT %\]:`pwd`/label_printing/print_mac.sh:" stress-timeout.sh_tmpl > stress-timeout.sh
chmod +x stress-timeout.sh

sed -e "s:\[% SCRIPT %\]:`pwd`/label_printing/print_mac.sh:" print_status.sh_tmpl > print_status.sh
chmod +x print_status.sh


### TODO: write print_status.sh
