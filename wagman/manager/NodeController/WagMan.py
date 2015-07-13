import serial

########################################################################
##            EDIT PARAMETERS HERE
########################################################################
params = {"param1": 23,
          "param2": 5}

# Establish serial connection to SysMon
ser_SysMon = serial.Serial('/dev/ttyACM1', 57600, timeout=10)

# Infinite loop
while True:
    # Receive line from SysMon
    data = ser_SysMon.readline()

    # Strip extra shmutz
    data = data.strip()

    print data

    # Did SysMon request parameters?
    if data == "$":
        # Send parameters
        for i in params.keys():
            # TODO why is it sending the list backwards?
            print "Sending: ", str(params[i])
            ser_SysMon.write(str(params[i]))

        # Send terminator
        ser_SysMon.write("!")