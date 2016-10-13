#!/bin/bash

MODEL_REPORTED=$(cat /proc/cpuinfo | grep Hardware | grep -o "[^ ]*$")

if [ "${MODEL_REPORTED}x" == "x" ] ; then
  echo "no model detected"
  exit 1
fi


if [ "${MODEL_REPORTED}x" == "ODROIDCx" ] ; then
  ODROID_MODEL="C"
  CPU_COUNT=4
elif [ "${MODEL_REPORTED}x" == "ODROID-XU3x" ] ; then
  ODROID_MODEL="XU3"
  CPU_COUNT=8
else
  echo "Model ${MODEL_REPORTED} unknown."
  exit 1
fi

echo "ODROID_MODEL=${ODROID_MODEL}"

set -x


############################


if [ -e /run/stress.log ] ; then
  echo "/run/stress.log already exists."
  exit 1
fi




/usr/local/bin/stress-ng --cpu ${CPU_COUNT} --io 2 --vm 1 --vm-bytes 500M --timeout 180s --metrics-brief
STRESS_RESULT=$?

if [ ${STRESS_RESULT} -ne 0 ] ; then
  echo "Error: Error code: ${STRESS_RESULT}"
  echo "error" > /run/stress.log
else
  echo "success" > /run/stress.log
fi

./print_status.sh

