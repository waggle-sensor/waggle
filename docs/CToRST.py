# CToRST.py
from cStringIO import StringIO



class Function(object):

	def __init__(self,comment,name):

		comment = StringIO(comment)
		self.data = {
			"body": "",
			"returns": [],
			"params": [],
			"name": ""
		}
		for line in comment.readlines():
			if(line.lstrip() and line.lstrip()[0] == ":"): # This is a tag
				tag = line.lstrip().split(" ")[0][1:]
				if tag == "rtype:":
					self.data["returns"].append(" ".join(line.lstrip().split(" ")[1:])[:-1])
				elif tag == "param":
					splitted = line.lstrip().split(" ")
					pName = splitted[2]
					pType = splitted[1]
					description = " ".join(splitted[3:])[:-1]
					self.data["params"].append((pName,pType,description))
			else: # It's part of the body then.
				self.data["body"] += line
		comment.close()

		# Chop up the name
		methodName = name.lstrip().split(" ")
		if methodName[0][:2] == "__":
			methodName = methodName[2].split("(")[0]
		else:
			methodName = methodName[1].split("(")[0]
		self.data["name"] = methodName

	def toRST(self):
		rst = ""

		# Write the name of the method
		rst += "**" + self.data["name"] + "**\n\n"

		tempIO = StringIO(self.data["body"])
		body = ""
		for line in tempIO.readlines():
			body += "| "+ line
		tempIO.close()

		rst += body[:-2] + "\n\n"	

		if self.data["params"]:
			rst += "   :Parameters:\n"
			for param in self.data["params"]:
				rst += "      "+param[0][:-1]+" ("+param[1]+"): "+param[2]+"\n"

		if self.data["returns"]:
			rst += "   :returns:\n"
			for rtype in self.data["returns"]:
				rst += "      "+rtype

		return rst


comments = []

print "Enter the file name to get comments from."

filename = raw_input('Filename: ')
with open(filename,'r') as cCode:
	for line in cCode:
		if(line.lstrip()[:2] == "/*"):
			#We want this comment!
			newComment = ""
			line = cCode.next()
			while line.lstrip()[:2] != "*/":
				newComment += line
				line = cCode.next()
			name = cCode.next()
			comments.append(Function(newComment,name))


# Write the .rst file

with open(filename.split(".")[0]+".rst","w+") as rstFile:
	rstFile.write(filename + "\n")
	rstFile.write("=" * len(filename) + "\n\n") # Underline it to tell RST it's a title
	addLine = False
	for comment in comments:
		if addLine:
			rstFile.write("\n\n---------\n\n")
		else:
			addLine = True
		rstFile.write(comment.toRST())

