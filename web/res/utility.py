#!/usr/bin/env python
import sys, time, os

#if __name__ == "__main__":
def links(link):
	#input_file = sys.argv[1]
	input_file = link
	content=""
	ret = []
	try:
		file = open(input_file, "r+")
		content = file.read()
		file.close()
	except:
		exit(1)
	
	pos = 0
	pos_next = 0
	while(1):
		pos = content.find('a href="', pos_next)
		pos_next = content.find('"', pos + 8)
		if pos == -1:
			break
		link = content[pos + 8:pos_next]
		#print link
		ret.append(link)
	return ret

print links(sys.argv[1])