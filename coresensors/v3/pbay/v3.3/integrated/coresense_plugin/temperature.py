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

line_count = 0
row_count = 0
column_count = 0

degree_c = [[] for _ in range(8)]
what_time = []

result = {}

for i in range(10):
	result[i] = []

strs = ["" for x in range(4)]

# sub_file = open("temperature.txt", "w+")
# sub_file = []
# for i in range (0, 39):
# 	sub_file.append(open("id_" + str(i) + ".txt", "w+"))

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
	global flag_TIME
	flag_TIME = True

	two = line.split(" ")
	sensor_id = int(two[1])

	# sub_file[sensor_id].write(strs[0])		# year
	# sub_file[sensor_id].write(":")
	# sub_file[sensor_id].write(strs[1])		# month
	# sub_file[sensor_id].write(":")
	# sub_file[sensor_id].write(strs[2])		# day
	# sub_file[sensor_id].write(":")
	# sub_file[sensor_id].write(strs[3])		# time
	# sub_file[sensor_id].write(" ")
    #print time, " ",
	# print "two: ", two

	# if two[1] == "1" or two[1] == "3" or two[1] == "5" or two[1] == "9" or two[1] == "19" or two[1] == "30":
	# 	num = 1
	# else:
	# 	num = 2
	# if two[1] == "7" | two[1] == "38" | two[1] == "39":
	# 	num = 4
	# elif two[1] == "10" | two[1] == "31":
	# 	num = 3

	for i in range (0, MAX_trial):
		if two[i] == "@":
			result[row_count].append(two[i + 2].strip())
			# 	sub_file[sensor_id].write(result[j])
			# 	sub_file[sensor_id].write(" ")

			# if sensor_id == 1:
			# 	what_time[0].append(result[0])				
			# 	degree_c[0].append(result[0])
			# if sensor_id == 2:
			# 	what_time[1].append(result[0])	
			# 	degree_c[1].append(result[0])
			# if sensor_id == 4:
			# 	what_time[2].append(result[0])	
			# 	degree_c[2].append(result[0])
			# if sensor_id == 5:
			# 	what_time[3].append(result[0])	
			# 	degree_c[3].append(result[0])
			# if sensor_id == 9:
			# 	what_time[4].append(result[0])	
			# 	degree_c[4].append(result[0])
			# if sensor_id == 11:
			# 	what_time[5].append(result[0])	
			# 	degree_c[5].append(result[0])
			# if sensor_id == 29:
			# 	what_time[6].append(result[0])	
			# 	degree_c[6].append(result[0])
			# if sensor_id == 30:
			# 	what_time[7].append(result[0])	
			# 	degree_c[7].append(result[0])

			# sub_file[sensor_id].write('\n')
			break
	# print "result: ", result


try:
	with open(FILE_NAME) as data_file:
		for line in data_file:

			# count = count + 1
			# print count
			# if count < 50:

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
				if sensor_id == 1 or sensor_id == 2 or sensor_id == 4 or sensor_id == 5 or sensor_id == 9 or sensor_id == 11 or sensor_id == 19 or sensor_id == 29 or sensor_id == 30:
					sensor_data()
					row_count = row_count + 1
					flag_SIGN = False

			# else:
			# 	break

	# plot data
	# # temperature data
	# temp_id = [1, 2, 4, 5, 9, 11, 29, 30]
	# for a in range (0, 8):
	# 	file_plot = "id_" + str(temp_id[a]) + ".txt"
	# 	with open(file_plot) as plot_file:
	# 		for line in plot_file:

	# 			one = line.split(" ")
	# 			print one
	# 			what.append(dt.datetime.strptime(one[0], "%Y:%b:%d:%H:%M:%S"))


			# if sensor_id == 1:
			# 	degree_c[0].append(result[0])
			# if sensor_id == 2:
			# 	degree_c[1].append(result[0])
			# if sensor_id == 4:
			# 	degree_c[2].append(result[0])
			# if sensor_id == 5:
			# 	degree_c[3].append(result[0])
			# if sensor_id == 9:
			# 	degree_c[4].append(result[0])
			# if sensor_id == 11:
			# 	degree_c[5].append(result[0])
			# if sensor_id == 29:
			# 	degree_c[6].append(result[0])
			# if sensor_id == 30:
			# 	degree_c[7].append(result[0])

	# print result
	# print len(what_time), len(result[6])
	print what_time[100]

	what_dates = matplotlib.dates.date2num(what_time)
	three_hours = mdates.MinuteLocator(interval = 180)
	hours = mdates.MinuteLocator(interval = 60)
	hourFmt = mdates.DateFormatter('%y-%b-%d %H:%M:%S')

	colors = iter(cm.rainbow(np.linspace(0, 1, 9)))

	fig, ax = plt.subplots()
	ax.plot(what_dates, result[0], color = 'black', linewidth = 0.7, label = 'TMP112')
	ax.plot(what_dates, result[1], color = 'firebrick', linewidth = 0.7, label = 'HTU21D')
	ax.plot(what_dates, result[2], color = 'r', linewidth = 1.2, label = 'BMP180')
	ax.plot(what_dates, result[3], color = 'gold', linewidth = 0.7, label = 'PR103J2')
	ax.plot(what_dates, result[4], color = 'olivedrab', linewidth = 0.7, label = 'TSYS01')
	ax.plot(what_dates, result[5], color = 'green', linewidth = 0.7, label = 'HIH6130')
	ax.plot(what_dates, result[6], color = 'c', linewidth = 0.7, label = 'TMP421')
	ax.plot(what_dates, result[7], color = 'dodgerblue', linewidth = 0.7, label = 'SHT25')
	ax.plot(what_dates, result[8], color = 'darkblue', linewidth = 0.7, label = 'LPS25H')

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