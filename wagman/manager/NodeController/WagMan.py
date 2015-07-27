import collections
import time
import datetime

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
params_core['status report period'] = 10

# Min: 1, max: 255
params_core['max num of SOS boot attempts'] = 3

# How many times NC and GNs should try to boot
# Min: 1, max: 255
params_core['max num of subsystem boot attempts'] = 4

# Min: 1, max: 65535
params_core['boot time for NC (seconds)'] = 10
# Min: 1, max: 255
params_core['boot time for ethernet switch (seconds)'] = 6

# Min: 1, max: 255
params_core['heartbeat timeout (NC) (seconds)'] = 5
params_core['heartbeat timeout (switch) (seconds)'] = 3

# Min: 1, max: 255
params_core['bad temperature timeout (SysMon) (seconds)'] = 10
params_core['bad temperature timeout (NC) (seconds)'] = 15
params_core['bad temperature timeout (switch) (seconds)'] = 15

# Min: 1, max: 255
params_core['bad current timeout (SysMon) (seconds)'] = 6
params_core['bad current timeout (NC) (seconds)'] = 6
params_core['bad current timeout (switch) (seconds)'] = 6

# Min: 15, max: 8000
params_core['noise ceiling for current sensors (mA)'] = 15

# Min: -32768, max: 32767
params_core['temperature min (SysMon) (Celsius)'] = -20
params_core['temperature max (SysMon) (Celsius)'] = 140
params_core['temperature min (NC) (Celsius)'] = -20
params_core['temperature max (NC) (Celsius)'] = 140
params_core['temperature min (switch) (Celsius)'] = -20
params_core['temperature max (switch) (Celsius)'] = 140

# Min: 0, max: 100
params_core['relative humidity min (SysMon) (%)'] = 0
params_core['relative humidity max (SysMon) (%)'] = 100

# Min: 1, max: 8000
params_core['maximum current draw (SysMon) (mA)'] = 500
params_core['maximum current draw (NC) (mA)'] = 4000
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
params_GuestNodes['boot time (GN 1)'] = 12
params_GuestNodes['boot time (GN 2)'] = 12
params_GuestNodes['boot time (GN 3)'] = 12

# Min: 1, max: 255
# If a guest node is not present, its value will be ignored
params_GuestNodes['heartbeat timeout (GN 1) (seconds)'] = 10
params_GuestNodes['heartbeat timeout (GN 2) (seconds)'] = 10
params_GuestNodes['heartbeat timeout (GN 3) (seconds)'] = 10

# Min: 1, max: 255
# If a guest node is not present, its value will be ignored
params_GuestNodes['bad temperature timeout (GN 1) (seconds)'] = 15
params_GuestNodes['bad temperature timeout (GN 2) (seconds)'] = 15
params_GuestNodes['bad temperature timeout (GN 3) (seconds)'] = 15

# Min: 1, max: 255
# If a guest node is not present, its value will be ignored
params_GuestNodes['bad current timeout (GN 1) (seconds)'] = 5
params_GuestNodes['bad current timeout (GN 2) (seconds)'] = 5
params_GuestNodes['bad current timeout (GN 3) (seconds)'] = 5

# Min: -32768, max: 32767
# If a guest node is not present, its value will be ignored
params_GuestNodes['temperature min (GN 1) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 1) (Celsius)'] = 140
params_GuestNodes['temperature min (GN 2) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 2) (Celsius)'] = 140
params_GuestNodes['temperature min (GN 3) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 3) (Celsius)'] = 140

# Min: 1, max: 8000
# If a guest node is not present, its value will be ignored
params_GuestNodes['maximum current draw (GN 1) (mA)'] = 4000
params_GuestNodes['maximum current draw (GN 2) (mA)'] = 4000
params_GuestNodes['maximum current draw (GN 3) (mA)'] = 4000
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
thermistor_LUT[-55] = 0
thermistor_LUT[-54] = 41
thermistor_LUT[-53] = 110
thermistor_LUT[-52] = 175
thermistor_LUT[-51] = 234
thermistor_LUT[-50] = 289
thermistor_LUT[-49] = 339
thermistor_LUT[-48] = 386
thermistor_LUT[-47] = 430
thermistor_LUT[-46] = 470
thermistor_LUT[-45] = 507
thermistor_LUT[-44] = 541
thermistor_LUT[-43] = 573
thermistor_LUT[-42] = 603
thermistor_LUT[-41] = 630
thermistor_LUT[-40] = 656
thermistor_LUT[-39] = 679
thermistor_LUT[-38] = 701
thermistor_LUT[-37] = 722
thermistor_LUT[-36] = 741
thermistor_LUT[-35] = 759
thermistor_LUT[-34] = 775
thermistor_LUT[-33] = 790
thermistor_LUT[-32] = 805
thermistor_LUT[-31] = 818
thermistor_LUT[-30] = 831
thermistor_LUT[-29] = 842
thermistor_LUT[-28] = 853
thermistor_LUT[-27] = 863
thermistor_LUT[-26] = 873
thermistor_LUT[-25] = 882
thermistor_LUT[-24] = 890
thermistor_LUT[-23] = 898
thermistor_LUT[-22] = 905
thermistor_LUT[-21] = 912
thermistor_LUT[-20] = 918
thermistor_LUT[-19] = 924
thermistor_LUT[-18] = 930
thermistor_LUT[-17] = 935
thermistor_LUT[-16] = 940
thermistor_LUT[-15] = 945
thermistor_LUT[-14] = 949
thermistor_LUT[-13] = 953
thermistor_LUT[-12] = 957
thermistor_LUT[-11] = 960
thermistor_LUT[-10] = 964
thermistor_LUT[-9] = 967
thermistor_LUT[-8] = 970
thermistor_LUT[-7] = 973
thermistor_LUT[-6] = 975
thermistor_LUT[-5] = 978
thermistor_LUT[-4] = 980
thermistor_LUT[-3] = 983
thermistor_LUT[-2] = 985
thermistor_LUT[-1] = 987
thermistor_LUT[0] = 989
thermistor_LUT[1] = 990
thermistor_LUT[2] = 992
thermistor_LUT[3] = 993
thermistor_LUT[4] = 995
thermistor_LUT[5] = 996
thermistor_LUT[6] = 998
thermistor_LUT[7] = 999
thermistor_LUT[8] = 1000
thermistor_LUT[9] = 1001
thermistor_LUT[10] = 1002
thermistor_LUT[11] = 1003
thermistor_LUT[12] = 1004
thermistor_LUT[13] = 1005
thermistor_LUT[14] = 1006
thermistor_LUT[15] = 1007
thermistor_LUT[17] = 1008
thermistor_LUT[18] = 1009
thermistor_LUT[20] = 1010
thermistor_LUT[21] = 1011
thermistor_LUT[23] = 1012
thermistor_LUT[25] = 1013
thermistor_LUT[28] = 1014
thermistor_LUT[30] = 1015
thermistor_LUT[33] = 1016
thermistor_LUT[37] = 1017
thermistor_LUT[41] = 1018
thermistor_LUT[46] = 1019
thermistor_LUT[52] = 1020
thermistor_LUT[62] = 1021
thermistor_LUT[76] = 1022
thermistor_LUT[80] = 1023
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
import serial

# Establish serial connection to SysMon
ser_SysMon = serial.Serial('/dev/arduinoMicro', params_core['baud rate'], timeout = 10)
########################################################################
#           DO NOT TOUCH ANYTHING BELOW HERE
########################################################################

# Convert user-specified temperatures into ADC values for SysMon
params_core['temperature min (SysMon) (Celsius)'] = \
    convert_tempToADC(params_core['temperature min (SysMon) (Celsius)'])
params_core['temperature max (SysMon) (Celsius)'] = \
    convert_tempToADC(params_core['temperature max (SysMon) (Celsius)'])
params_core['temperature min (NC) (Celsius)'] = \
    convert_tempToADC(params_core['temperature min (NC) (Celsius)'])
params_core['temperature max (NC) (Celsius)'] = \
    convert_tempToADC(params_core['temperature max (NC) (Celsius)'])
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

    # Is SysMon about to inform me of a problem?
    elif incomingNotifier == "#":
        # Wait for problem report
        incomingProblem = ser_SysMon.readline().strip()

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

    # Clear incomingNotifier
    incomingNotifier = ''