#!/bin/bash

DRIVER=$1
IMAGE="$2.`date +%Y.%m.%d.%H.%M`.img"

echo $IMAGE

dd if=${DRIVER} of=${IMAGE}