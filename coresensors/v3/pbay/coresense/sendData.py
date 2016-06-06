import serial
import time

while 1:
    try:
	link = serial.Serial("/dev/waggle_coresense", 115200)
	print "connected"
        break
    except:
	print "no connection"
        time.sleep(1)

#When a link is found
f = open('workfile.txt', 'r+')
index = 0
Flag = False
  
while 1:
    if index < 3:
	line = f.readline()
	if line == "end":
	    print "nothig"
	    break
	else:
	    if 'BAD' in line: #contain "BAD"
		#link.write(" ")
	        link.write(line)#link.write(line)
    		print line

		if index == 2 and Flag == False:
		    Flag = True
	#	    link.write(" ")
		    continue 

	    else:
	        continue
    index = (index + 1) % 5
    Flag = False
    time.sleep(1)

f.close()
link.close()
