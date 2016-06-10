#!/usr/bin/python
import sys, time, os

def links(link, tag):
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
		pos = content.find(tag, pos_next)
		pos_next = content.find('"', pos + len(tag))
		if pos == -1:
			break
		link = content[pos + len(tag):pos_next]
		#print link
		ret.append(link)
	return ret

def convert(input_file, file_path, codes_files):
	'''
	This converts the external links from the code into
	actual source codes generated from Doxygen
	'''
	FILE_PREFIX="../docs/_build/"
	KEY_TO_FIND="<div id=\"doc-content\" "
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

def replace(input_file, original_source_code, namespace_filename, namespace_filename_without_extension):
	'''
	This converts the external links from the code into
	a link that goes to actual source code generated from Doxygen
	'''
	A_TAG="<a href=\"{}\">{}</a> <br>"
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

		if original_source_code in tag:
			content = content.replace(content[pos:pos_next + 3], A_TAG.format(namespace_filename, namespace_filename_without_extension))

	try:
		file = open(input_file, "w")
		file.write(content)
		file.close()
	except:
		exit(1)

if __name__ == '__main__':
	if len(sys.argv) < 4:
		print links(sys.argv[1], sys.argv[2])
	elif len(sys.argv) < 5:
		convert(sys.argv[1], sys.argv[2], sys.argv[3])
	elif len(sys.argv) < 6:
		replace(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])