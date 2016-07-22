import datetime as dt
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
import matplotlib.cm as cm
import matplotlib.dates as mdates

# read line

flag_SIGN = False
flag_TIME = False

SIGN = "-------------"
FILE_NAME = "July20_17_30.txt"  #Need to change file name

MAX_trial = 8
sensor_id = 0

test_count = 0
row_count = 0
column_count = 0

degree_c = [[] for _ in range(8)]
what_time = []

result = {}

for i in range(10):
	result[i] = []

strs = ["" for x in range(4)]

def get_time():
	one = line.split(" ")
	
	if 'lost' in one[-1]:
		return
	if int(one[-1], 10) < 5:
		return
	else:
		strs[0] = one[4]
		strs[1] = one[1]
		strs[2] = one[2]
		strs[3] = one[3]

		this_time = strs[0] + ":" + strs[1] + ":" + strs[2] + ":" + strs[3]
		what_time.append(dt.datetime.strptime(this_time, "%Y:%b:%d:%H:%M:%S"))

def get_sensor_id():
	two = line.split(" ")
	sensor_id = int(two[1])
    #print time, " ",
	# print "two: ", two
	return sensor_id

def sensor_data():
	two = line.split(" ")
	sensor_id = int(two[1])

	global flag_TIME
	flag_TIME = True

	if sensor_id == 2 or sensor_id == 11 or sensor_id == 29:
		for i in range (0, MAX_trial):
			if two[i] == "@":
				result[row_count].append(two[i + 3].strip())
				break

	elif sensor_id == 3:
		for i in range (0, MAX_trial):
			if two[i] == "@":
				result[row_count].append(two[i + 2].strip())
				break

try:
	with open(FILE_NAME) as data_file:
		for line in data_file:

			# test_count = test_count + 1
			# print test_count
			# if test_count < 50:

			#if TIME in line:
			if flag_SIGN == True:
				get_time()
				flag_SIGN = False

			#if data lines will be following:
			elif SIGN in line:
				flag_SIGN = True
				if flag_TIME == True:
					# write_file()
					row_count = 0
					flag_TIME = False

			# data
			elif "Sensor" in line:
				sensor_id = get_sensor_id()
				if sensor_id == 2 or sensor_id == 3 or sensor_id == 11 or sensor_id == 29:
					sensor_data()
					row_count = row_count + 1
				flag_SIGN = False

			# else:
			# 	break

	# print result
	# print len(what_time), result
	# print what_time[100]

	what_dates = matplotlib.dates.date2num(what_time)
	three_hours = mdates.MinuteLocator(interval = 180)
	hours = mdates.MinuteLocator(interval = 60)
	hourFmt = mdates.DateFormatter('%y-%b-%d %H:%M:%S')

	colors = iter(cm.rainbow(np.linspace(0, 1, 9)))

	fig, ax = plt.subplots()
	ax.plot(what_dates, result[0], color = 'black', linewidth = 0.7, label = 'HTU21D')
	ax.plot(what_dates, result[1], color = 'firebrick', linewidth = 0.7, label = 'HIH4030')
	ax.plot(what_dates, result[2], color = 'olivedrab', linewidth = 0.7, label = 'HIH6030')
	ax.plot(what_dates, result[3], color = 'dodgerblue', linewidth = 0.7, label = 'SHT25')

	fig.autofmt_xdate()
	plt.grid(b = True, which = 'both')
	ax.xaxis.set_major_locator(three_hours)
	ax.xaxis.set_major_formatter(hourFmt)
	ax.xaxis.set_minor_locator(hours)
	# ax.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
	plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.05), ncol=9)
	plt.show()


except (KeyboardInterrupt, SystemExit):
	data_file.close()
	# sub_file.close()

data_file.close()
# sub_file.close()