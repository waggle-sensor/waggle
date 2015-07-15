#!/usr/bin/env python

from time import gmtime, strftime
import random
from commands import getoutput as bashit

current_time = strftime("%m/%d/%y %H:%M:%S", gmtime())
Temperature_value = random.uniform(-40,60)
Temp_C = str("{0:.2f}".format(Temperature_value))
print "Temp_C: ", Temperature_value, " Total: ", Temperature_value*16
Temp_F = str("{0:.2f}".format(Temperature_value * 1.8 + 31))

# Simulated data for each of the sensors.
sensors = {
	'MLX90614ESF' : {
		'name' : 'MLX90614ESF-DAA.Melexis.008-2013',
		'data': 'Temperature;' + Temp_F + ';F;none'
	},
	'TMP421' : {
		'name' : 'TMP421.Texas_Instruments.2012',
		'data': 'Temperature;' + Temp_C + ';C;none'
	},
	'BMP180' : {
		'name' : 'BMP180.Bosch.2_5-2013',
		'data': 'Temperature;' + Temp_C + ';C;none,Pressure;' + str(random.uniform(999120,1000000)) + ';PA;Barometric'
	},
	'MMA8452Q' : {
		'name' : 'MMA8452Q.Freescale.8_1-2013',
		'data': 'Acceleration;' + str("{0:.2f}".format(random.uniform(-10,10))) + ';g;X,Acceleration;' + str("{0:.2f}".format(random.uniform(-10,10))) + ';g;Y,Acceleration;' + str("{0:.2f}".format(random.uniform(-10,10))) + ';g;Z,Vibration;' + str("{0:.2f}".format(random.uniform(0,10))) + ';g;RMS_3Axis'
	},
	'PDV_P8104' : {
		'name' : 'PDV_P8104.API.2006',
		'data': 'Luminous_Intensity;' + str(random.randint(0,1024)) + ';Units10B0V5;Voltage_Divider_5V_PDV_Tap_4K7_GND'
	},
	'PR103J2' : {
		'name' : 'Thermistor_NTC_PR103J2.US_Sensor.2003',
		'data': 'Temperature;' + str(random.randint(0,1024)) + ';Units10B0V5;Voltage_Divider_5V_NTC_Tap_68K_GN'
	},
	'HIH6130' : {
		'name' : 'HIH6130.Honeywell.2011',
		'data': 'Temperature;' + Temp_C + ';C;none,Humidity;' + str(random.randint(0,1024)) + ';%RH;none'
	},
	'SHT15' : {
		'name' : 'SHT15.Sensirion.4_3-2010',
		'data': 'Temperature;' + Temp_C + ';C;none,Humidity;' + str(random.randint(0,1024)) + ';%RH;RH'
	},
	'HTU21D' : {
		'name' : 'HTU21D.MeasSpec.2013',
		'data': 'Temperature;' + Temp_C + ';C;none,Humidity;' + str(random.randint(0,1024)) + ';%RH;RH'
	},
	'DS18B20' : {
		'name' : 'DS18B20.Maxim.2008',
		'data': 'Temperature;' + Temp_C + ';C;none'
	},
	'RHT03' : {
		'name' : 'RHT03.Maxdetect.2011',
		'data': 'Temperature;' + Temp_C + ';C;none,Humidity;' + str(random.randint(0,1024)) + ';%RH;RH'
	},
	'TMP102' : {
		'name' : 'TMP102.Texas_Instruments.2008',
		'data': 'Temperature;' + Temp_F + ';F;none'
	},
	'SHT75' : {
		'name' : 'SHT75.Sensirion.5_2011',
		'data': 'Temperature;' + Temp_C + ';C;none,Humidity;' + str(random.randint(0,1024)) + ';%RH;RH'
	},
	'HIH4030' : {
		'name' : 'HIH4030.Honeywell.2008',
		'data': 'Humidity;' + str(random.randint(0,1024)) + ';Units10B0V5;RH'
	},
	'GA1A1S201WP' : {
		'name' : 'GA1A1S201WP.Sharp.2007',
		'data': 'Luminous_Intensity;' + str(random.randint(0,1024)) + ';Units10B0V5;non-standard'
	},
	'MAX4466' : {
		'name' : 'MAX4466.Maxim.2001',
		'data': 'Acoustic_Intensity;' + str(random.randint(0,1024)) + ';Units10B0V5;non-standard'
	},
	'D6T44L06' : {
		'name' : 'D6T-44L-06.Omron.2012',
		'data': 'Temperature;' + Temp_C + ';C;PTAT,Temperature;' + Temp_C + ';C;1x1,Temperature;' + Temp_C + ';C;1x2,Temperature;' + Temp_C + ';C;1x3,Temperature;' + Temp_C + ';C;1x4,Temperature;' + Temp_C + ';C;2x1,Temperature;' + Temp_C + ';C;2x2,Temperature;' + Temp_C + ';C;2x3,Temperature;' + Temp_C + ';C;2x4,Temperature;' + Temp_C + ';C;3x1,Temperature;' + Temp_C + ';C;3x2,Temperature;' + Temp_C + ';C;3x3,Temperature;' + Temp_C + ';C;3x4,Temperature;' + Temp_C + ';C;4x1,Temperature;' + Temp_C + ';C;4x2,Temperature;' + Temp_C + ';C;4x3,Temperature;' + Temp_C + ';C;4x4'
	},
	'HMC5883' : {
		'name' : 'HMC5883.Honeywell.2013',
		'data': 'Magnetic_Field;' + str("{0:.2f}".format(random.uniform(-8,8))) + ';gauss;X,Magnetic_Field;' + str("{0:.2f}".format(random.uniform(-8,8))) + ';gauss;Y,Magnetic_Field;' + str("{0:.2f}".format(random.uniform(-8,8))) + ';gauss;Z'
	}
}

def getData(sensorName):
	return sensors[sensorName]['name'] + ',' + current_time + ',' + sensors[sensorName]['data'] + '\n'

# -----------------------------------------------
# Overwrite the file containing the current data.
try:
    currentFilePtr = open('./current/current', 'w+')
except:
    bashit('mkdir current')
    currentFilePtr = open('./current/current', 'w+')

for sensor in sensors.keys():
	currentFilePtr.write(getData(sensor))

currentFilePtr.close()

# ------------------------------------------------
# Append the latest data to the files containing historical data for each sensor.
#try:
#    historical_prt = open('./historical/BMP180', 'a+')
#except:
#    bashit('mkdir historical')

#for sensor in sensors.keys():
#	historical_prt = open('./historical/' + sensors[sensor]['name'], 'a+')
#	historical_prt.write(getData(sensor))
#	historical_prt.close()
