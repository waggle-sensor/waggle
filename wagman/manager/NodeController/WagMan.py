import collections

########################################################################
#           EDIT PARAMETERS HERE.
#           DO NOT CHANGE THE ORDER OR NUMBER OF ITEMS.
#           (if you must change it, you need to modify the
#            "get_params_nc()" function in SysMon)
########################################################################
params = collections.OrderedDict()

# Max: 65535
params['baud rate'] = 57600

# Be courteous to the SysMon...it only has about 1 KB of available RAM
params['SysMon RX buffer size (characters)'] = 150

# Max: 255
params['max num of SOS boot tries'] = 3

# Max: 255
params['heartbeat timeout (NC) (seconds)'] = 5
params['heartbeat timeout (switch) (seconds)'] = 3
params['heartbeat timeout (GN 1) (seconds)'] = 10
params['heartbeat timeout (GN 2) (seconds)'] = 10
params['heartbeat timeout (GN 3) (seconds)'] = 10
params['heartbeat timeout (GN 4) (seconds)'] = 10

# Max: 255
params['bad temperature timeout (SysMon) (seconds)'] = 10
params['bad temperature timeout (NC) (seconds)'] = 15
params['bad temperature timeout (switch) (seconds)'] = 15
params['bad temperature timeout (GN 1) (seconds)'] = 15
params['bad temperature timeout (GN 2) (seconds)'] = 15
params['bad temperature timeout (GN 3) (seconds)'] = 15
params['bad temperature timeout (GN 4) (seconds)'] = 15

# Min: -32768, max: 32767
params['temperature min (SysMon) (Celsius)'] = -20
params['temperature max (SysMon) (Celsius)'] = 140
params['temperature min (NC) (Celsius)'] = -20
params['temperature max (NC) (Celsius)'] = 140
params['temperature min (switch) (Celsius)'] = -20
params['temperature max (switch) (Celsius)'] = 140
params['temperature min (GN 1) (Celsius)'] = -20
params['temperature max (GN 1) (Celsius)'] = 140
params['temperature min (GN 2) (Celsius)'] = -20
params['temperature max (GN 2) (Celsius)'] = 140
params['temperature min (GN 3) (Celsius)'] = -20
params['temperature max (GN 3) (Celsius)'] = 140
params['temperature min (GN 4) (Celsius)'] = -20
params['temperature max (GN 4) (Celsius)'] = 140

# Min: 0, max: 100
params['relative humidity min (SysMon) (%)'] = 0
params['relative humidity max (SysMon) (%)'] = 100
########################################################################






########################################################################
import serial

# Establish serial connection to SysMon
ser_SysMon = serial.Serial('/dev/ttyACM0', params['baud rate'], timeout = 10)

########################################################################
#           DO NOT TOUCH ANYTHING BELOW HERE
########################################################################
while True:
    # Receive line from SysMon
    incomingNotifier = ser_SysMon.readline()

    # Strip extra shmutz
    incomingNotifier = incomingNotifier.strip()

    print "From SysMon: ", incomingNotifier

    # Did SysMon request parameters?
    if incomingNotifier == "$":
        # Send parameters
        for i in params.keys():
            ser_SysMon.write(str(params[i]))
            ser_SysMon.write(",")

        # Send terminator
        ser_SysMon.write("!")

        print "Sent parameters"

    # Is SysMon about to send a status report?
    elif incomingNotifier == "@":
        # Wait for status report
        incomingStatus = ser_SysMon.readline()

        # Strip extra shmutz
        incomingStatus = incomingStatus.strip()

        print incomingStatus

    # Is SysMon about to inform me of a problem?
    elif incomingNotifier == "#":
        # Wait for problem report
        incomingProblem = ser_SysMon.readline()

        # Strip extra shmutz
        incomingProblem = incomingProblem.strip()

        print incomingProblem

    # Clear incomingNotifier
    incomingNotifier = ''