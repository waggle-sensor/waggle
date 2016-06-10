## Integrated codes

This folder contains all files to test the airsense, lightsense, and chemsense board together. The boards need to be connected to your computer as shown in the document [link.pdf](../../../docs/sensorStreamFormat/link.pdf). Target file for integrated board test is [integrated.ino](./integrated.ino), and this gathers data from [airsense.ino](./airsense.ino), [lightsense.ino](./lightsense.ino), and [chemsense.ino](./chemsense.ino). Each sensor data is cumulated and parsed into designated format as explained in the document, [sensorStreamFormat.pdf](../../../docs/sensorStreamFormat/sensorStreamFormat.pdf). The formatted values will be stored in a sub-packet format which is explained also in the sensorStreamFormat.pdf. Please refer the two domucments.
The outcome of this process is a super-packet which contains all sensor values.

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

To compile and run the files, do
```bash
make run
```
</br>
__To exit the screen session created for the test, press Control+a, and press k and y afterward.__

To test this and get decoded data with python script, do
```bash
make install
```
and execute [coresense.py](./coresense_plugin/coresense.py) in [coresens_plugin](./coresense_plugin). 
```bash
python coresense.py
```
Decode process is done through [coresense_pluginUSBSerial.py](./coresense_plugin/coresense_pluginUSBSerial.py).
