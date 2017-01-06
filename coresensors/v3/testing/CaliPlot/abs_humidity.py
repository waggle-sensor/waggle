
import math

class PostSets(object):
	def __init__(self, ds):
		self.ds = ds

	def calc(self):
		self._calc_humidity('ref_temperature', 'ref_humidity', 'ref_pressure')
		self._calc_humidity('HTU21D_temperature', 'HIH4030_humidity', 'BMP180_pressure')
		self._calc_humidity('HTU21D_temperature', 'HTU21D_humidity', 'BMP180_pressure')
		self._calc_humidity('HIH6130_temperature', 'HIH6130_humidity', 'BMP180_pressure')

		self._calc_temp_diff('HTU21D_temperature', 'PR103J2_temperature')
		self._calc_temp_diff('TSYS01_temperature', 'HIH6130_temperature')
		self._calc_temp_diff('HTU21D_temperature', 'HIH6130_temperature')
		self._calc_temp_diff('TSYS01_temperature', 'PR103J2_temperature')

	def _calc_humidity(self, sensor_name_a, sensor_name_b, sensor_name_c):
		data = self.ds.get_THP_sensor_data(sensor_name_a, sensor_name_b, sensor_name_c)

		for mac, record_t, record_h, record_p in data:
			time = [ record[0] for record in record_t]
			temp = [ record[1] for record in record_t]
			humid = [ record[1] for record in record_h]
			press = [ record[1] for record in record_p]
			macaddr = mac

			sensor_name = sensor_name_b.split("_")[0]

			for i in range(len(time)):
				factor_a = (17.67 * float(temp[i])) / (float(temp[i]) + 243.5)
				stauration_vapor = 6.112 * math.exp(factor_a)
				vapor_pressure = (float(humid[i]) / 100.0) * stauration_vapor
				water_vapor_ratio = 622 * (vapor_pressure / (int(press[i]) - vapor_pressure))
				date_time = time[i]

				self.ds.store_post_ref_data(macaddr, sensor_name + "_" + "vapor_pressure", date_time, vapor_pressure)
				self.ds.store_post_ref_data(macaddr, sensor_name + "_" + "vapor_ratio", date_time, water_vapor_ratio)

	def _calc_temp_diff(self, sensor_name_a, sensor_name_b):
		data = self.ds.get_TT_sensor_data(sensor_name_a, sensor_name_b)

		for mac, record_a, record_b in data:
			time = [ record[0] for record in record_a]
			temp_a = [ record[1] for record in record_a]
			temp_b = [ record[1] for record in record_b]
			macaddr = mac

			sensor_name = sensor_name_a.split("_")[0] + "_" + sensor_name_b.split("_")[0]

			for i in range(len(time)):
				diff = float(temp_a[i]) - float(temp_b[i])
				if diff < 0:
					diff = -diff

				date_time = time[i]

				self.ds.store_post_ref_data(macaddr, sensor_name + "_" + "diff", date_time, diff)