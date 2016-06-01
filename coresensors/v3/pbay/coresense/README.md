## Pbay coresense
This folder contains all necessary files to test for the chemsense board. The board needs to be conntected to your computer as shown in the document [link.pdf](../../../../docs/sensorStreamFormat/link.pdf). Target file for the chemsense board is [coresense.ino](./coresense.ino), and this cumulates and parses data into designated format as explained in the document, [sensorStreamFormat.pdf](../../../../docs/sensorStreamFormat/sensorStreamFormat.pdf). The formatted values will be stored in a sub-packet format which is explained also in the sensorStreamFormat.pdf. Please refer the two domucments.

## Tools and equipment required:
* One of each Chemsense, Lightsense, and Airsense borads
* Two ethernet cables and a micro-USB cable
* A computer to test the Chemsense

## Perform a test with the files
When you test with the files, make sure the sensor boards are connected and powered on.

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
