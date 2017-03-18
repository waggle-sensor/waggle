#!/usr/bin/env python3

import time
import subprocess

number_of_cpu = int(subprocess.getoutput('cat /proc/stat | grep -E "^cpu[0-9]" | wc -l'))

if number_of_cpu < 1:
    print('[ERROR] no cpu found!')
    exit(1)

class mali_gpu(object):
    def __init__(self, name):
        self.name = name

    def get_name(self):
        return self.name

    def get_usage(self):
        return subprocess.getoutput('cat /sys/devices/11800000.mali/utilization')

class cpu(object):
    def __init__(self, name, total=0, idle=0):
        self.name = name
        self.prev_total = total
        self.prev_idle = idle
        self.diff_usage = 0

    def get_usage(self):
        return self.diff_usage

    def calculate_cpu_usage(self, total, idle):
        diff_total = total - self.prev_total
        diff_idle = idle - self.prev_idle
        self.diff_usage = round((1000 * (diff_total - diff_idle) / diff_total + 5) / 10)
        self.prev_total = total
        self.prev_idle = idle
        return self.diff_usage

def get_info():
    info = subprocess.getoutput('cat /proc/stat | grep -E "^cpu[0-9]"')
    ret = []
    for c in info.split('\n'):
        sp = c.split(' ')
        tt = sp[1:5]
        total = sum(int(t) for t in tt if t.isdigit())
        idle = int(sp[4])
        ret.append([sp[0], total, idle])
    return ret

info = get_info()
cpus = {c[0]:cpu(c[0], 0, 0) for c in info}
gpus = [mali_gpu('Mali T-628')]
sleep_time = 1

try:
    while True:
        info = get_info()
        line = time.strftime("%Y %m %d %H:%M:%S %Z", time.localtime(time.time()))
        for cpu_name, total, idle in info:
            usage = cpus[cpu_name].calculate_cpu_usage(total, idle)
            line += ',' + cpu_name + ':' + str(usage)

        for gpu in gpus:
            line += ',' + gpu.get_name() + ':' + gpu.get_usage()

        #line += '\n'
        #subprocess.call(['echo', '-p', line, '>>', 'result.log'])
        print(line, file=open('result.log', 'a'))
        time.sleep(sleep_time)
except:
    pass
