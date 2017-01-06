

import time
import datetime as dt


sensor_category = {
	'Temperature': ['TMP112_temperature', 'HTU21D_temperature', 'BMP180_temperature', 'TSYS01_temperature', 'HIH6130_temperature', 'TMP421_temperature', 'PR103J2_temperature', 'SHT25_temperature', 'LPS25H_temperature', 'ref_temperature'],
	'ADC_temperature': ['CO_ADC_Temp_adc_temperature', 'IAQ/IRR_Temp_adc_temperature', 'O3/NO2_Temp_adc_temperature', 'SO2/H2S_Temp_adc_temperature', 'CO_LMP_Temp_adc_temperature'],
	'Humidity': ['HTU21D_humidity', 'HIH4030_humidity', 'HIH6130_humidity', 'SHT25_humidity', 'ref_humidity'],
	'Pressure': ['BMP180_pressure', 'LPS25H_pressure', 'ref_pressure'],
	'Light': ['TSL250RD_intensity', 'APDS-9006-020_intensity', 'TSL260RD_intensity', 'MLX75305_intensity'],
	'UV_index': ['ML8511_intensity'],
	'Sound': ['SPV1840LR5H-B_intensity'],
	'Acceleration': ['MMA8452Q_acceleration.x', 'MMA8452Q_acceleration.y', 'MMA8452Q_acceleration.z', 'MMA8452Q_rms'],
	'Magnetic_field': ['HMC5883L_magnetic_field.x', 'HMC5883L_magnetic_field.y', 'HMC5883L_magnetic_field.z'],
	'Abs_humidity': ['ref_vapor_pressure', 'HTU21D_vapor_pressure', 'HIH4030_vapor_pressure', 'HIH6130_vapor_pressure', 'SHT25_vapor_pressure', \
					'ref_vapor_ratio', 'HTU21D_vapor_ratio', 'HIH4030_vapor_ratio', 'HIH6130_vapor_ratio', 'SHT25_vapor_ratio'],
	'Temp_diff': ['HTU21D_PR103J2_diff', 'HTU21D_HIH6130_diff', 'TSYS01_HIH6130_diff', 'TSYS01_PR103J2_diff']
}

SIGN_SENSOR = "coresense:3"

class DataSets(object):

	def __init__(self):
		self.dict_data = {}
		self.sensor_type = {}
		self.post_type = {}
		self.macs = []
		self.time_diff_utc = 0
		self.FLAG_TIME = False

	def read(self, args):
		self._get_time_difference()
		self._init_sensor_type()

		if "ref" in args[-1]:
			self._get_reference_data(args[-1])
			self._data_parsing(args[:-1])
			print("reference sensors? yes")
		else:
			self._data_parsing(args)
			print("reference sensors? no")

	def get_list(self):
		return self.sensor_type

	def get_sensor_data(self, sensor_array):
		for mac in self.macs:
			data = {}
			for sensor_name in sensor_array:
				if (sensor_name, mac) in self.dict_data:
					data[sensor_name] = self._get_row(sensor_name, mac)
					
			if data != {}:
				yield (mac, data)

	def get_all_mac_for_sensors(self, sensor_names):
		ret = []
		for sensor_name in sensor_names:
			for mac in self.macs:
				if (sensor_name, mac) in self.dict_data:
					if mac not in ret:
						ret.append(mac)
		return ret

	def store_post_data(self, mac, sensor_name, date_time, sensor_data):
		self._store_post_data(mac, sensor_name, date_time, sensor_data)

	def store_post_name(self, sensor_name):
		self._sensor_type_append(sensor_name)
	

	def _data_parsing(self, file_list):
		for filename in file_list:

			filename = self._get_file_name(filename)
			macaddr = "_" + filename.split("_")[-2]
			print("reading.......", filename)

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


							self._sensor_type_append(sensor_name)
							self._store_data(macaddr, sensor_name, date_time, sensor_data)

						else:
							pass

				data_file.close()

			except (KeyboardInterrupt, SystemExit):
				data_file.close()

	
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


	def _get_time_difference(self):
		get_local_time = time.time()
		utc_time = dt.datetime.utcnow()
		
		############# When is not summer time ############
		str_local_time = dt.datetime.fromtimestamp(get_local_time).strftime('%Y-%m-%d %H:%M:%S')

		############# When is summer time #############
		# str_local_time = (dt.datetime.fromtimestamp(get_local_time) + dt.timedelta(0,3600)).strftime('%Y-%m-%d %H:%M:%S')  

		local_time = dt.datetime.fromtimestamp(get_local_time).strptime(str_local_time, '%Y-%m-%d %H:%M:%S')

		self.time_diff_utc = int(str(utc_time - local_time).split(":")[0])


	def _init_sensor_type(self):
		for s_type, sensor_name in sensor_category.items():
			if s_type not in self.sensor_type:
				self.sensor_type[s_type] = []


	def _store_data(self, mac, sensor_name, date_time, sensor_data):
		if mac != "_ref":
			date_time = date_time - dt.timedelta(hours=self.time_diff_utc)

		if (sensor_name, mac) not in self.dict_data:
			self.dict_data[(sensor_name, mac)] = []
		self.dict_data[(sensor_name, mac)].append([date_time, sensor_data])

	def _store_post_data(self, mac, sensor_name, date_time, sensor_data):
		if (sensor_name, mac) not in self.dict_data:
			self.dict_data[(sensor_name, mac)] = []
		self.dict_data[(sensor_name, mac)].append([date_time, sensor_data])


	def _sensor_type_append(self, sensor_name):
		for s_type, s_name in sensor_category.items():
			if sensor_name in s_name:
				if sensor_name not in self.sensor_type[s_type]:
					self.sensor_type[s_type].append(sensor_name)


#################### reference data ######################
	def _get_reference_data(self, args):
		FILE_NAME = args

		print("reading.......", args)

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

					press = line.split(",")[1]
					humid = line.split(",")[2]
					temp = line.split(",")[3].strip("\n")

					self._store_data("_ref", "ref_pressure", date_time, press)
					self._store_data("_ref", "ref_humidity", date_time, humid)
					self._store_data("_ref", "ref_temperature", date_time, temp)

					self._sensor_type_append("ref_pressure")
					self._sensor_type_append("ref_humidity")
					self._sensor_type_append("ref_temperature")

			data_file.close()

		except (KeyboardInterrupt, SystemExit):
			data_file.close()
		except Exception as e:
			print(str(e))
#################### reference data ######################