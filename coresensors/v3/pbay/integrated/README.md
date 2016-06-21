## Integrated codes

This folder contains all files to test the airsense, lightsense, and chemsense board together (Jun 21, 2016). The boards need to be connected to your computer as shown in the document [link.pdf](../../../docs/sensorStreamFormat/link.pdf). 

Target file for complie and build codes for integrated board test is [integrated.ino](./integrated.ino). This file calls all other relative codes to gather data using [airsense.ino](./airsense.ino), [lightsense.ino](./lightsense.ino), and [chemsense.ino](./chemsense.ino). Each sensor data is cumulated and parsed into designated format as explained in the document, [sensorStreamFormat.pdf](../../../docs/sensorStreamFormat/sensorStreamFormat.pdf). All relative codes to get data from lightsense and airsense are in this folder and 'lib' folder. 

The formatted values will be stored in a sub-packet format which is explained also in the sensorStreamFormat.pdf. Please refer the two domucments. The sub-packet are initialized though [initialization.ino](./initialization.ino), which put designiated sensor ID, and initialize second buffer of each sub-packets. The outcome of this process is a super-packet which generated from [packet_assembler.ino](./packet_assembler.ino), which contains all sensor values. 

When you need to do "serial debug (verbose mode)" or need to test without one or more sensors, the mode can be modified by changing status defined in [config.cpp](./config.cpp).

## Coresense_plugin

The coresense plugin folder contains python codes which de-parse super-packets into human readable lines. Processes to de-parse super-packets are in [coresense_pluginUSBSerial.py](./coresense_plugin/coresense_pluginUSBSerial.py). To change USB serial port, see [coresense_InotifyKernel.py](./coresense_plugin/coresense_InotifyKernel.py) and change "/dev/waggle_coresense" in "newDevice.put('/dev/waggle_coresense')" to what you are using.

To execute this process, do
```bash
python coresense.py
```

## Tools and equipment required:
* One of each Chemsense, Lightsense, and Airsense borads
* Two ethernet cables and a micro-USB cable
* A computer to test the Chemsense

## Perform a test with the files
When you test with the files, make sure the sensor boards are connected and powered on. To see the values from the sensor boards, make sure that the SERIAL_DEBUG is set in config.cpp.

To compile the files, do
```bash
make
```
To compile, build and upload the codes on the Atmel, do
```bash
make install
```
or
```bash
make
make program
```

To compile, build and run the files, do
```bash
make run
```
</br>
__To exit the screen session created for the test, press Control+a, and press k and y afterward.__

To compile, build the codes and get decoded data with python script, do
```bash
make install
```
and execute [coresense.py](./coresense_plugin/coresense.py) in [coresens_plugin](./coresense_plugin). 
```bash
python coresense.py
```
Decode process is done through [coresense_pluginUSBSerial.py](./coresense_plugin/coresense_pluginUSBSerial.py).
