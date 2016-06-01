#!/usr/bin/env python
import sys, time, os

if __name__ == "__main__":
	print "hello world"

	if len(sys.argv) < 4:
		print "ERROR: NEED A FILE"
		exit(1)

	depth = int(sys.argv[3], 10)
	
	'''
	1. Retrieve dictionary for matching md
	and corresponding html files
	'''
	dic = []
	try:
		with open(sys.argv[4]) as fileobj:
			for line in fileobj:
				d = line.split(':')
				l = [d[1].strip(), d[0].strip()]
				dic.append(l)
	except:
		print "ERROR"
		exit(1)

	print dic

	content = ""
	try:
		file = open(sys.argv[1], "r+")
		content = file.read()
		file.close()
	except:
		print "ERROR occured"
	'''
	2. Find my path from the root
	'''
	dir_path = sys.argv[2] + '/'
	# for key in dic:
	# 	if key[1].find(from_file) != -1:

	'''
	3. Find any <a> tag and correct the path of
	the link using the dictionary
	'''
	pos = 0
	pos_next = 0
	while(1):
		pos = content.find('href="', pos_next)
		pos_next = content.find('"', pos + 6)
		if pos == -1:
			break
		link = content[pos + 6:pos_next]
		'''
		We only touch relative path for all converted md files
		'''
		if 'http' not in link and 'HTTP' not in link:
			for key in dic:
				comp = key[0].replace(dir_path, "")
				print dir_path,
				print key[0],
				print comp
				if depth == 0:
					print comp
				if link.find(comp) != -1:
					newlink = ""
					for i in range(depth):
						newlink += "../"
					newlink += key[1]
					content = content.replace(link, newlink)
					#print newlink
					break

	try:
		file = open(sys.argv[1], 'w')
		file.write(content)
		file.close()
	except:
		print "WRITE ERROR!!"
































"""
		if 'http' in link or 'HTTP' in link:
			print " ABSOLUTE"
			for key in dic:
				print key[0], 
				print link.find(key[0])
		else:
			if os.path.isabs(link):
				print " ABSOLUTE"
			else:
				print " RELATIVE"
"""