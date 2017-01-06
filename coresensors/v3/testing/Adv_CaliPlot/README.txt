
This codes are for ploting calibration data.
Basically, if you put at least one downloaded file from the Beehive server, the result will be time-data plots for all sensors, absolute humidity, and temperature difference between some temperature sensors.

The usage is this:
python3 server_parse.py args

There is no limit on the number of args, but it takes more time as the number of the args increases.
Name of downloaded file from Beehive server must be "nodeID_date", and reference data file must contains a word "ref" to be classified in the codes.
If reference sensor data files are included in args(which are the files contain the word "ref"), it will plot sensor data-reference data plot for temperature, relative humidity, absolute humidity, and pressure.

The configuration of the codes are like this:
a. server_parse.py: call all the other classes and functions and plot data
b. pre_calc.py: do some conversions for temperature, light, pressure, etc.
	b'. RTlist.py: converse raw PR103J2 data to temperature.
c. data_storing.py: store all the data in a dictionary for time-data plot.
d. post_processes.py: calculate absolute humidity and temperature difference between sensor data.
e. two_dimensinal.py: create another dictionary for sensor data-reference data plot.
f. plot_class.py: do time-data plot using javascript.
g. two_dimen_plot.py: do sensor-reference plot using javascript.

As a result, a html file will be created, and this can be sent or copyed independently to share the result.

Since some of data are raw register or raw voltage reading from the sesnor, pre_calc.py will generate new files which have an "_" in front of the original file name, and the new files will be used in processes after.
