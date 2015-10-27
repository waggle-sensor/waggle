"""
    This script scans for the Node Controller's IP address and writes it to a file.

"""

import subprocess

#need to find the node's IP address 
#so, first save results of ifconfig and grep commands to get IP address to a file
p = subprocess.Popen('ifconfig | grep "inet addr" > output.txt', stdout=subprocess.PIPE, shell=True)
(output, err) = p.communicate()

#read the file
with open('output.txt','r') as _file:
    line = _file.readline().strip()

#the device's IP address should be found in the first line
#The line should look like '     inet address:xx.xx.xx.xx  Bcast:xx.xx.xx.xx Mask:xx.xx.xx.xx   '
#remove 'inet address'
junk, IP_addr = line.split(':',1)

#remove the extra stuff on the end that we don't need
IP_addr, junk = IP_addr.split(' ', 1)
print 'IP_addr: ', IP_addr

#Now, we have the device's IP address.
#write nodecontroller IP to file
with open('/etc/waggle/NCIP','w') as file_: 
    file_.write(IP_addr)
