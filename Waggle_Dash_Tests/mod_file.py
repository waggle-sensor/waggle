#!usr/bin/env python

# Test file to update JSON file every 2 seconds
#
# TO RUN: in terminal: watch -n x update_node.py, where x is number of seconds between updates
#
import random

def mod_file():
	str_0 = '[\n\t{"node_name":"ANL", "lat":"10.5", "lng":"40", "active":"Active", "page":"#"},\n\t{"node_name":"COD", "lat":"24.7905", "lng":"-87.2854", "active":"Active", "page":"#"},\n\t{"node_name":"UIC", "lat":"23.32", "lng":"-2.333", "active":"Inactive", "page":"#"}\n]'
	str_1 = '[\n\t{"node_name":"ANL", "lat":"10.5", "lng":"40", "active":"Active", "page":"#"},\n\t{"node_name":"UIC", "lat":"23.32", "lng":"-2.333", "active":"Active", "page":"#"},\n\t{"node_name":"IIT", "lat":"89.664", "lng":"40.1103", "active":"Inactive", "page":"#"},\n\t{"node_name":"Mizzou", "lat":"19.35", "lng":"-75.1", "active":"Active", "page":"#"}\n]'
	#str_1 = '[\n\t{"node_name":"IIT", "lat":"14.5", "lng":"60", "active":"Active", "page":"#"},\n\t{"node_name":"NIU", "lat":"103.479902", "lng":"-17.65", "active":"Active", "page":"#"}\n]'

	x = random.random()

	f = open("node.json", 'w')
	if x > 0.5:
		f.write(str_0);
		print "str_0: 3 elements -> ANL, COD, UIC"
	else:
		f.write(str_1);
		print "str_1: 4 elements -> ANL, UIC, IIT, Mizzou"
		#print "str_1: 1 element -> IIT, NIU"

	f.close()

if __name__ == "__main__":
	import sys
	mod_file()