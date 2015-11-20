#!/bin/python
import time
sensorBoardCalib = {'8fd25951ffff':{"SO2":[100601,1503,179,29.88,[0,15],[1.2,0.5]],
                                    "CO":[100106,1502,51,9.88,[0,2.375],[0.6,0.4]],
                                    "TOX":[100801,1502,802,15.49,[0,0],[0,0]],
                                    "H2S":[100302,1503,530,186.68,[0,0],[0.3,0]],
                                    "TOR":[100601,1503,-5.3,-43.23,[0,0],[0,0]],
                                    "O3":[100401,1503,36,9.02,[0,0],[0,0.5]],
                                    "NO2":[100501,1503,-3,-43.57,[0,-1.6],[1.2,0.5]]}
                    }
sensorListFmt = ["MAC", "HDC_Temp", "HDC_RH", "SHT_Temp", "SHT_RH", "LPS_Temp", "UV", "LPS_Baro", "H2S", "O3", "NO2", "CO", "SO2", "TOX", "TOR", "ETOH"]

data_SHT_Temp_fudge = pow(2,14)
data_SHT_RH_fudge = pow(2,12)

def transform(temperature, rawvalue, sensitivity, baseline):
    nA = float(rawvalue/1425.40783)
    zero = sensor_params[4][temperature>25]
    span = sensor_params[5][temperature>25]
    nazt = baseline+zero*temperature-20
    nact = nA - nazt
    concentration=(1/sensitivity)*nact*(1-span*(temperature-20))
    return concentration

data='Fri Nov 20 22:45:34 2015:8fd25951ffff,0,0,6344,1033,-2078,0,4126690,-256357,-169908,42129,-83501,-526446,-246942,220338,428'

data_date = data.split(':')[:3]
data_time = data_date[0]+':'+data_date[1]+':'+data_date[2]
data_date_pattern = '%a %b %d %H:%M:%S %Y'
data_epoch = int(time.mktime(time.strptime(data_time, data_date_pattern)))

if data_time == time.ctime(data_epoch):
    print "Time of Smapling:", data_epoch
data_data = data.split(':')[3:][0].split(',')
data_data_id = data_data[0]

try:
    for i in range(8):
        print sensorListFmt[i],data_data[i]
        if i == 3:
            data_temperature = -46.85 + (float(data_data[3])*175.72) / data_SHT_Temp_fudge
            print "Temperature in Deg C: ", data_temperature
        if i == 4:
            data_humidity = -6 + (float(data_data[4]) * 125) / data_SHT_RH_fudge
            print "RH in %: ", data_humidity
    for i in range(7):
        print sensorListFmt[i+8],data_data[i+8],sensorBoardCalib[data_data_id][sensorListFmt[i+8]]
        sensor_params = sensorBoardCalib[data_data_id][sensorListFmt[i+8]]
        #do not - zero, span and type1/type2 info
        print "Concentration of ",sensorListFmt[i+8]," - ",transform(data_temperature, float(data_data[i+8]), sensor_params[3], sensor_params[2])

except:
    print "ID not found"


