#!/bin/bash
CAMERA_IP=10.10.10.128
OUT_DIR=./
OUT_FILE="${OUT_DIR}/recording.`date +%Y.%m.%d.%M.%S`.mp4"

ffmpeg -i rtsp://${CAMERA_IP} -r 25 ${OUT_FILE}