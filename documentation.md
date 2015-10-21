
## AirSense / LightSense
* Overview
* Build firmware image (NC)
* Flash AirSense (NC)
* Send commands
  * Display \<sensor\>
  * Reboot
  * Set variable \<variable\>
  * List sensors/variables
  * Status
  * Enable \<sensor\>
  * Disable \<sensor\>
 
## WAGMAN
* Overview / LED, PWR, etc 
* Build firmware image (NC)
* Flash Wagman (NC)
* Send commands (NC)
  * off \<device\>
  * on \<device\>
  * reboot \{device\}
  * display \<sensor\>
  * set \<variable\>
  * list sensors / variables
  * status \{device\}
  * gettime \<-\>
  * settime \<-\>

## Web
* Build and Install Cassandra
* Launch ...


## Guest Computer
* Build image from scratch
  * test
  * test2
* Download & install image
* Log in via NodeController
* Rebuild via SafeMode (future)
* Configure for data push to NC
* Turn on simple board sensors (to NC)
* Run OvenCV example<br>
  * detect motion
  * emit sensor value (e.g. brightness)



## Node Controller
* Build image from scratch
* Download and install waggle image
* Log in via ethernet
* Configure Wifi
* Configure sensor list
* Configure to cloud  (unique ID)
* Recovery safe mode scripts (future)
* Rebuild via safe mode
* Cache control
* Turn on simple board sensors (to cloud)
