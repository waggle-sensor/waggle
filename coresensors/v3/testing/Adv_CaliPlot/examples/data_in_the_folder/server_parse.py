#!/usr/bin/env python3


import sys

from pre_calc import *
from data_storing import *
from post_processes import *
from plot_class import *

from two_dimensional import *
from two_dimen_plot import *

def main():
	if len(sys.argv) < 2:
		print("add file names as arguments")
		exit(1)

	#** Pre-converting sensor values and names
	ps = PreSets()
	ps.read(sys.argv[1:])

	#** Storing data into a dictionary-list
	ds = DataSets()
	ds.read(sys.argv[1:])

	#** Calculating abs-humidity and temp-diff btw sensors
	ts = PostSets(ds)
	ts.calc()

	a_panels = {}


	#** Call existing sensor types: 
	#** sensor_category in data_storing.py needs to be updated
	s_cat = ds.get_list()

	#** Drawing a data-time plot
	try:
		for category, sensor_names in s_cat.items():
			p = data_time_Panel(category, sensor_names, ds.get_all_mac_for_sensors(sensor_names))
			for n in sensor_names:
				result = ds.get_sensor_data([n])
				for mac, data in result:
					p.fill_source(n, mac, data[n])

			a_panels[category] = p.get_panel()

		a_tabs = Tabs(tabs = [a_panels[category] for category in a_panels])

		show(a_tabs)

	#** Drawing a ref-sensor plot	
		if "ref" in sys.argv[-1]:
			hs = TwoDimenSets(ds)
			hs.read()
			
			b_panels = {}
			p_cat = hs.get_list()

			for category, sensor_names in p_cat.items():
				np = two_sensor_Panel(category, sensor_names, ds.get_all_mac_for_sensors(sensor_names))
				for sens in sensor_names:
					result = ds.get_sensor_data([sens])
					for mac, data in result:
						np.fill_source(sens, mac, data[sens])

				b_panels[category] = np.get_panel()

			b_tabs = Tabs(tabs = [b_panels[category] for category in b_panels])

			show(b_tabs)

	except Exception as e:
		print(str(e))
		pass


if __name__ == "__main__":
	# try:
	main()
	# except:
	# 	pass