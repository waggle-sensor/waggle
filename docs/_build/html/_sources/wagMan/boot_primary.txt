boot_primary.ino
================

**boot_primary**

|    Starts/initializes/boots self, node controller, and ethernet switch.
|    Conditions for and operation of the node controller and ethernet switch are
|    verified before completing boot sequence.
|

   :returns:
      boolean

---------

**init_primary**

|    Initializes/starts all necessary ports, peripherals, interrupts, etc.
|

   :returns:
      none

---------

**check_power_self**

|    Reads its own current sensor.  If too much power is being drawn, we shut
|    ourselves down.
|

   :returns:
      none

---------

**check_environ_self**

|    Gets temperature and humidity info from the sensor, then checks if the 
|    environment is suitable for safe operation of the system monitor.  If it is
|    not safe, then we go to sleep.
|

   :returns:
      none

---------

**check_environ_nc**

|    Gets temperature and humidity info from the sensor, then checks if the 
|    environment is suitable for safe operation of the node controller.  If it
|    is not safe, then we monitor it until it is safe.
|

   :returns:
      none

---------

**check_power_nc**

|    Reads the node controller's current sensor.  If the node controller is not
|    drawing any power or is drawing too much power, we'll shut it down and go
|    to sleep.
|

   :returns:
      none

---------

**check_heartbeat_nc**

|    Checks that the node controller is alive and sending a heartbeat.  If it is
|    not, then power cycle it and try again.  If a reboot is tried too many
|    times, the node controller is assumed to be dead, so we go to sleep.
|

   :returns:
      none

---------

**get_gn_info**

|    Requests information about the guest nodes from the node controller.
|    Expected data for each guest nodes contains: present/not present, acceptable
|    environmental conditions, and expected power draw.  If the node controller
|    takes too long to send the info, we skip booting the guest nodes.
|

   :returns:
      boolean

---------

**get_time_nc**

|    Requests a time update from the node controller.  If a time update is
|    received, the RTC is initialized with that time.  If a time update is not
|    recieved, the RTC is started without a time correction.
|

   :returns:
      none

---------

**check_environ_es**

|    Gets temperature info from the thermistor, then checks if the 
|    environment is suitable for safe operation of the ethernet switch.  If it
|    is not safe, then we monitor it until it is safe.
|

   :returns:
      none

---------

**check_power_es**

|    Reads the ethernet switch's current sensor.  If the ethernet switch is not
|    drawing any power or is drawing too much power, we'll shut it down and
|    inform the node controller (and wait for it to inform the cloud), then go
|    to sleep.
|

   :returns:
      none

---------

**check_heartbeat_es**

|    Checks that the ethernet switch is alive and sending a heartbeat.  If it is
|    not, then power cycle it and try again.  If a reboot is tried too many
|    times, the ethernet switch is assumed to be dead, so we inform the node 
|    controller (and wait for it to inform the cloud), then go to sleep.
|

   :returns:
      none