
import math

class PostSets(object):
	def __init__(self, ds):
		self.ds = ds

	def calc(self):

		self._calc_humidity('ref_temperature', 'ref_humidity', 'ref_pressure')
		self._calc_humidity('HTU21D_temperature', 'HIH4030_humidity', 'BMP180_pressure')
		self._calc_humidity('HTU21D_temperature', 'HTU21D_humidity', 'BMP180_pressure')
		self._calc_humidity('HIH6130_temperature', 'HIH6130_humidity', 'BMP180_pressure')
		self._calc_humidity('SHT25_temperature', 'SHT25_humidity', 'LPS25H_pressure')


		self._calc_temp_diff('HTU21D_temperature', 'PR103J2_temperature')
		self._calc_temp_diff('TSYS01_temperature', 'HIH6130_temperature')
		self._calc_temp_diff('HTU21D_temperature', 'HIH6130_temperature')
		self._calc_temp_diff('TSYS01_temperature', 'PR103J2_temperature')


	def _calc_humidity(self, sensor_name_a, sensor_name_b, sensor_name_c):
		sensor_array = [sensor_name_a, sensor_name_b, sensor_name_c]
		result = self.ds.get_sensor_data(sensor_array)

		for mac, data in result:
			time = [ record[0] for record in data[sensor_name_a]]
			temp = [ record[1] for record in data[sensor_name_a]]
			humid = [ record[1] for record in data[sensor_name_b]]
			press = [ record[1] for record in data[sensor_name_c]]
			macaddr = mac

			a_number = min(len(time), len(temp), len(humid), len(press))

			sensor_name = sensor_name_b.split("_")[0]

			for i in range(a_number):
				factor_a = (17.67 * float(temp[i])) / (float(temp[i]) + 243.5)
				stauration_vapor = 6.112 * math.exp(factor_a)
				vapor_pressure = (float(humid[i]) / 100.0) * stauration_vapor
				water_vapor_ratio = 622 * (vapor_pressure / (float(press[i]) - vapor_pressure))
				date_time = time[i]

				self.ds.store_post_data(macaddr, sensor_name + "_" + "vapor_pressure", date_time, vapor_pressure)
				self.ds.store_post_data(macaddr, sensor_name + "_" + "vapor_ratio", date_time, water_vapor_ratio)
				self.ds.store_post_name(sensor_name + "_" + "vapor_pressure")
				self.ds.store_post_name(sensor_name + "_" + "vapor_ratio")


	def _calc_temp_diff(self, sensor_name_a, sensor_name_b):
		sensor_array = [sensor_name_a, sensor_name_b]
		result = self.ds.get_sensor_data(sensor_array)

		for mac, data in result:
			time = [ record[0] for record in data[sensor_name_a]]
			temp_a = [ record[1] for record in data[sensor_name_a]]
			temp_b = [ record[1] for record in data[sensor_name_b]]
			macaddr = mac

			a_number = min(len(time), len(temp_a), len(temp_b))

			sensor_name = sensor_name_a.split("_")[0] + "_" + sensor_name_b.split("_")[0]

			for i in range(a_number):
				diff = float(temp_a[i]) - float(temp_b[i])
				if diff < 0:
					diff = -diff

				date_time = time[i]

				self.ds.store_post_data(macaddr, sensor_name + "_" + "diff", date_time, diff)
				self.ds.store_post_name(sensor_name + "_" + "diff")
