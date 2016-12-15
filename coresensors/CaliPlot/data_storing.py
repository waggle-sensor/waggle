

import time
import datetime as dt

SIGN_SENSOR = "coresense:3"

class DataSets(object):

	def __init__(self):
		self.dict_data = {}
		self.macs = []
		self.time_diff_utc = 0
		self.FLAG_TIME = False

	def read(self, args):
		self._get_time_difference()
		print(args)
		if "ref" in args[-1]:
			self._get_reference_data(args[-1])
			self._data_parsing(args[:-1])
			print("yes ref")
		else:
			self._data_parsing(args)
			print("no ref")

	def get_macs(self):
		return self.macs

	def get_all_sensor_data(self, sensor_name):
		for mac in self.macs:
			if (sensor_name, mac) in self.dict_data:
				yield (mac, self._get_row(sensor_name, mac))

	def get_THP_sensor_data(self, sensor_name_a, sensor_name_b, sensor_name_c):
		for mac in self.macs:
			if (sensor_name_a, mac) in self.dict_data and \
			(sensor_name_b, mac) in self.dict_data and \
			(sensor_name_c, mac) in self.dict_data:
				yield (mac, self._get_row(sensor_name_a, mac), self._get_row(sensor_name_b, mac), self._get_row(sensor_name_c, mac))

	def get_TT_sensor_data(self, sensor_name_a, sensor_name_b):
		for mac in self.macs:
			if (sensor_name_a, mac) in self.dict_data and \
			(sensor_name_b, mac) in self.dict_data:
				yield (mac, self._get_row(sensor_name_a, mac), self._get_row(sensor_name_b, mac))


	def store_post_ref_data(self, mac, sensor_name, date_time, sensor_data):
		self._store_ref_data(mac, sensor_name, date_time, sensor_data)

	def _get_row(self, sensor_name, mac):
		return self.dict_data[(sensor_name, mac)]


	def _datetime_form(self, pre_time):
		pre_time = pre_time.split(".")[0]

		formed_time = dt.datetime.strptime(pre_time, "%Y-%m-%d %H:%M:%S")
		return formed_time


	def _get_file_name(self, input):
		if "/" in input:
			op = ""

			name = input.split("/")
			for j in range(len(name) - 1):
				op = op + name[j] + "/"

			filename = op + "_" + name[-1]
		else:
			filename = "_" + input

		return filename


	def _data_parsing(self, file_list):
		for filename in file_list:

			filename = self._get_file_name(filename)
			macaddr = filename.split("_")[1]

			if macaddr not in self.macs:
				self.macs.append(macaddr)

			try:
				with open(filename) as data_file:
					date_time = ""
					for line in data_file:

						if SIGN_SENSOR in line:
							step_one = line.split(";")
							
							pre_time = step_one[0].split(".")[0]
							date_time = self._datetime_form(pre_time)

							sensor_name = step_one[2] + "_" + step_one[3]
							sensor_data = step_one[-2]

							self._store_data(macaddr, sensor_name, date_time, sensor_data)

						else:
							pass

				data_file.close()

			except (KeyboardInterrupt, SystemExit):
				data_file.close()


	def _get_time_difference(self):
		get_local_time = time.time()
		utc_time = dt.datetime.utcnow()
		str_local_time = dt.datetime.fromtimestamp(get_local_time).strftime('%Y-%m-%d %H:%M:%S')
		local_time = dt.datetime.fromtimestamp(get_local_time).strptime(str_local_time, '%Y-%m-%d %H:%M:%S')

		self.time_diff_utc = int(str(utc_time - local_time).split(":")[0])

	def _store_data(self, mac, sensor_name, date_time, sensor_data):
		date_time = date_time - dt.timedelta(hours=self.time_diff_utc)
		if (sensor_name, mac) not in self.dict_data:
			self.dict_data[(sensor_name, mac)] = []
		self.dict_data[(sensor_name, mac)].append([date_time, sensor_data])

	def _store_ref_data(self, mac, sensor_name, date_time, sensor_data):
		if (sensor_name, mac) not in self.dict_data:
			self.dict_data[(sensor_name, mac)] = []
		self.dict_data[(sensor_name, mac)].append([date_time, sensor_data])



#################### reference data ######################
	def _get_reference_data(self, args):
		FILE_NAME = args

		print(FILE_NAME)

		self.macs.append("_ref")
		try:
			with open(FILE_NAME) as data_file:
				for line in data_file:

					time_line = line.split(",")[0]

					d = time_line.split(" ")[0]
					t = time_line.split(" ")[1]
					ay = time_line.split(" ")[2]
					time_tmp = d + ":" + t + ay


					date_time = dt.datetime.strptime(time_tmp, "%m/%d/%Y:%I:%M:%S%p") 

					press = float(line.split(",")[1]) * 100
					humid = line.split(",")[2]
					temp = line.split(",")[3].strip("\n")

					self._store_ref_data("_ref", "ref_pressure", date_time, press)
					self._store_ref_data("_ref", "ref_humidity", date_time, humid)
					self._store_ref_data("_ref", "ref_temperature", date_time, temp)


			data_file.close()

		except (KeyboardInterrupt, SystemExit):
			data_file.close()
#################### reference data ######################