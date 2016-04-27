The library was forked from https://github.com/adafruit/Adafruit_HMC5883_Unified, renamed and modified to allow use of I2C Port0 and Port1.
## Usage:
```
HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(&Wire1); // Sensor is connected to Wire1 interface
HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor();  // Sensor is connected to Wire interface (default behavior)
HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(23);  // Sensor is connected to Wire interface, and has id 23 (default behavior)
HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(23,&Wire1); // Sensor is connected to Wire1 interface, and has id 23
```
