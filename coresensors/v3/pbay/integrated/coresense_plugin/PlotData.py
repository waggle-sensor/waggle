# plot data

import matplotlib.pyplot as plt
import matplotlib
import datetime as dt
import matplotlib.dates as mdates

# read line

flag_FIRST = True

i = 0
j = 0
x = []
y = []
z = []
v = []
w = []

#TITLE = "TMP112"
#TITLE = "HTU21D"
#TITLE = "BMP180"
#TITLE = "PR103J2"
#TITLE = "TSL250RD"
#TITLE = "MMA8452Q"
#TITLE = "HMC5883L"
#TITLE = "HIH6130"
#TITLE = "APDS_9006_020"
#TITLE = "TSL260RD"
#TITLE = "TSL250RD"
#TITLE = "MLX75305"
#TITLE = "ML8511"
#TITLE = "TMP421"

#TITLE = "Intel_MAC"
#TITLE = "SHT25"
#TITLE = "LPS25H"
#TITLE = "Si1145"

TITLE = "TotalReducing"
#TITLE = "TotalOxidizing"
#TITLE = "SulfurDioxide"
#TITLE = "HydrogenSulphide"
#TITLE = "Ozone"
#TITLE = "NitrogenDiOxide"
#TITLE = "CarbonMonoxide"

#TITLE = "CO_ADCtemp"
#TITLE = "IAQ_IRR_ADCtemp"
#TITLE = "O3_NO2_ADCtemp"
#TITLE = "SO2_H2S_ADCtemp"
#TITLE = "CO_LMPtemp"

#TITLE = "Accelerometer"
#TITLE = "Gyroscope"

#if TITLE == "TMP112" or TITLE == "PR103J2" or TITLE == "TSL250RD" or TITLE = "APDS_9006_020" or TITLE = "TSL260RD" or TITLE = "TSL250RD" or TITLE = "MLX75305" or TITLE = "ML8511" or TITLE = "TMP421":
    #num = 1
#elif TITLE = "HTU21D" or TITLE = "BMP180" or TITLE = "HIH6130" or TITLE = "SHT25" or TITLE = "LPS25H":
    #num = 2
#elif TITLE = "Si1145": # special case, not a int, but hex
    #num = 3
#elif TITLE = "MMA8452Q" or TITLE = "HMC5883L":
    #num = 4
#else:
    #print "Wrong sensor name"
    #break

SUB_FILE_NAME = "sub" + TITLE + ".txt"

try:
    with open(SUB_FILE_NAME) as data_file:
        for line in data_file:
            #print line

            if flag_FIRST == False:
                one = line.split(" ")

                x.append(dt.datetime.strptime(one[0], "%Y:%b:%d:%H:%M:%S"))

                if num == 1:
                    y.append(int(one[1].strip("\n")))
                elif num == 2:
                    y.append(int(one[1].strip("\n")))
                    z.append(int(one[2].strip("\n")))
                elif  num == 3:
                    y.append(int(one[1].strip("\n")))
                    z.append(int(one[2].strip("\n")))
                    v.append(int(one[3].strip("\n")))
                elif num == 4:
                    y.append(int(one[1].strip("\n")))
                    z.append(int(one[2].strip("\n")))
                    v.append(int(one[3].strip("\n")))
                    w.append(int(one[4].strip("\n")))
                else:
                    print "Wrong num"
                    break

            else:
                num = int(line)
                flag_FIRST = False
                #print num
            
        #print one
        
    #print x, time
    dates = matplotlib.dates.date2num(x)
    
    hours = mdates.MinuteLocator(interval=50)
    #minutes = mdates.MinuteLocator(interval=1)
    hourFmt= mdates.DateFormatter('%b-%d %H:%M:%S')
    
    fig, ax = plt.subplots()
    if num == 1:
        ax.plot(dates, y)
    if num == 2:
        ax.plot(dates, y, 'r--', dates, z, 'b--')
    if num == 3:
        ax.plot(dates, y, 'r--', dates, z, 'b--', dates, v, 'g--')
    if num == 4:
        ax.plot(dates, y, 'r--', dates, z, 'b--', dates, v, 'g--', dates, w, 'g^')
    plt.grid(b=True, which='both')
    
    ax.xaxis.set_major_locator(hours)
    ax.xaxis.set_major_formatter(hourFmt)
    #ax.xaxis.set_minor_locator(minutes)
    #ax.xaxis.set_minor_formatter(hourFmt)
    fig.autofmt_xdate()
    plt.show()

except (KeyboardInterrupt, SystemExit):
    data_file.close()

data_file.close()


#import datetime
#import numpy as np
#import matplotlib.pyplot as plt
#import matplotlib.dates as mdates
#import matplotlib.cbook as cbook

#hours = mdates.MinuteLocator(interval=10)   # every year
#minutes = mdates.MinuteLocator(interval=10)  # every month
#hourFmt= mdates.DateFormatter('%H:%M:%S')

#fig, ax = plt.subplots()
#ax.plot(dates, y)
#plt.grid(b=True, which='both')

# format the ticks
#ax.xaxis.set_major_locator(hours)
#ax.xaxis.set_major_formatter(hourFmt)
#ax.xaxis.set_minor_locator(minutes)
#ax.xaxis.set_minor_formatter(hourFmt)

#datemin = datetime.date(r.date.min().year, 1, 1)
#datemax = datetime.date(r.date.max().year + 1, 1, 1)
#ax.set_xlim(datemin, datemax)


# rotates and right aligns the x labels, and moves the bottom of the
# axes up to make room for them
#fig.autofmt_xdate()

#plt.show()