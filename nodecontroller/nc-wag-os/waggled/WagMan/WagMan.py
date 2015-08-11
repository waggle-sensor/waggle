import collections, time, datetime, serial, sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
sys.path.append('../Communications/')
from internal_communicator import send

"""
    This is where parameters for SysMon are defined and communication between node controller and SysMon occurs. 
"""


### I M P O R T A N T ###
# SysMon's timer actually counts every 1.0486 seconds, so any timeouts
# specified here will actually be multiplied by 1.0486.
# However, only integer values may be specified.  Floats are truncated.

########################################################################
#           Edit CORE (SysMon, NC, network switch) parameters here.
#           Do not change the order or number of items.
#           (if you must change it, you need to modify the
#            "get_params_nc()" function in SysMon)
########################################################################
params_core = collections.OrderedDict()

# Min: 1, max: 65535
params_core['baud rate'] = 57600

# Be courteous to the SysMon...it has very little RAM
# Min: total num of chars in each field + 1 for each field
params_core['SysMon RX buffer size (characters)'] = 150

# Min: 1, max: 255
params_core['status report period'] = 3

# SOS boot attempt occurs after a POST failure
# Min: 1, max: 255
params_core['max num of SOS boot attempts'] = 3

# How many times NC and GNs should try to boot if heartbeat is not detected
# Min: 1, max: 255
params_core['max num of subsystem boot attempts'] = 4

# How many times SysMon should try the primary boot sequence if a failure occurs
# Min: 1, max: 255
params_core['max num of primary boot attempts'] = 3

# Non-running devices were shut off due to bad temperature, power, or heartbeat
# Min: 1, max: 65535
params_core['time to wait before rebooting non-running devices (seconds)'] = 20

# Present: 1, not present: 0
params_core['present (ethernet switch)'] = 1

# Min: 1, max: 65535
params_core['boot time for NC (seconds)'] = 30
params_core['first-time config time for NC (seconds)'] = 600
# Min: 1, max: 255
params_core['boot time for ethernet switch (seconds)'] = 3

# Min: 1, max: 255
params_core['heartbeat timeout (NC) (seconds)'] = 5
params_core['heartbeat timeout (switch) (seconds)'] = 3

# Min: 1, max: 255
params_core['bad environment timeout (SysMon) (seconds)'] = 10
params_core['bad environment timeout (NC) (seconds)'] = 15
params_core['bad temperature (processor) timeout (NC) (seconds)'] = 6
params_core['bad temperature timeout (switch) (seconds)'] = 15

# Min: 1, max: 255
params_core['bad current timeout (SysMon) (seconds)'] = 6
params_core['bad current timeout (NC) (seconds)'] = 6
params_core['bad current timeout (switch) (seconds)'] = 6

# Min: -40, max: 125
params_core['temperature min of environment (SysMon) (Celsius)'] = -20
params_core['temperature max of environment (SysMon) (Celsius)'] = 125
params_core['temperature min of environment (NC) (Celsius)'] = -20
params_core['temperature max of environment (NC) (Celsius)'] = 125
# Min: -55, max: 80
params_core['temperature min of processor (NC) (Celsius)'] = -30
params_core['temperature max of processor (NC) (Celsius)'] = 80
params_core['temperature min (switch) (Celsius)'] = -20
params_core['temperature max (switch) (Celsius)'] = 80

# Min: 0, max: 100
params_core['relative humidity min (SysMon) (%)'] = 0
params_core['relative humidity max (SysMon) (%)'] = 100
params_core['relative humidity min (NC) (%)'] = 0
params_core['relative humidity max (NC) (%)'] = 100

# Min: 1, max: 8000
params_core['maximum current draw (SysMon) (mA)'] = 4000
params_core['maximum current draw (NC) (mA)'] = 3000
params_core['maximum current draw (switch) (mA)'] = 1500
########################################################################

########################################################################
#           Edit GUEST NODE parameters here.
#           Do not change the order or number of items.
#           (if you must change it, you need to modify the
#            "get_params_gn()" function in SysMon)
########################################################################
params_GuestNodes = collections.OrderedDict()

# Present: 1, not present: 0
params_GuestNodes['present (GN 1)'] = 1
params_GuestNodes['present (GN 2)'] = 0
params_GuestNodes['present (GN 3)'] = 0

# Min: 1, max: 65535
params_GuestNodes['boot time (GN 1)'] = 3
params_GuestNodes['boot time (GN 2)'] = 12
params_GuestNodes['boot time (GN 3)'] = 12

# If a guest node is not present, its value will be ignored
# Min: 1, max: 255
params_GuestNodes['heartbeat timeout (GN 1) (seconds)'] = 10
params_GuestNodes['heartbeat timeout (GN 2) (seconds)'] = 10
params_GuestNodes['heartbeat timeout (GN 3) (seconds)'] = 10

# If a guest node is not present, its value will be ignored
# Min: 1, max: 255
params_GuestNodes['bad temperature timeout (GN 1) (seconds)'] = 15
params_GuestNodes['bad temperature timeout (GN 2) (seconds)'] = 15
params_GuestNodes['bad temperature timeout (GN 3) (seconds)'] = 15

# If a guest node is not present, its value will be ignored
# Min: 1, max: 255
params_GuestNodes['bad current timeout (GN 1) (seconds)'] = 5
params_GuestNodes['bad current timeout (GN 2) (seconds)'] = 5
params_GuestNodes['bad current timeout (GN 3) (seconds)'] = 5

# If a guest node is not present, its value will be ignored
# Min: -55, max: 80
params_GuestNodes['temperature min (GN 1) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 1) (Celsius)'] = 80
params_GuestNodes['temperature min (GN 2) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 2) (Celsius)'] = 80
params_GuestNodes['temperature min (GN 3) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 3) (Celsius)'] = 80

# If a guest node is not present, its value will be ignored
# Min: 1, max: 8000
params_GuestNodes['maximum current draw (GN 1) (mA)'] = 2500
params_GuestNodes['maximum current draw (GN 2) (mA)'] = 2500
params_GuestNodes['maximum current draw (GN 3) (mA)'] = 2500
########################################################################

########################################################################
#           Lookup table for thermistors
#
#           It is too expensive to convert (mathematically or with a
#           lookup table) the temperature to an ADC value onboard the
#           SysMon, so we do it here and send the appropriate ADC
#           value instead.
########################################################################
thermistor_LUT = collections.OrderedDict()
thermistor_LUT[-55] = 24
thermistor_LUT[-54] = 25
thermistor_LUT[-53] = 27
thermistor_LUT[-52] = 29
thermistor_LUT[-51] = 31
thermistor_LUT[-50] = 33
thermistor_LUT[-49] = 35
thermistor_LUT[-48] = 38
thermistor_LUT[-47] = 40
thermistor_LUT[-46] = 43
thermistor_LUT[-45] = 46
thermistor_LUT[-44] = 49
thermistor_LUT[-43] = 53
thermistor_LUT[-42] = 56
thermistor_LUT[-41] = 60
thermistor_LUT[-40] = 64
thermistor_LUT[-39] = 68
thermistor_LUT[-38] = 72
thermistor_LUT[-37] = 77
thermistor_LUT[-36] = 81
thermistor_LUT[-35] = 86
thermistor_LUT[-34] = 91
thermistor_LUT[-33] = 97
thermistor_LUT[-32] = 103
thermistor_LUT[-31] = 109
thermistor_LUT[-30] = 115
thermistor_LUT[-29] = 121
thermistor_LUT[-28] = 128
thermistor_LUT[-27] = 135
thermistor_LUT[-26] = 142
thermistor_LUT[-25] = 150
thermistor_LUT[-24] = 158
thermistor_LUT[-23] = 166
thermistor_LUT[-22] = 174
thermistor_LUT[-21] = 183
thermistor_LUT[-20] = 192
thermistor_LUT[-19] = 201
thermistor_LUT[-18] = 211
thermistor_LUT[-17] = 220
thermistor_LUT[-16] = 230
thermistor_LUT[-15] = 241
thermistor_LUT[-14] = 251
thermistor_LUT[-13] = 262
thermistor_LUT[-12] = 273
thermistor_LUT[-11] = 284
thermistor_LUT[-10] = 295
thermistor_LUT[-9] = 307
thermistor_LUT[-8] = 319
thermistor_LUT[-7] = 330
thermistor_LUT[-6] = 342
thermistor_LUT[-5] = 355
thermistor_LUT[-4] = 367
thermistor_LUT[-3] = 379
thermistor_LUT[-2] = 392
thermistor_LUT[-1] = 404
thermistor_LUT[0] = 417
thermistor_LUT[1] = 429
thermistor_LUT[2] = 442
thermistor_LUT[3] = 455
thermistor_LUT[4] = 467
thermistor_LUT[5] = 480
thermistor_LUT[6] = 493
thermistor_LUT[7] = 505
thermistor_LUT[8] = 518
thermistor_LUT[9] = 530
thermistor_LUT[10] = 542
thermistor_LUT[11] = 555
thermistor_LUT[12] = 567
thermistor_LUT[13] = 579
thermistor_LUT[14] = 590
thermistor_LUT[15] = 602
thermistor_LUT[16] = 614
thermistor_LUT[17] = 625
thermistor_LUT[18] = 636
thermistor_LUT[19] = 647
thermistor_LUT[20] = 658
thermistor_LUT[21] = 668
thermistor_LUT[22] = 679
thermistor_LUT[23] = 689
thermistor_LUT[24] = 699
thermistor_LUT[25] = 708
thermistor_LUT[26] = 718
thermistor_LUT[27] = 727
thermistor_LUT[28] = 736
thermistor_LUT[29] = 745
thermistor_LUT[30] = 753
thermistor_LUT[31] = 762
thermistor_LUT[32] = 770
thermistor_LUT[33] = 778
thermistor_LUT[34] = 786
thermistor_LUT[35] = 793
thermistor_LUT[36] = 800
thermistor_LUT[37] = 807
thermistor_LUT[38] = 814
thermistor_LUT[39] = 821
thermistor_LUT[40] = 827
thermistor_LUT[41] = 834
thermistor_LUT[42] = 840
thermistor_LUT[43] = 846
thermistor_LUT[44] = 851
thermistor_LUT[45] = 857
thermistor_LUT[46] = 862
thermistor_LUT[47] = 868
thermistor_LUT[48] = 873
thermistor_LUT[49] = 877
thermistor_LUT[50] = 882
thermistor_LUT[51] = 887
thermistor_LUT[52] = 891
thermistor_LUT[53] = 895
thermistor_LUT[54] = 900
thermistor_LUT[55] = 904
thermistor_LUT[56] = 907
thermistor_LUT[57] = 911
thermistor_LUT[58] = 915
thermistor_LUT[59] = 918
thermistor_LUT[60] = 922
thermistor_LUT[61] = 925
thermistor_LUT[62] = 928
thermistor_LUT[63] = 931
thermistor_LUT[64] = 934
thermistor_LUT[65] = 937
thermistor_LUT[66] = 939
thermistor_LUT[67] = 942
thermistor_LUT[68] = 945
thermistor_LUT[69] = 947
thermistor_LUT[70] = 949
thermistor_LUT[71] = 952
thermistor_LUT[72] = 954
thermistor_LUT[73] = 956
thermistor_LUT[74] = 958
thermistor_LUT[75] = 960
thermistor_LUT[76] = 962
thermistor_LUT[77] = 964
thermistor_LUT[78] = 966
thermistor_LUT[79] = 968
thermistor_LUT[80] = 969
########################################################################

########################################################################
#           This function converts the user's specified temperature
#           into an ADC value (via the lookup table) to be sent to
#           SysMon.
########################################################################
def convert_tempToADC(temperature):
    # Check if temperature has a direct match in Lookup Table
    # If yes, return the corresponding value
    if thermistor_LUT.has_key(temperature):
        return thermistor_LUT[temperature]

    # If no, find next highest value
    else:
        index = 0

        # Keep track of previous Key
        prev_key = thermistor_LUT.keys()[0]

        # Iterate through all keys until found temperature is too high
        while index < len(thermistor_LUT.keys()):

            # Find current key we are considering
            current_key = thermistor_LUT.keys()[index]

            # Case 1: we overshot, so take the next highest temperature
            if current_key > temperature:
                return thermistor_LUT[prev_key]

            # Case 2: key is too small, record previous index and continue
            else:
                prev_key = current_key
                index += 1

        # If temperature is higher than highest key, return highest value
        return thermistor_LUT.values()[len(thermistor_LUT)-1]
########################################################################






########################################################################

#Tries to establish connect. Will loop until connection is made.
#TODO May want to send error report to cloud if this happens?
while True: 
    try:
        # Establish serial connection to SysMon
        ser_SysMon = serial.Serial('/dev/arduinoMicro', params_core['baud rate'], timeout = 10)
        #send the signal to SysMon to indicate successful node controller configuration
        ser_SysMon.write("=!")
        break
    except Exception as e:
        print e
########################################################################
#           DO NOT TOUCH ANYTHING BELOW HERE
########################################################################

# Convert user-specified temperatures into ADC values for SysMon
params_core['temperature min of processor (NC) (Celsius)'] = \
    convert_tempToADC(params_core['temperature min of processor (NC) (Celsius)'])
params_core['temperature max of processor (NC) (Celsius)'] = \
    convert_tempToADC(params_core['temperature max of processor (NC) (Celsius)'])
params_core['temperature min (switch) (Celsius)'] = \
    convert_tempToADC(params_core['temperature min (switch) (Celsius)'])
params_core['temperature max (switch) (Celsius)'] = \
    convert_tempToADC(params_core['temperature max (switch) (Celsius)'])
params_GuestNodes['temperature min (GN 1) (Celsius)'] = \
    convert_tempToADC(params_GuestNodes['temperature min (GN 1) (Celsius)'])
params_GuestNodes['temperature max (GN 1) (Celsius)'] = \
    convert_tempToADC(params_GuestNodes['temperature max (GN 1) (Celsius)'])
params_GuestNodes['temperature min (GN 2) (Celsius)'] = \
    convert_tempToADC(params_GuestNodes['temperature min (GN 2) (Celsius)'])
params_GuestNodes['temperature max (GN 2) (Celsius)'] = \
    convert_tempToADC(params_GuestNodes['temperature max (GN 2) (Celsius)'])
params_GuestNodes['temperature min (GN 3) (Celsius)'] = \
    convert_tempToADC(params_GuestNodes['temperature min (GN 3) (Celsius)'])
params_GuestNodes['temperature max (GN 3) (Celsius)'] = \
    convert_tempToADC(params_GuestNodes['temperature max (GN 3) (Celsius)'])

while True:
    # Receive line from SysMon
    incomingNotifier = ser_SysMon.readline().strip()
    print incomingNotifier

    # Did SysMon request parameters?
    if incomingNotifier == "$":
        # Send parameters
        for i in params_core.keys():
            ser_SysMon.write(str(params_core[i]))
            ser_SysMon.write(",")

        # Send terminator
        ser_SysMon.write("!")

    # Is SysMon about to send a status report?
    elif incomingNotifier == "@":
        # Wait for status report
        incomingStatus = ser_SysMon.readline().strip()
        #TODO change this if you no longer want WagMan data to go to Cassandra
        #status report comes in a string of raw data separated by commas
        #need to format status report for Cassandra before sending to cloud. 
        
        #First, convert string into list of raw data
        raw_data = [] #list of raw data
        timestamp, data = incomingStatus.split(',', 1) #get the timestamp
        while not data.find(',') == -1: #loops until it reaches the end of the string
            measurement, data = data.split(',', 1)
            raw_data.append(float(measurement)) #adds measurement to list
            
        #Second, need a human readable list of what the raw data is measuring 
        measuring = ['Light level', 'SysMon current draw','Environment temperature', 'Relative humidity','NC current draw','Temperature of NC processor', 'Enabled?','Running?', 'Current draw (switch)', 'Temperature (switch)',
                     'GN1 enabled?','GN1 running?','GN1 current draw','GN1 temperature','GN2 enabled?','GN2 running?','GN2 current draw','GN2 temperature','GN3 enabled?','GN3 running?','GN3 current draw','GN3 temperature']
        
        #Third, need list of corresponding units
        units = ['ADC value', 'mA','C','%','mA','ADC value','','','mA','ADC value','','','mA','ADC value','','','mA','ADC value','','','mA','ADC value']
       
       #Fourth, specify data types
        data_types = ['f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f']
        
       #Lastly, put it all together in Cassandra accepted format
        status_report = ['WagMan', timestamp, measuring, data_types , raw_data, units, ['']]
       
       #pack status report as waggle message
        packet = packetmaker.make_data_packet(status_report)
       
       #send status report to cloud
        for _pack in packet:
            send(_pack)
        print status_report

    # Is SysMon about to inform me of a problem?
    elif incomingNotifier == "#":
        # Wait for problem report
        incomingProblem = ser_SysMon.readline().strip()
        #TODO change this if you no longer want WagMan data to go to Cassandra
        #problem report comes in a string 
        #need to format problem report for Cassandra before sending to cloud. 
        
        #First, convert string into list 
        report = []
        timestamp, data = incomingProblem.split(',', 1) #get the timestamp
        problem_node, problem = data.split(',', 1) #get node and problem
        
        #Second, make problem easy for human to read and add to report list
        if problem == 'e':
            problem = 'environment'
        elif problem == 'p': 
            problem = 'power'
        elif problem == 't':
            problem = 'temperature'
        elif problem == 'h':
            problem = 'heartbeat'
        
        report.append(problem_node)
        report.append(problem)
        
        #Third, need a human readable list of what this report says
        measuring = ['Node', 'Problem']
        
        #Lastly, put it all together in Cassandra accepted format 
        #TODO may want to add a special Cassandra accepted format for WagMan problem reports that makes more sense
        problem_report = ['WagMan', timestamp, measuring, ['str', 'str'], report, ['',''],['']]
        
        #pack status report as waggle message
        packet = packetmaker.make_data_packet(problem_report)
        #send status report to cloud
        for _pack in packet:
            send(_pack)
        print problem_report

    # Did SysMon request guest node info?
    elif incomingNotifier == "^":
        # Send guest node parameters
        for i in params_GuestNodes.keys():
            ser_SysMon.write(str(params_GuestNodes[i]))
            ser_SysMon.write(",")

    # Did SysMon request the current time?
    elif incomingNotifier == "*":
        # Get current time
        secondsSinceEpoch = time.time()
        timeStamp = datetime.datetime.fromtimestamp(secondsSinceEpoch).strftime('%Y,%m,%d,%H,%M,%S')
        ser_SysMon.write(timeStamp)

        # Send terminator
        ser_SysMon.write("!")

    # Is SysMon about to send me its time?
    elif incomingNotifier == "(":
        # Wait for time message
        incomingTime = ser_SysMon.readline().strip()

        print incomingTime

    # Is SysMon about to shut me down?
    elif incomingNotifier == "?":
        #send Shutdown to datacache to flush messages to file before shutting down.
        print 'Sending flush request to data cache.'
        print incomingNotifier
        send('Flush')

    # Clear incomingNotifier
    incomingNotifier = ''