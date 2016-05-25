# SSH connection to the node controller

To ssh into your ODROID you may first have to figure out its IP address. If your computer is in the same internal network as the ODROID and you do not know the IP address, you can follow the steps below. If you have access to your router's admin page, you could also find the IP address there. In case the ODROID is not connected to a private network you might have to attach a monitor and keyboard to the ODROID.

First, get your computer's IP address, e.g.:
```text
ifconfig -a
```
or more specific:
```bash
# Linux
ifconfig -a | grep -o "inet addr:[0-9\.]\+" | grep -v 127.0.0.1 | grep -o "[0-9\.]\+"
# OSX
ifconfig -a | grep -o "inet [0-9\.]\+" | grep -v 127.0.0.1 | grep -o "[0-9\.]\+"
```
Example output:
```text
130.202.135.120   # public IP, do not use with nmap
10.10.10.120      # IP in private network, use that !
```

Your computer might have more than one IP address assigned. Make sure that for the following step you use the IP address for the local network to which the ODROID also is connected. Possible private IPv4 address spaces: 10.0.0.0 - 10.255.255.255, 172.16.0.0 - 172.31.255.255 and 192.168.0.0 - 192.168.255.255 .

To find the actual IP address of the ODROID you can use the tool nmap.
```bash
# Linux:
apt-get install nmap
# OSX:
brew install nmap
```

Use nmap to list all devices in your network:
```bash
nmap -sP <yourIP>/24 
```
If the output does not include hostnames, you might have a hard time to figure out which of the listed devices is your ODROID. (You could disconnect the ODROID from the network and run nmap again and the compare the two lists of devices.) You can also point nmap to a DNS server. Assuming your IP is 10.10.10.120 and your router is acting as a DNS server with IP address 10.10.10.1, you could run nmap like this:

```bash
nmap -sP --dns-servers=10.10.10.1 10.10.10.120/24  
```

Your ODROID should show up in that list with a hostname containing the name "waggle".


Now you should be able to ssh into your ODROID:
```bash
# waggle image:
ssh waggle@<odroid_ip>
#password: waggle

# if you use the ODROID stock ubuntu image:
ssh odroid@<odroid_ip>
# or
ssh root@<odroid_ip>
#password: odroid
```



