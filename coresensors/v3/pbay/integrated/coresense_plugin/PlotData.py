# plot data

import matplotlib.pyplot as plt
import matplotlib
import datetime as dt
import matplotlib.dates as mdates

# read line

i = 0
j = 0
x = []
y = []

TITLE = "CarbonMonoxide"
data_file = open("sub" + TITLE + ".txt", "r")

try:
    while (1):
        line = data_file.readline()
        if line == "":
            break
        
        one = line.split(" ")
        x.append(dt.datetime.strptime(one[0], "%H:%M:%S"))
        y.append(int(one[1].strip("\n")))
        #print one
        
    #print x, time
    dates = matplotlib.dates.date2num(x)
    
    hours = mdates.MinuteLocator(interval=10)
    minutes = mdates.MinuteLocator(interval=10)
    hourFmt= mdates.DateFormatter('%H:%M:%S')
    
    fig, ax = plt.subplots()
    ax.plot(dates, y)
    plt.grid(b=True, which='both')
    
    ax.xaxis.set_major_locator(hours)
    ax.xaxis.set_major_formatter(hourFmt)
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