#!/usr/bin/env python3


import sys

from pre_calc import *
from data_storing import *
from abs_humidity import *
from plot_class import *

sensor_type = {
	'Temperature': ['TMP112_temperature', 'HTU21D_temperature', 'BMP180_temperature', 'TSYS01_temperature', 'HIH6130_temperature', 'TMP421_temperature', 'PR103J2_temperature', 'ref_temperature'],
	'Humidity': ['HTU21D_humidity', 'HIH4030_humidity', 'HIH6130_humidity', 'ref_humidity'],
	'Pressure': ['BMP180_pressure', 'ref_pressure'],
	'Light': ['TSL250RD_intensity', 'APDS-9006-020_intensity', 'TSL260RD_intensity', 'MLX75305_intensity'],
	'UV_index': ['ML8511_intensity'],
	'Acceleration': ['MMA8452Q_acceleration.x', 'MMA8452Q_acceleration.y', 'MMA8452Q_acceleration.z', 'MMA8452Q_rms'],
	'Magnetic_field': ['HMC5883L_magnetic_field.x', 'HMC5883L_magnetic_field.y', 'HMC5883L_magnetic_field.z'],
	'Abs_humidity': ['ref_vapor_pressure', 'HTU21D_vapor_pressure', 'HIH4030_vapor_pressure', 'HIH6130_vapor_pressure', 'ref_vapor_ratio', 'HTU21D_vapor_ratio', 'HIH4030_vapor_ratio', 'HIH6130_vapor_ratio'],
	'Temp_diff': ['HTU21D_PR103J2_diff', 'HTU21D_HIH6130_diff', 'TSYS01_HIH6130_diff', 'TSYS01_PR103J2_diff']
}

sensor_unit = {
	'Temperature': 'Degree Celsius ($^\circ$C)',
	'Humidity': 'Relative Humidity (%RH)',
	'Pressure': 'Pascal (Pa)',
	'Light': 'Various Units',
	'UV_index': 'index',
	'Acceleration': 'gauss (g)',
	'Magnetic_field': 'Gauss (G)'
}

def main():
	if len(sys.argv) < 2:
		print("add file names as arguments")
		exit(1)

	ps = PreSets()
	ps.read(sys.argv[1:])

	ds = DataSets()
	ds.read(sys.argv[1:])

	ts = PostSets(ds)
	ts.calc()

	panels = {}

	for category, sensor_names in sensor_type.items():
		p = SH_Panel(category, sensor_names, ds.get_macs())
		for n in sensor_names:
			result = ds.get_all_sensor_data(n)
			for mac, data in result:
				p.fill_source(n, mac, data)

		panels[category] = p.get_panel()

	tabs = Tabs(tabs = [panels[category] for category in panels])

	show(tabs)


if __name__ == "__main__":
	main()