"""
    This file stores all of the configurable variables for a guest node. 

"""



with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    
#gets the IP address for the nodecontroller
with open('/etc/waggle/NCIP','r') as file_:
    NCIP = file_.read().strip() 

#Unique ID for the nodecontroller
with open('/etc/waggle/NCID','r') as file_:
    NC_ID = file_.read().strip() 