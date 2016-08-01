import sys

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

	if two == "TMP112":
		s_id = 1
	elif two == "HTU21D":
		s_id = 2
	elif two == "HIH4030":
		s_id = 3
	elif two == "BMP180":
		s_id = 4
	elif two == "PR103J2":
		s_id = 5
	elif two == "TSL250RD":
		s_id = 6
	elif two == "MMA8452Q":
		s_id = 7
	elif two == "SPV1840LR5H-B":
		s_id = 8
	elif two == "TSYS01":
		s_id = 9

	elif two == "HMC5883L":
		s_id = 10
	elif two == "HIH6130":
		s_id = 11
	elif two == "APDS-9006-020":
		s_id = 12
	elif two == "TSL260RD":
		s_id = 13
	elif two == "TSL250RD":
		s_id = 14
	elif two == "MLX75305":
		s_id = 15
	elif two == "ML8511":
		s_id = 16
	elif two == "MLX90614":
		s_id = 18
	elif two == "TMP421":
		s_id = 19

	elif two == "Total reducing gases":
		s_id = 21		
	elif two == "Nitrogen Di-oxide (NO2)":
		s_id = 23
	elif two == "Ozone (03)":
		s_id = 24
	elif two == "Hydrogen Sulphide (H2S)":
		s_id = 25
	elif two == "Total Oxidizing gases":
		s_id = 26
	elif two == "Carbon Monoxide (C0)":
		s_id = 27
	elif two == "Sulfur Dioxide (SO2)":
		s_id = 28
	elif two == "SHT25":
		s_id = 29
	elif two == "LPS25H":
		s_id = 30
	elif two == "CO ADC Temp":
		s_id = 33
	elif two == "IAQ/IRR ADC Temp":
		s_id = 34
	elif two == "O3/NO2 ADC Temp":
		s_id = 35
	elif two == "SO2/H2S ADC Temp":
		s_id = 36
	elif two == "CO LMP Temp":
		s_id = 37
	elif two == "Accelerometer":
		s_id = 38
	elif two == "Gyro":
		s_id = 39
	else:
		s_id = 0

	return s_id

def sensor_data(in_str, s_id, entry):
	if s_id == 0:
		return

	two = in_str[1:-2]
	three = two.split(",")

	if not s_id in what_time[entry]:
		what_time[entry][s_id] = {}

	for element in three:
		data = element[1:-1].split(':')

		# #JUST GUESS OF ******************************************** WHEN the data are came from chemical sensors
		# if s_id == 21:
		# 	data[1] = float(data[1]) / (48.75)
		# elif s_id == 23:
		# 	data[1] = float(data[1]) / 43.51
		# elif s_id == 24:
		# 	data[1] = float(data[1]) / (-10.13)
		# elif s_id == 25:
		# 	data[1] = float(data[1]) / 151.69
		# elif s_id == 26:
		# 	data[1] = float(data[1]) / 10.14
		# elif s_id == 27:
		# 	data[1] = float(data[1]) / 10.39
		# elif s_id == 28:
		# 	data[1] = float(data[1]) / 32.48

		what_time[entry][s_id][data[0]] = data[1]

if __name__ == "__main__":
	if len(sys.argv) != 2:
		print "usage: python result.py FILE_PATH"
		sys.exit()

	FILE_NAME = sys.argv[1]
	try:
		with open(FILE_NAME) as data_file:
			for line in data_file:

				# if count < 10020:
				# 	count = count + 1
				
				if "base64" not in line:
					
					if "results" in line:
						break

					one = line.split(";")
					# print one[5]

					index = get_time(one[5], pre_index)
					sensor_id = get_sensor_id(one[6], sensor_id)
					sensor_data(one[8], sensor_id, index)

				# else:
				# 	break

		what_time = OrderedDict(sorted(what_time.items()))

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

		# print len(result[1]), len(result[2]), len(result[4]), len(result[9]),
		# print what_time, result
		# print what_time

		# what_dates = matplotlib.dates.date2num(x)
		three_hours = mdates.MinuteLocator(interval = 180)
		hours = mdates.MinuteLocator(interval = 60)
		hourFmt = mdates.DateFormatter('%y-%b-%d %H:%M:%S')

		colors = iter(cm.rainbow(np.linspace(0, 1, 9)))

		# #************************************************************ PLOT TEMPERATURE VALUES
		# fig, ax = plt.subplots()
		# # fig.autofmt_xdate()
		# plt.grid(b = True, which = 'both')

		# #**** index for the result is sensor_id * 10 + data index (alphabeticall order of key words)
		# ax.plot(what_dates[1], result[11], color = 'black', linewidth = 0.7, label = 'TMP112')
		# ax.plot(what_dates[2], result[22], color = 'firebrick', linewidth = 0.7, label = 'HTU21D')
		# ax.plot(what_dates[4], result[42], color = 'r', linewidth = 1.2, label = 'BMP180')
		# # ax.plot(what_dates[5], result[501], color = 'gold', linewidth = 0.7, label = 'PR103J2')
		# ax.plot(what_dates[9], result[91], color = 'olivedrab', linewidth = 0.7, label = 'TSYS01')
		# ax.plot(what_dates[11], result[112], color = 'green', linewidth = 0.7, label = 'HIH6130')
		# ax.plot(what_dates[19], result[191], color = 'c', linewidth = 0.7, label = 'TMP421')
		# # ax.plot(what_dates[29], result[292], color = 'dodgerblue', linewidth = 0.7, label = 'SHT25')
		# # ax.plot(what_dates[30], result[302], color = 'darkblue', linewidth = 0.7, label = 'LPS25H')

		# plt.xlabel('Time (UTC)', fontsize=18)
		# plt.ylabel('Temperature (Centigrade)', fontsize=16)
		# plt.title('Temperature', fontsize=20)

		# # plt.ylim(0, 30)
		# # ax.xaxis.set_major_locator(three_hours)
		# # ax.xaxis.set_major_formatter(hourFmt)
		# # ax.xaxis.set_minor_locator(hours)
		# # ax.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
		# plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.07), ncol=9)
		# # plt.show()


		# #************************************************************ PLOT HUMIDITY VALUES
		# fig, ax_b = plt.subplots()
		# plt.grid(b = True, which = 'both')

		# ax_b.plot(what_dates[2], result[21], color = 'firebrick', linewidth = 0.7, label = 'HTU21D')
		# # ax_b.plot(what_dates[3], result[31], color = 'r', linewidth = 0.7, label = 'HIH4030')
		# ax_b.plot(what_dates[11], result[111], color = 'green', linewidth = 0.7, label = 'HIH6130')
		# # ax_b.plot(what_dates[29], result[291], color = 'c', linewidth = 0.7, label = 'SHT25')

		# plt.xlabel('Time (UTC)', fontsize=18)
		# plt.ylabel('Humidity (%RH)', fontsize=16)
		# plt.title('Humidity', fontsize=20)

		# # plt.ylim(0, 30)
		# # ax.xaxis.set_major_locator(three_hours)
		# # ax.xaxis.set_major_formatter(hourFmt)
		# # ax.xaxis.set_minor_locator(hours)
		# # ax.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
		# plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.07), ncol=9)


		# #************************************************************ PLOT BAROMATRIC PRESSURE VALUES
		# fig, ax_c = plt.subplots()
		# plt.grid(b = True, which = 'both')

		# ax_c.plot(what_dates[4], result[41], color = 'firebrick', linewidth = 0.7, label = 'BMP180')
		# # ax_c.plot(what_dates[30], result[301], color = 'c', linewidth = 0.7, label = 'LPS25')

		# plt.xlabel('Time (UTC)', fontsize=18)
		# plt.ylabel('Pressure (Pa)', fontsize=16)
		# plt.title('Barometric Pressure', fontsize=20)

		# # plt.ylim(0, 30)
		# # ax.xaxis.set_major_locator(three_hours)
		# # ax.xaxis.set_major_formatter(hourFmt)
		# # ax.xaxis.set_minor_locator(hours)
		# # ax.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
		# plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.07), ncol=9)



		#************************************************************ PLOT BAROMATRIC PRESSURE VALUES
		fig, ax_d = plt.subplots()
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
		# ax.xaxis.set_major_locator(three_hours)
		# ax.xaxis.set_major_formatter(hourFmt)
		# ax.xaxis.set_minor_locator(hours)
		# ax.yaxis.set_minor_locator(matplotlib.ticker.AutoMinorLocator())
		plt.legend(loc='upper right', bbox_to_anchor=(1.0, 0.1), ncol=4)



		plt.show()

	except (KeyboardInterrupt, SystemExit):
		data_file.close()
		# sub_file.close()

	data_file.close()
	# sub_file.close()