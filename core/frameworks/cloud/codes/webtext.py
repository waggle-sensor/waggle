#!/usr/bin/env python2.7
from commands import getoutput as bash
from os.path import isfile
from waggle.common.messaging_d import *
from datetime import datetime
import operator
import re
import linecache
import time
from localconfig import *

sensors_list = ["BMP180.Bosch.2_5-2013","D6T-44L-06.Omron.2012","DS18B20.Maxim.2008","GA1A1S201WP.Sharp.2007","HIH4030.Honeywell.2008","HIH6130.Honeywell.2011","HMC5883.Honeywell.2013","HTU21D.MeasSpec.2013","MAX4466.Maxim.2001","MLX90614ESF-DAA.Melexis.008-2013","MMA8452Q.Freescale.8_1-2013","PDV_P8104.API.2006","RHT03.Maxdetect.2011","SHT15.Sensirion.4_3-2010","SHT75.Sensirion.5_2011","TMP102.Texas_Instruments.2008","TMP421.Texas_Instruments.2012","Thermistor_NTC_PR103J2.US_Sensor.2003"]
sensor_current_data=["BMP180.Bosch.2_5-2013","D6T-44L-06.Omron.2012","DS18B20.Maxim.2008","GA1A1S201WP.Sharp.2007","HIH4030.Honeywell.2008","HIH6130.Honeywell.2011","HMC5883.Honeywell.2013","HTU21D.MeasSpec.2013","MAX4466.Maxim.2001","MLX90614ESF-DAA.Melexis.008-2013","MMA8452Q.Freescale.8_1-2013","PDV_P8104.API.2006","RHT03.Maxdetect.2011","SHT15.Sensirion.4_3-2010","SHT75.Sensirion.5_2011","TMP102.Texas_Instruments.2008","TMP421.Texas_Instruments.2012","Thermistor_NTC_PR103J2.US_Sensor.2003"]



def nullify(a):
    if a == '':
        return "none"
    return a

def to_easy_parse_string(payload, delim = " ; "):
    data = payload._convert_to_list()
    rv = ','.join([str(data[1]), str(data[2])] + [';'.join([data[3][i], data[5][i], data[6][i], nullify(data[7][i])]) for i in xrange(len(data[3]))])
    return rv + "\n"

def num_lines_to_process():
    # Get number of lines that have been processed
    num_lines = int(bash("cat /tmp/wag/lines_processed.in"))
    return num_lines


def safe_string(a):
    # Remove any potentially harmful characters from a string
    return re.sub("[^0-9A-Za-z_]", "", a)


def update_current(payload):
    # Update current values of a sensor
    file_location = WORKING_CACHE_DIR + payload.inst_id + ".in"
    current_values = read_current(file_location)

    for i in xrange(len(payload.data_name)):
        keys = (payload.sens_id, payload.data_name[i])
        value = (payload.read_tm, payload.data_type[i], payload.data_valu[i],
                                  payload.data_unit[i], payload.data_note[i])

        update_value(current_values, keys, value)
    write_current(file_location, current_values)


def read_current(file_location):
    # Read the current values at a given file location
    if not isfile(file_location):
        write_current(file_location, dict())
    f = open(file_location, 'r')
    values = f.readline()
    return eval(values)


def write_current(file_location, values):
    # Write the current values to a given file location
    f = open(file_location, 'w')
    f.write(repr(values))

def update_value(dic, keys, value):
    # Update a key/value pair based on time
    if keys[0] in dic:
        if keys[1] in dic[keys[0]]:
            old_value = dic[keys[0]][keys[1]]
            if value[0] > old_value[0]:
                dic[keys[0]][keys[1]] = value
        else:
            dic[keys[0]][keys[1]] = value
    else:
        dic[keys[0]] = dict()
        dic[keys[0]][keys[1]] = value


def log_payload(payload):
    bash("mkdir -p " + WWW_PREFIX + payload.inst_id)
    f = open(WWW_PREFIX + payload.inst_id +"/Waggle_" + filename_timestamp(payload.read_tm) + ".txt", 'a')
    payload.read_tm = pretty_time(payload.read_tm)
    f.write(to_easy_parse_string(payload))

def filename_timestamp(time):
    # Convert a time into a date
    a = datetime.utcfromtimestamp(time)
    return a.strftime("%m-%d-%y-%H")


def pretty_time(time):
    a = datetime.utcfromtimestamp(time)
    return a.strftime("%m/%d/%y %H:%M:%S")


def gen_page(inst_id):
    cfg = read_current(WORKING_CACHE_DIR + payload.inst_id + ".in")
    f = open(WWW_PREFIX + inst_id + "/current.txt", 'w')
    touch(WWW_PREFIX + inst_id)

    iid = "Instance ID = " + inst_id

    f.write("/" + "-" * len(iid) + "--\\\n")
    f.write("| " + iid + " |\n")
    f.write("\\" + "-" * len(iid) + "--/\n\n")

    first = True
    for sens_id in sorted(cfg.keys(), key=lambda k: k.lower()):
        if not first:
            f.write("\n" + ("#" * 40) + "\n")
        else:
            first = False
        f.write("\nSensor ID = " + sens_id + ":\n\n")
        values = sorted(cfg[sens_id].iteritems(), key=lambda k: k[0].lower())

        f.write(indented(table([
                                ([tup[0] for tup in values], "Value Name", "<"),
                                ([pretty_time(tup[1][0]) for tup in values], "Read Time", "<"),
                                ([tup[1][2] for tup in values], "Value", ">"),
                                ([tup[1][3] for tup in values], "Unit", ">"),
                                ([tup[1][4] for tup in values], "Note", "<")
                               ])))


def touch(inst_id):
    bash("touch " + inst_id)


def file_len(fname):
    with open(fname) as f:
        try:
            for i, l in enumerate(f):
                pass
            return i + 1
        except:
            return 0
    return 0

on_break = False
sleep_time = 1.0
i = 0

#create local directory if not present.
bash('mkdir '+LOCAL_DIR)
bash('mkdir '+WORKING_CACHE_DIR)
bash('touch '+SENSOR_DATA_EXCHANGE_FILE)

while 1:
    #checking how many lines have been processed
    try:
        linecache.checkcache(COUNTER_FILE)
        lines_proc = int(linecache.getline(COUNTER_FILE, 1))
    except:
        bash("echo '0' > /tmp/wag/lines_processed.in")
        lines_proc = 0

    totalData = file_len(SENSOR_DATA_EXCHANGE_FILE)
    linesToProcess = max(totalData - lines_proc, 0)
    print linesToProcess, lines_proc
    if linesToProcess > 0:
        rawHandler = open(SENSOR_DATA_EXCHANGE_FILE,'r')
        #do not process already processed lines, seek the appropriate line.
        for i in range(lines_proc):
            rawHandler.readline()

        for i in xrange(linesToProcess):
            line = rawHandler.readline().split('\n')[0]
            lines_proc = lines_proc + 1
            msg = Message.decode(line)
            if int(msg.header.message_type) == DataPayload.PAYLOAD_ID:
                for payload in msg.payloads:
                    payload.inst_id = safe_string(payload.inst_id)
                    bash("mkdir -p" + WWW_PREFIX + str(payload.inst_id))
                    update_current(payload)
                    log_payload(payload)

            if lines_proc % 10000 == 0:
                print linesToProcess,lines_proc,time.asctime()
                f = open(COUNTER_FILE, 'w')
                f.write(str(lines_proc))
                f.close()
        f = open(COUNTER_FILE, 'w')
        f.write(str(lines_proc))
        f.close()
    else:
        time.sleep(1)
