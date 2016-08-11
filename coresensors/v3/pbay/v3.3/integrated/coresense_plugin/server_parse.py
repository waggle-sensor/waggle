import sys

from datetime import timedelta
import datetime as dt
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
import matplotlib.cm as cm
import matplotlib.dates as mdates

from collections import OrderedDict

# read line

flag_SIGN = False
flag_TIME = False

SIGN = "-------------"
# FILE_NAME = "CIVIQ_data2.txt"  #Need to change file name

MAX_trial = 8
sensor_id = 0

line_count = 0
row_count = 0
column_count = 0
count = 0

what_time = {}
index = []
idx = 0
s_id = 0

pre_index = 0

sensor_idx = []
sensor_name = []

result = {}
what_dates = OrderedDict()

for i in range(400):
	result[i] = []
	what_dates[i] = []

strs = ["" for x in range(4)]


def get_time(in_str, idx):
	two = in_str.split(".")
	temp_string = two[0].strip()
	if not dt.datetime.strptime(temp_string, "%Y-%m-%d %H:%M:%S") in what_time:
		what_time[dt.datetime.strptime(temp_string, "%Y-%m-%d %H:%M:%S")] = {}

	return dt.datetime.strptime(temp_string, "%Y-%m-%d %H:%M:%S")


def get_sensor_id(in_str, s_id):
	two = in_str.strip()

	id_idx = 0
	found = 0
	for id_idx in range (0, len(sensor_idx)):	
		if in_str == sensor_name[id_idx]:
			# print sensor_idx[id_idx]

			found = int(sensor_idx[id_idx])
			break
			
	return found


def sensor_data(in_str, s_id, entry):
	if s_id == 0:
		return

	two = in_str[1:-2]
	three = two.split(",")

	if not s_id in what_time[entry]:
		what_time[entry][s_id] = {}

	for element in three:
		data = element[1:-1].split(':')

		if 24 <= s_id <= 29:
			data[1] = float(data[1])/100.00
		if s_id == 30 and 'Temperature' in data[0]:
			data[1] = float(data[1])/100.00

		# print data

		what_time[entry][s_id][data[0]] = data[1]

def sorting_data():
	for date in what_time:
		# print(date)
		# x.append(date)
		vals = what_time[date]
		for s_id in vals:
			inner_vals = what_time[date][s_id]
			data_local_index = 0
			what_dates[s_id].append(date)
			for v in inner_vals:
				data_local_index = data_local_index + 1
				data_index = s_id * 10 + data_local_index
				result[data_index].append(inner_vals[v])

def counting_data_hourly():
	for index_of_sensor_data in range (0, 400):
		if len(what_dates[index_of_sensor_data]) != 0:
			previous_time = what_dates[index_of_sensor_data][0] + dt.timedelta(hours=1)
			num_data_hour = 1

			# print what_dates[index_of_sensor_data][0], what_dates[index_of_sensor_data][len(what_dates[index_of_sensor_data]) - 1]

			result[index_of_sensor_data * 10].append(index_of_sensor_data)
			for length_of_what_dates_index in range (0, len(what_dates[index_of_sensor_data])):
				if previous_time > what_dates[index_of_sensor_data][length_of_what_dates_index]:
					num_data_hour = num_data_hour + 1
					# print num_data_hour
				else:
					result[index_of_sensor_data * 10].append(num_data_hour)
					previous_time = what_dates[index_of_sensor_data][length_of_what_dates_index] + dt.timedelta(hours=1)
					num_data_hour = 1
					# print result[index_of_sensor_data*10]

			result[index_of_sensor_data * 10].append(num_data_hour)
			# print what_dates[index_of_sensor_data][length_of_what_dates_index]
			print result[index_of_sensor_data*10]



if __name__ == "__main__":
	if len(sys.argv) < 2:
		print "usage: python result.py FILE_PATH"
		sys.exit()

	with open("sensor_id.csv") as id_file:
		for line in id_file:
			temp_to_get_id = line[0:-1].split(",")
			sensor_name.append(temp_to_get_id[0])
			sensor_idx.append(temp_to_get_id[1])

	for num_input_files in range (1, len(sys.argv)):
		FILE_NAME = sys.argv[num_input_files]	

		# FILE_NAME = sys.argv[1]
		try:
			with open(FILE_NAME) as data_file:
				for line in data_file:

					# if count < 10030:
					# 	count = count + 1
					
					if "base64" not in line:  ### NOT CONSIDERING ALPHASENSE
						
						if "results" in line:
							break

						one = line.split(";")
						# print one[6]
						# print type(sensor_idx[1])

						index = get_time(one[5], pre_index)
						sensor_id = get_sensor_id(one[6], sensor_id)
						sensor_data(one[8], sensor_id, index)

					# else:
					# 	break

		except (KeyboardInterrupt, SystemExit):
			data_file.close()
			# sub_file.close()

	what_time = OrderedDict(sorted(what_time.items()))

	sorting_data()
	counting_data_hourly()

	# for date in what_time:
	# 	# print(date)
	# 	# x.append(date)
	# 	vals = what_time[date]
	# 	for s_id in vals:
	# 		inner_vals = what_time[date][s_id]
	# 		data_local_index = 0
	# 		what_dates[s_id].append(date)
	# 		for v in inner_vals:
	# 			data_local_index = data_local_index + 1
	# 			data_index = s_id * 10 + data_local_index
	# 			result[data_index].append(inner_vals[v])

	# for index_of_sensor_data in range (0, 400):
	# 	if len(what_dates[index_of_sensor_data]) != 0:
	# 		previous_time = what_dates[index_of_sensor_data][0] + dt.timedelta(hours=1)
	# 		num_data_hour = 1

	# 		for length_of_what_dates_index in range (0, len(what_dates[index_of_sensor_data])):
	# 			if previous_time > what_dates[index_of_sensor_data][length_of_what_dates_index]:
	# 				num_data_hour = num_data_hour + 1
	# 				# print num_data_hour
	# 			else:
	# 				if len(result[index_of_sensor_data]) == 0:
	# 					result[index_of_sensor_data * 10].append(num_data_hour)
	# 				else:
	# 					result[index_of_sensor_data * 10 + 9].append(num_data_hour)
	# 				previous_time = what_dates[index_of_sensor_data][length_of_what_dates_index] + dt.timedelta(hours=1)
	# 				num_data_hour = 1
	# 				# print result[index_of_sensor_data*10]
	# 		print result[index_of_sensor_data*10]


	print len(result[11]), len(result[22]), len(result[42]), len(result[91]),
	# print what_time, result
	# print len(what_dates)

	# what_dates = matplotlib.dates.date2num(x)
	three_hours = mdates.MinuteLocator(interval = 60)
	hours = mdates.MinuteLocator(interval = 60)
	hourFmt = mdates.DateFormatter('%Y-%b-%d %H:%M:%S')

	colors = iter(cm.rainbow(np.linspace(0, 1, 9)))


	#************************************************************ HISTOGRAM
	# mu, sigma = 100, 15
	# x = mu + sigma * np.random.randn(10000)
	
	# hist, bins = np.histogram(x, bins=50)
	
	# width = 0.7 * (bins[1] - bins[0])
	# center = (bins[:-1] + bins[1:]) / 2

	# plt.xlabel('Time (UTC)', fontsize=18)
	# plt.ylabel('Count', fontsize=16)
	# plt.grid(b = True, which = 'both')
	# plt.bar(center, hist, align='center', width=width)



	#************************************************************ PLOT TEMPERATURE VALUES
	fig, ax = plt.subplots()
	fig.autofmt_xdate()			# tilt x date
	plt.grid(b = True, which = 'both')

	#**** index for the result is sensor_id * 10 + data index (alphabeticall order of key words)
	ax.plot(what_dates[1], result[11], color = 'black', linewidth = 1.5, label = 'TMP112')
	ax.plot(what_dates[2], result[22], color = 'firebrick', linewidth = 1.5, label = 'HTU21D')
	ax.plot(what_dates[4], result[42], color = 'r', linewidth = 1.5, label = 'BMP180')
	ax.plot(what_dates[5], result[51], color = 'gold', linewidth = 1.5, label = 'PR103J2')
	ax.plot(what_dates[9], result[91], color = 'olivedrab', linewidth = 1.5, label = 'TSYS01')
	ax.plot(what_dates[11], result[112], color = 'green', linewidth = 1.5, label = 'HIH6130')
	ax.plot(what_dates[19], result[191], color = 'c', linewidth = 1.5, label = 'TMP421')
	ax.plot(what_dates[29], result[292], color = 'dodgerblue', linewidth = 1.5, label = 'SHT25')
	ax.plot(what_dates[30], result[301], color = 'darkblue', linewidth = 1.5, label = 'LPS25H')

	plt.xlabel('Time (UTC)', fontsize=18)
	plt.ylabel('Temperature (Centigrade)', fontsize=16)
	plt.title('Temperature', fontsize=20)

	# plt.ylim(0, 30)
	ax.xaxis.set_major_locator(three_hours)
	ax.xaxis.set_major_formatter(hourFmt)
	# ax.xaxis.set_minor_locator(hours)
	ax.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
	plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.07), ncol=9)
	# plt.show()


	#************************************************************ PLOT HUMIDITY VALUES
	fig, ax_b = plt.subplots()
	fig.autofmt_xdate()	
	plt.grid(b = True, which = 'both')

	ax_b.plot(what_dates[2], result[21], color = 'firebrick', linewidth = 1.5, label = 'HTU21D')
	ax_b.plot(what_dates[3], result[31], color = 'r', linewidth = 1.5, label = 'HIH4030')
	ax_b.plot(what_dates[11], result[111], color = 'green', linewidth = 1.5, label = 'HIH6130')
	ax_b.plot(what_dates[29], result[291], color = 'c', linewidth = 1.5, label = 'SHT25')

	plt.xlabel('Time (UTC)', fontsize=18)
	plt.ylabel('Humidity (%RH)', fontsize=16)
	plt.title('Humidity', fontsize=20)

	# plt.ylim(0, 30)
	ax_b.xaxis.set_major_locator(three_hours)
	ax_b.xaxis.set_major_formatter(hourFmt)
	# ax_b.xaxis.set_minor_locator(hours)
	ax_b.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
	plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.07), ncol=9)


	#************************************************************ PLOT BAROMATRIC PRESSURE VALUES
	fig, ax_c = plt.subplots()
	fig.autofmt_xdate()	
	plt.grid(b = True, which = 'both')

	ax_c.plot(what_dates[4], result[41], color = 'firebrick', linewidth = 1.5, label = 'BMP180')
	ax_c.plot(what_dates[30], result[302], color = 'c', linewidth = 1.5, label = 'LPS25')

	plt.xlabel('Time (UTC)', fontsize=18)
	plt.ylabel('Pressure (Pa)', fontsize=16)
	plt.title('Barometric Pressure', fontsize=20)

	# plt.ylim(0, 30)
	ax_c.xaxis.set_major_locator(three_hours)
	ax_c.xaxis.set_major_formatter(hourFmt)
	# ax_c.xaxis.set_minor_locator(hours)
	ax_c.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
	plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.07), ncol=9)



	#************************************************************ PLOT BAROMATRIC PRESSURE VALUES
	fig, ax_d = plt.subplots()
	fig.autofmt_xdate()	
	plt.grid(b = True, which = 'both')

	ax_d.plot(what_dates[21], result[211], color = 'firebrick', linewidth = 1.5, label = 'Total reducing gases')
	ax_d.plot(what_dates[23], result[231], color = 'r', linewidth = 1.5, label = 'Nitrogen Di-oxide (NO2)')
	ax_d.plot(what_dates[24], result[241], color = 'gold', linewidth = 1.5, label = 'Ozone (03)')
	ax_d.plot(what_dates[25], result[251], color = 'olivedrab', linewidth = 1.5, label = 'Hydrogen Sulphide (H2S)')
	ax_d.plot(what_dates[26], result[261], color = 'c', linewidth = 1.5, label = 'Total Oxidizing gases')
	ax_d.plot(what_dates[27], result[271], color = 'dodgerblue', linewidth = 1.5, label = 'Carbon Monoxide (C0)')
	ax_d.plot(what_dates[28], result[281], color = 'darkblue', linewidth = 1.5, label = 'Sulfur Dioxide (SO2)')

	plt.xlabel('Time (UTC)', fontsize=18)
	plt.ylabel('parts-per notation (ppm)', fontsize=16)
	plt.title('Chemical sensors', fontsize=20)

	# plt.ylim(0, 30)
	ax_d.xaxis.set_major_locator(three_hours)
	ax_d.xaxis.set_major_formatter(hourFmt)
	# ax_d.xaxis.set_minor_locator(hours)
	ax_d.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
	plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.1), ncol=4)



	plt.show()

	data_file.close()
	# sub_file.close()