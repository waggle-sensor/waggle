import time, serial, sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
sys.path.append('../Communications/')
from internal_communicator import send

"""
   This connects to a sensor board via a serial connection. It reads and parses the sensor data into meaningful information, packs, and sends the data packet to the cloud. 
   
   
"""
print 'Beginning sensor script...'

Sensor_Index=["D6T_44L_06_1_T_C","MMA8452_1_A_X_Units","MMA8452_1_A_Y_Units",
              "MMA8452_1_A_Z_Units","MMA8452_1_A_RMS_Units","SHT15_1_T_C","SHT15_1_H_%","SHT75_1_T_C",
              "SHT75_1_H_%","MAX4466_1_Units","AMBI_1_Units","PhoRes_10K4.7K_Units","HIH4030_Units",
              "THERMIS_100K_Units","DS18B20_1_T_C","TMP421_1_T_C","RHT03_1_T_C","RHT03_1_H_%",
              "BMP_180_1_T_C","BMP_180_1_P_PA","TMP102_1_T_F","HIH_6130_1_T_C","HIH_6130_1_H_%",
              "MLX90614_T_F"]

reading_names = [ ["Temperature",
                   "Temperature","Temperature","Temperature","Temperature",
                   "Temperature","Temperature","Temperature","Temperature",
                   "Temperature","Temperature","Temperature","Temperature",
                   "Temperature","Temperature","Temperature","Temperature"],
                    "Acceleration",
                    "Acceleration",
                    "Acceleration",
                    "Vibration",
                    "Temperature",
                    "Humidity",
                    "Temperature",
                    "Humidity",
                    "Acoustic_Intensity",
                    "Luminous_Intensity",
                    "Luminous_Intensity",
                    "Humidity",
                    "Temperature",
                    "Temperature",
                    "Temperature",
                    "Temperature",
                    "Humidity",
                    "Temperature",
                    "Pressure",
                    "Temperature",
                    "Temperature",
                    "Humidity",
                    "Temperature"]

reading_type = [['f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f'],
                'f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f']

reading_unit = [["C","C","C","C","C","C","C","C","C","C","C","C","C","C","C","C","C"],
                "g","g","g","g","C","%RH","C","%RH","Units10B0V5","Units10B0V5","Units10B0V5","Units10B0V5",
                "Units10B0V5","C","C","C","%RH","C","PA","F","C","%RH","F"]

reading_note = [["PTAT",
                   "1x1","1x2","1x3","1x4",
                   "2x1","2x2","2x3","2x4",
                   "3x1","3x2","3x3","3x4",
                   "4x1","4x2","4x3","4x4"],
                    "X",
                    "Y",
                    "Z",
                    "RMS_3Axis",
                    "",
                    "RH",
                    "", 
                    "RH",
                    "non-standard",
                    "non-standard",
                    "Voltage_Divider_5V_PDV_Tap_4K7_GND", 
                    "RH",
                    "Voltage_Divider_5V_NTC_Tap_68K_GND",
                    "",
                    "",
                    "",
                    "RH", 
                    "", 
                    "Barometric",
                    "",
                    "", 
                    "", 
                    ""]    

sensor_array_index = [2,7,7,7,7,5,5,12,12,15,14,0,13,3,8,9,10,10,6,6,11,4,4,1]

sensor_names = ["PDV_P8104.API.2006", "MLX90614ESF-DAA.Melexis.008-2013", "D6T-44L-06.Omron.2012", "Thermistor_NTC_PR103J2.US_Sensor.2003", 
        "HIH6130.Honeywell.2011", "SHT15.Sensirion.4_3-2010", "BMP180.Bosch.2_5-2013", "MMA8452Q.Freescale.8_1-2013", 
        "DS18B20.Maxim.2008", "TMP421.Texas_Instruments.2012", "RHT03.Maxdetect.2011", "TMP102.Texas_Instruments.2008", 
        "SHT75.Sensirion.5_2011", "HIH4030.Honeywell.2008", "GA1A1S201WP.Sharp.2007", "MAX4466.Maxim.1_2001"]
try:
    while True:
        wxconnection = False
        while wxconnection == False:
            try:
                wxsensor = serial.Serial('/dev/ttyACM0',57600,timeout=300)
                wxconnection = True
            except:
                #Will not work if sensor board is not plugged in. 
                #If sensor board is plugged in, check to see if it is trying to connect to the right port
                print "Still Waiting for Connection..."
                time.sleep(1)
        try:
            wxsensor.flushInput()
            wxsensor.flushOutput()
        except:
            wxsensor.close()
            wxconnection = False
        while wxconnection == True:
            try:
                readData = ' '
                readData=wxsensor.readline()
            except:
                wxsensor.close()
                wxconnection = False
            if len(readData) > 0 and wxconnection == True:
                try:
                    sensorsData = readData.split(';')
                    if len(sensorsData) > 2:
                        sensorDataAvail = True
                    else:
                        sensorDataAvail = False
                except:
                    sensorDataAvail = False

                if sensorDataAvail == True:
                    if sensorsData[0] == 'WXSensor' and sensorsData[-1]=='WXSensor\r\n':
                        print sensorsData[1:-1]
                        sensorReading_bucket = [[[] for col in range(5)] for row in range(16)]
                        for i in range(len(sensorsData)-2):
                            print sensorsData[i+1]
                            currentSensor = sensorsData[i+1].split(':')
                            if currentSensor[0] <> 'D6T_44L_06_1_T_C':
                                try:
                                    temp_values = float(currentSensor[1])
                                    which_row = sensor_array_index[Sensor_Index.index(currentSensor[0])]
                                    sensorReading_bucket[which_row][0].append(reading_names[Sensor_Index.index(currentSensor[0])])
                                    sensorReading_bucket[which_row][1].append(reading_type[Sensor_Index.index(currentSensor[0])])
                                    sensorReading_bucket[which_row][2].append(temp_values)
                                    sensorReading_bucket[which_row][3].append(reading_unit[Sensor_Index.index(currentSensor[0])])
                                    sensorReading_bucket[which_row][4].append(reading_note[Sensor_Index.index(currentSensor[0])])
                                except:
                                    pass
                            else:
                                pass
                                try:
                                    temp_values=currentSensor[1].split(',')
                                    for k in range(len(temp_values)):
                                        temp_values[k] = float(temp_values[k])
                                    which_row = sensor_array_index[Sensor_Index.index(currentSensor[0])]
                                    sensorReading_bucket[which_row][0]=list(reading_names[Sensor_Index.index(currentSensor[0])])
                                    sensorReading_bucket[which_row][1]=list(reading_type[Sensor_Index.index(currentSensor[0])])
                                    sensorReading_bucket[which_row][2]=list(temp_values)
                                    sensorReading_bucket[which_row][3]=list(reading_unit[Sensor_Index.index(currentSensor[0])])
                                    sensorReading_bucket[which_row][4]=list(reading_note[Sensor_Index.index(currentSensor[0])])
                                except:
                                    pass
                        for all in range(len(sensorReading_bucket)):
                            if (sensorReading_bucket[all] <> [[],[],[],[],[]]):
                                sendData=[sensor_names[all],int(time.time()),sensorReading_bucket[all][0],sensorReading_bucket[all][1],sensorReading_bucket[all][2],sensorReading_bucket[all][3],sensorReading_bucket[all][4]]
                                #print sendData
                                #packs and sends the data
                                packet = packetmaker.make_data_packet(sendData)
                                for pack in packet:
                                    send(pack)
                        time.sleep(1)
except KeyboardInterrupt, k:
    try:
        wxsensor.close()
    except: 
        pass