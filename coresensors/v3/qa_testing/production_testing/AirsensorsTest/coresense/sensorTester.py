import serial
import time
import commands

TEMP_MAX = 35
TEMP_MIN = 20
HUMID_MAX = 0
HUMID_MIN = 100
LOG_PATH = "/tmp/"

SEQ_NO = []
SPV1840LR5HB = []
TMP112 = []
HTU21D = []
BMP180 = []
PR103J2 = []
TSL250RD = []
MMA8452Q = []
TSYS01 = []
HIH4030 = []
FileName = ' '
port = serial.Serial('/dev/waggle_coresense', 115200)
print "Starting test, gathering sensor readings..."
while (1):
    line = port.readline()
    if (line.startswith("MAC:")):
        MAC_ADDR = line.split(':')[1].split('\r')[0]
        FileName = LOG_PATH+MAC_ADDR+'_air.txt'
    elif (line.startswith("SEQ_NO:")):
        SEQ_NO.append(int(line.split(':')[1].split('\r')[0]))
        if (FileName <> ' '):
            print FileName
            break
    time.sleep(0.1)

for i in range (9):
    line = port.readline()
    if (line.startswith("SPV1840LR5HB:")):
        SPV1840LR5HB.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TMP112:")):
        TMP112.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HTU21D:")):
        HTU21D.append(float(line.split(':')[1].split(',')[0]))
        HTU21D.append(float(line.split(':')[1].split(',')[1].split('\r')[0]))
    elif (line.startswith("BMP180:")):
        BMP180.append(float(line.split(':')[1].split(',')[0]))
        BMP180.append(int(line.split(':')[1].split(',')[1].split('\r')[0]))
    elif (line.startswith("PR103J2:")):
        PR103J2.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TSL250RD:")):
        TSL250RD.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("MMA8452Q:")):
        MMA8452Q.append(float(line.split(':')[1].split(',')[0]))
        MMA8452Q.append(float(line.split(':')[1].split(',')[1]))
        MMA8452Q.append(float(line.split(':')[1].split(',')[2].split('\r')[0]))
    elif (line.startswith("TSYS01:")):
        TSYS01.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HIH4030:")):
        HIH4030.append(int(line.split(':')[1].split('\r')[0]))

print SEQ_NO, SPV1840LR5HB, TMP112, HTU21D, BMP180, TSL250RD, MMA8452Q, TSYS01, HIH4030, PR103J2
print "Gathered pre-stimulus readings."
s = raw_input('Press enter after turning the board upside down and starting the heater:')

while (port.inWaiting() > 0):
    port.readline()

print "Proceeding..."

while (1):
    line = port.readline()
    if (line.startswith("SEQ_NO:")):
        SEQ_NO.append(int(line.split(':')[1].split('\r')[0]))
        break
    time.sleep(0.1)

for i in range (9):
    line = port.readline()
    if (line.startswith("SPV1840LR5HB:")):
        SPV1840LR5HB.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TMP112:")):
        TMP112.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HTU21D:")):
        HTU21D.append(float(line.split(':')[1].split(',')[0]))
        HTU21D.append(float(line.split(':')[1].split(',')[1].split('\r')[0]))
    elif (line.startswith("BMP180:")):
        BMP180.append(float(line.split(':')[1].split(',')[0]))
        BMP180.append(int(line.split(':')[1].split(',')[1].split('\r')[0]))
    elif (line.startswith("PR103J2:")):
        PR103J2.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TSL250RD:")):
        TSL250RD.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("MMA8452Q:")):
        MMA8452Q.append(float(line.split(':')[1].split(',')[0]))
        MMA8452Q.append(float(line.split(':')[1].split(',')[1]))
        MMA8452Q.append(float(line.split(':')[1].split(',')[2].split('\r')[0]))
    elif (line.startswith("TSYS01:")):
        TSYS01.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HIH4030:")):
        HIH4030.append(int(line.split(':')[1].split('\r')[0]))
    time.sleep(0.001)

print "SEQ_NO, SPV1840LR5HB, TMP112, HTU21D, BMP180, TSL250RD, MMA8452Q, TSYS01, HIH4030, PR103J2"
print SEQ_NO, SPV1840LR5HB, TMP112, HTU21D, BMP180, TSL250RD, MMA8452Q, TSYS01, HIH4030, PR103J2

print "Test Results:"
#test passing criteria
if (TMP112[1] > TMP112[0]) :
    print "1. TMP112: PASS"
else:
    print "1. TMP112: FAIL"

if (HTU21D[2] > HTU21D[0]) and (HTU21D[1] > HTU21D [3]):
    print "2. HTU21D: PASS"
else:
    print "2. HTU21D: FAIL"

if (HIH4030[0] > HIH4030[1]):
    print "3. HIH4030: PASS"
else:
    print "3. HIH4030: FAIL"

if (BMP180[2] > BMP180[0]) and (BMP180[1] > 98000) and (BMP180[1] < 120000) and (BMP180[3] > 98000) and (BMP180[3] < 120000):
    print "4. BMP180: PASS"
else:
    print "4. BMP180: FAIL"

if (PR103J2[0] < PR103J2[1]):
    print "5. PR103J2: PASS"
else:
    print "5. PR103J2: FAIL"

if (TSL250RD[0] > TSL250RD[1]) and (TSL250RD[1] < 200) and (TSL250RD[0] > 400):
    print "6. TSL250RD: PASS"
else:
    print "6. TSL250RD: FAIL"

if (MMA8452Q[2] > 0) and (MMA8452Q[5] < 0):
    print "7. MMA8452Q: PASS"
else:
    print "7. MMA8452Q: FAIL"

if (SPV1840LR5HB[0] > 200):
    print "8. SPV1840LR5HB: PASS"
else:
    print "8. SPV1840LR5HB: FAIL"

if (TSYS01[1] > TSYS01[0]):
    print "9. TSYS01: PASS"
else:
    print "9. TSYS01: FAIL"

filethis = open(FileName, 'w+')
filethis.write("".join(str([TMP112]+[HTU21D]+[HIH4030]+[BMP180]+[PR103J2]+[TSL250RD]+[MMA8452Q]+[SPV1840LR5HB]+[TSYS01])))
filethis.close()


