#!/usr/bin/env python3

import sys
import serial
import time
import os
from tinydb import TinyDB, Query

DEVICE = "/dev/waggle_coresense"
ready = 1

DATABASE_NAME = 'coresense_db.json'
START_DIGIT = 200

db = TinyDB(DATABASE_NAME)

def get_three_digits(db, mac, three_digits=-1):
    device = Query()
    ret = db.search(device.mac == mac)
    if ret == []:
        digits = Query()
        if three_digits != -1:
            ret2 = db.search(digits.digits == three_digits)
            if ret2 == []:
                db.insert({'mac':mac, 'digits':three_digits})
                return three_digits
            else:
                return -1
        else:
            ret2 = db.search(digits.digits >= START_DIGIT)
            print(ret2)
            l = len(ret2)
            three_digits = l + START_DIGIT
            
            while True:
                ret2 = db.search(digits.digits == three_digits)
                if ret2 == []:
                    db.insert({'mac':mac, 'digits':three_digits})
                    break
                else:
                    three_digits += 1
            return three_digits
    else:
        # something is wrong
        if len(ret) != 1:
            return -1

        return ret[0]['digits']

def close_db(db):
    if db:
        db.close()

def print_db(db):
    return db.all()


print('Usage python3 getmac.py [OPTION]')
print('For option; python3 getmac.py output')
print('              creates out.csv of records in the database')

if len(sys.argv) == 2:
    try:
        with open('out.csv', 'w') as file:
            records = print_db(db)
            for record in records:
                file.write('%03d, %s\n' % (record['digits'], record['mac']))
            file.flush()
    except Exception as e:
        print('[ ERROR ] Print failed: %s' % str(e))
    exit(1)

print('[ INFO  ] Looking for coresense boards...')
while 1:
    try:
        if os.path.exists(DEVICE):
            if ready == 1:
                print('[ INFO  ] Board found!')
                ready = 0
                time.sleep(1)
                os.system("make program >> /dev/null")
                time.sleep(3)
                macaddr = ''
                ser = serial.Serial(DEVICE,115200)  # open serial port
                macaddr=ser.readline().strip()
                macaddr=ser.readline().strip()
                ser.close()
                try:
                    macaddr = macaddr.decode()
                except:
                    pass

                if macaddr != '':
                    while True:
                        id_num = input('Please 3 digit ID:') #check if this is valid number
                        if id_num == '':
                            id_num = -1
                            break
                        else:
                            try:
                                id_num = int(id_num)
                                if id_num > 999:
                                    print('[ ERROR ] Please enter three digits!')
                                else:
                                    break
                            except:
                                print('[ ERROR ] Cannot parse %s' % id_num)
                                pass

                    ret = get_three_digits(db, macaddr, id_num)
                    if ret == -1:
                        print('Error: failed to insert %s into database' % macaddr)
                    else:
                        if id_num != ret:
                            print('[WARNING] %s has been assigned to %d' % (macaddr, ret))
                        else:
                            print('[ INFO  ] %s is assigned to %d' % (macaddr, ret))
                        print('[ INFO  ] Please unplug the coresense board.')
        else:
            ready = 1

        time.sleep(1)
    except KeyboardInterrupt:
        break
close_db(db)