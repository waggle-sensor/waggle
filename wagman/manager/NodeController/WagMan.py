import collections

########################################################################
#           Edit CORE (SysMon, NC, network switch) parameters here.
#           Do not change the order or number of items.
#           (if you must change it, you need to modify the
#            "get_params_nc()" function in SysMon)
########################################################################
params_SysMon = collections.OrderedDict()

# Min: 1, max: 65535
params_SysMon['baud rate'] = 57600

# Be courteous to the SysMon...it only has about 1 KB of available RAM
# Min: total num of chars in each field + 1 for each field
params_SysMon['SysMon RX buffer size (characters)'] = 150

# Min: 1, max: 255
params_SysMon['max num of SOS boot tries'] = 3

# Min: 1, max: 255
params_SysMon['heartbeat timeout (NC) (seconds)'] = 5
params_SysMon['heartbeat timeout (switch) (seconds)'] = 3

# Min: 1, max: 255
params_SysMon['bad temperature timeout (SysMon) (seconds)'] = 10
params_SysMon['bad temperature timeout (NC) (seconds)'] = 15
params_SysMon['bad temperature timeout (switch) (seconds)'] = 15

# Min: 1, max: 255
params_SysMon['bad current timeout (SysMon) (seconds)'] = 6
params_SysMon['bad current timeout (NC) (seconds)'] = 6
params_SysMon['bad current timeout (switch) (seconds)'] = 6

# Min: 15, max: 8000
params_SysMon['noise ceiling for current sensors (mA)'] = 15

# Min: -32768, max: 32767
params_SysMon['temperature min (SysMon) (Celsius)'] = -20
params_SysMon['temperature max (SysMon) (Celsius)'] = 140
params_SysMon['temperature min (NC) (Celsius)'] = -20
params_SysMon['temperature max (NC) (Celsius)'] = 140
params_SysMon['temperature min (switch) (Celsius)'] = -20
params_SysMon['temperature max (switch) (Celsius)'] = 140

# Min: 0, max: 100
params_SysMon['relative humidity min (SysMon) (%)'] = 0
params_SysMon['relative humidity max (SysMon) (%)'] = 100

# Min: 1, max: 8000
params_SysMon['maximum current draw (SysMon) (mA)'] = 200
params_SysMon['maximum current draw (NC) (mA)'] = 4000
params_SysMon['maximum current draw (switch) (mA)'] = 1500
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
import serial

# Establish serial connection to SysMon
ser_SysMon = serial.Serial('/dev/arduinoMicro', params_SysMon['baud rate'], timeout = 10)
########################################################################
#           DO NOT TOUCH ANYTHING BELOW HERE
########################################################################
while True:
    # Receive line from SysMon
    incomingNotifier = ser_SysMon.readline()

    # Strip extra shmutz
    incomingNotifier = incomingNotifier.strip()

    print incomingNotifier

    # Did SysMon request parameters?
    if incomingNotifier == "$":
        # Send parameters
        for i in params_SysMon.keys():
            ser_SysMon.write(str(params_SysMon[i]))
            ser_SysMon.write(",")

        # Send terminator
        ser_SysMon.write("!")

    # Is SysMon about to send a status report?
    elif incomingNotifier == "@":
        # Wait for status report
        incomingStatus = ser_SysMon.readline()

        # Strip extra shmutz
        incomingStatus = incomingStatus.strip()

    # Is SysMon about to inform me of a problem?
    elif incomingNotifier == "#":
        # Wait for problem report
        incomingProblem = ser_SysMon.readline()

        # Strip extra shmutz
        incomingProblem = incomingProblem.strip()

    # Did SysMon request guest node info?
    elif incomingNotifier == "^":
        # Send guest node parameters
        for i in params_GuestNodes.keys():
            ser_SysMon.write(str(params_GuestNodes[i]))
            ser_SysMon.write(",")

        # Send terminator
        ser_SysMon.write("!")

    # Clear incomingNotifier
    incomingNotifier = ''