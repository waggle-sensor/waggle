#!/bin/sh
python3 fetch-beehive-data.py $1 $2 | grep -E ',alpha|,HTU21D,|,BMP180,Atm'
