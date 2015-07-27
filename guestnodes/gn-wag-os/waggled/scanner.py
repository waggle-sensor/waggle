"""
    This script scans for the Node Controller IP address and writes it to a file.

"""

import subprocess, os, socket

#need to find the node's IP address 
#so, first save results of ifconfig linux command to file
p = subprocess.Popen("ifconfig", stdout=subprocess.PIPE, shell=True)
(output, err) = p.communicate()
print 'output from ifconfig: ', output

try:
    _file = open('output.txt','w')
    _file.write(output)
    _file.close()
except Exception as e:
    print e

#then use grep to get only the lines with 'inet addr' in them. 
#save those lines to file
try:
    p = subprocess.Popen('grep "inet addr" output.txt', stdout=subprocess.PIPE, shell=True)
    (output, err) = p.communicate()
    _file = open('output.txt', 'w')
    _file.write(output)
    _file.close()
except Exception as e:
    print e
    
#read the lines of the file
with open('output.txt','r') as _file:
    lines = _file.readlines()

#the device's IP address should be found in the first line
#The line should look like '     inet address:xx.xx.xx.xx  Bcast:xx.xx.xx.xx Mask:xx.xx.xx.xx   '
#Need to strip the extra whitespace
IP_addr = lines[0].strip()

#remove 'inet address'
junk, IP_addr = IP_addr.split(':',1)

#remove the extra stuff on the end that we don't need
IP_addr, junk = IP_addr.split(' ', 1)

#Now, we have the device's IP address. We can use that to scan for the node controller
#Need to remove the last number and add '.1/24'
nmap_IP = ''
for i in range(3):
    stuff, IP_addr = IP_addr.split('.',1)
    nmap_IP = nmap_IP + stuff + '.'

nmap_IP = nmap_IP + '1/24'

#TODO can combine above steps
#need to do a host discovery scan and write results to file
p = subprocess.Popen('nmap -sP ' + nmap_IP + ' > output.txt', stdout=subprocess.PIPE, shell=True)
(output, err) = p.communicate()
#_file = open('output.txt', 'w')
#_file.write(output)
#_file.close()

#list of available hosts that need to be checked
hosts = []
with open ('output.txt','r') as _file:
    lines = _file.readlines()

#check each line for a host IP address    
for line in lines:
    #does the line contain an IP address?
    if line.find('('): 
        #remove the parenthesis around the IP address
        junk, IP = line.split('(',1)
        IP, junk = IP.split(')',1)
        #add it to the list of hosts
        hosts.append(IP)
        
#now, we need to check each host to find out if it is the node controller
PORT = 9090 #port for push_server
for HOST in hosts:
    try: 
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((HOST,PORT))
        print 'Connected...'
        request = 'Hello' #a nice hello
        s.send(request)
        msg = s.recv(4028)
        if msg == 'Hi': #Nodecontroller! #TODO probably need to make this more secure
            with open('/etc/waggle/NCIP','r') as file_: #write nodecontroller IP to file
                HOST= file_.read().strip() 
            print 'NCIP is: ', HOST
            break
        else:
            #Not the nodecontroller... 
            pass
    except: 
        pass
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

