#!/usr/bin/python
import sys, time, os

def links(link):
	'''
	This extracts all the sources of 'a' tag from the file
	'''
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

def convert(input_file):
	'''
	This converts the external links from the code into
	actual source codes generated from Sphinx
	'''
	FILE_PREFIX="../docs/_build/"
	KEY_TO_FIND="<div role=\"main\" class=\"document\">"
	KEY_TO_FIND_LEN = len(KEY_TO_FIND)

	try:
		file = open(input_file, "r+")
		content = file.read()
		file.close()
	except:
		exit(1)

	pos = 0
	pos_next = 0
	while(1):
		pos = content.find('<!--', pos_next)
		pos_next = content.find('-->', pos + 4)
		if pos == -1:
			break
		tag = content[pos + 4:pos_next]
		
		tag_pos = tag.find("\"")
		tag_end_pos = tag.find("\"", tag_pos + 1)
		tag = tag[tag_pos + 1:tag_end_pos]
		#print tag
		try:
			file = open(FILE_PREFIX+tag, "r+")
			code_content = file.read()
			file.close()
		except:
			continue
		print code_content
		code_pos = code_content.find(KEY_TO_FIND)
		code_pos_next = code_content.find('<footer', code_pos + KEY_TO_FIND_LEN)
		if code_pos == -1:
			continue
		#print code_content[code_pos:code_pos_next]
		content = content.replace(content[pos:pos_next + 3], code_content[code_pos:code_pos_next])
		#print content

	try:
		file = open(input_file, "w")
		file.write(content)
		file.close()
	except:
		exit(1)

if __name__ == '__main__':
	if len(sys.argv) < 3:
		print links(sys.argv[1])
	else:
		convert(sys.argv[1])