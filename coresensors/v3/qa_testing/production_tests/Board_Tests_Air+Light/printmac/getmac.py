#!/usr/bin/env python3

import sys
import serial
import time
import os
import argparse
from tinydb import TinyDB, Query

DEVICE = "/dev/waggle_coresense"
ready = 1

DATABASE_NAME = 'coresense_db.json'
START_DIGIT = 200

db = TinyDB(DATABASE_NAME)

def update_macaddr(db, mac, three_digits):
    digits = Query()
    ret = db.search(digits.digits == three_digits)
    if ret == []:
        return -1, mac
    def update_operation(new_value):
        def transform(element):
            element['mac'] = new_value
        return transform
    ret = db.update(update_operation(mac), digits.digits == three_digits)
    return ret[0]

def get_three_digits(db, mac, three_digits=-1):
    device = Query()
    ret = db.search(device.mac == mac)
    if ret == []:
        digits = Query()
        if three_digits != -1:
            ret2 = db.search(digits.digits == three_digits)
            if ret2 == []:
                db.insert({'mac':mac, 'digits':three_digits})
                return three_digits, mac
            else:
                return -1, ret2[0]['mac']
        else:
            ret2 = db.search(digits.digits >= START_DIGIT)
            l = len(ret2)
            three_digits = l + START_DIGIT
            
            while True:
                ret2 = db.search(digits.digits == three_digits)
                if ret2 == []:
                    db.insert({'mac':mac, 'digits':three_digits})
                    break
                else:
                    three_digits += 1
            return three_digits, mac
    else:
        # something is wrong
        if len(ret) != 1:
            return -1, ''

        return -1, ret[0]['mac']

def close_db(db):
    if db:
        db.close()

def print_db(db):
    return db.all()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Manage MAC address')
    parser.add_argument('-o', '--output', action='store', help='Export data to the output file')
    parser.add_argument('-i', '--input', action='store', help='Import data from the csv file')

    args = parser.parse_args()

    if args.output:
        try:
            with open(args.output, 'w') as file:
                records = print_db(db)
                records = sorted(records, key=lambda k: k['digits'])
                for record in records:
                    file.write('%03d, %s\n' % (record['digits'], record['mac']))
                file.flush()
        except Exception as e:
            print('[ ERROR ] Export failed: %s' % str(e))
        print('[ INFO  ] Export done.')
        exit(1)
    elif args.input:
        try:
            if not os.path.isfile(args.input):
                print('[ ERROR ] input file not found')
                exit(1)
            with open(args.input, 'r') as file:
                for line in file:
                    try:
                        digits, macaddr = line.strip().split(',')
                        digits = int(digits.strip())
                        macaddr = macaddr.strip()
                        ret, ret_macaddr = get_three_digits(db, macaddr, digits)
                        if ret == -1:
                            print ('[ ERROR ] %s is occupied by %s' % (digits, ret_macaddr))
                            while True:
                                answer = input('Do you still want to replace %s with %s?[y/n]' % (digits, macaddr))
                                if answer[0] == 'y' or answer[0] == 'Y':
                                    update_macaddr(db, macaddr, digits)
                                    break
                                elif answer[0] == 'n' or answer[0] == 'N':
                                    pass
                                    break
                                else:
                                    pass
                        else:
                            print('[ INFO  ] %s is assigned to %s' % (macaddr, digits))
                    except Exception as e:
                        print('[ ERROR ] Could not proceed %s:%s' % (line, str(e)))
        except Exception as e:
            print('[ ERROR ] Import failed: %s' % str(e))
        exit(1)
    else:
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