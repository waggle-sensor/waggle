
import datetime

category = {'Temperature': 'temperature', 'Humidity': 'humidity', 'Pressure': 'pressure', 'Abs_humidity': 'vapor'}

class TwoDimenSets(object):
	def __init__(self, ds):
		self.ds = ds
		self.set_one = []
		self.post_type = {}

	def read(self):
		self._pre_sets()
		for key in self.set_one:
			for cat_list in category.keys():
				if cat_list in key:
					print(cat_list)
					self.post_type[cat_list] = []
					for sens in self.set_one[key]:
						self._call_function(cat_list, sens)

	def get_list(self):
		return self.post_type

	def _pre_sets(self):
		self.set_one = self.ds.get_list()


	def _call_function(self, cat_list, sens):
		if 'ref' not in sens:
			if cat_list != 'Abs_humidity':
				ref_sens = 'ref_' + category[cat_list]
				self._get_comparing_sets(ref_sens, sens, cat_list)
			else:
				ref_sens = 'ref_' + sens.split("_", 1)[1]
				self._get_comparing_sets(ref_sens, sens, cat_list)


	def _post_sensors(self, s_type, sensor):
		if sensor not in self.post_type[s_type]:
			self.post_type[s_type].append(sensor)


	def _get_comparing_sets(self, sensor_name_a, sensor_name_b, cat_list):
		sensor_array = [sensor_name_a, sensor_name_b]
		result = self.ds.get_sensor_data(sensor_array)

		for mac, data in result:
			if 'ref' in mac:
				ref_time = [record[0] for record in data[sensor_name_a]]
				ref_data = [record[1] for record in data[sensor_name_a]]
				continue
			else:
				macaddr = mac			
				sensor_time = [record[0] for record in data[sensor_name_b]]
				sensor_data = [record[1] for record in data[sensor_name_b]]

			for i in range(len(ref_time)):
				for j in range(len(sensor_time)):
					if (ref_time[i] - sensor_time[j]) < datetime.timedelta(0, 30) and \
					(ref_time[i] - sensor_time[j]) > datetime.timedelta(0, 0):
						sensor_name = sensor_name_b + "_ref"
						self.ds.store_post_data(macaddr, sensor_name, ref_data[i], sensor_data[j])
						self._post_sensors(cat_list, sensor_name)
						break