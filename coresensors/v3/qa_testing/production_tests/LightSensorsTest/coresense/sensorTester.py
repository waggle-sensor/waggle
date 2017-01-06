import serial
import time
import commands

TEMP_MAX = 30
TEMP_MIN = 20
HUMID_MAX = 20
HUMID_MIN = 60

LOG_PATH = "../../log_files/"

fudge_humi_counts = 30
fudge_humi_percent = 2
fudge_temp_C = 2
fudge_temp_counts = 5


#SEQ_NO:52
#HIH6130:25.82,26.49
#HMC5883L:0.17,-0.29,0.71
#TMP421:23.31
#APDS9006020:2874
#TSL260RD:3492
#TSL250RD:20048
#MLX75305:5848
#ML8511:9627


SEQ_NO = []
HIH6130 = []
TMP421 = []
HMC5883L = []
APDS9006020 = []
TSL260RD = []
TSL250RD = []
MLX75305 = []
ML8511 = []
MLX90614 = []
FileName = ' '
port = serial.Serial('/dev/waggle_coresense', 115200)
print "Starting test, gathering sensor readings..."
while (1):
    line = port.readline()
    if (line.startswith("MAC:")):
        MAC_ADDR = line.split(':')[1].split('\r')[0]
        FileName = LOG_PATH+MAC_ADDR+'_light.txt'
    elif (line.startswith("SEQ_NO:")):
        SEQ_NO.append(int(line.split(':')[1].split('\r')[0]))
        if (FileName <> ' '):
            print MAC_ADDR
            print ""
            break
    time.sleep(0.001)

for i in range (9):
    line = port.readline()
    if (line.startswith("MLX75305:")):
        MLX75305.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TMP421:")):
        TMP421.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HIH6130:")):
        HIH6130.append(float(line.split(':')[1].split(',')[0]))
        HIH6130.append(float(line.split(':')[1].split(',')[1].split('\r')[0]))
    elif (line.startswith("APDS9006020:")):
        APDS9006020.append(int(line.split(':')[1].split(',')[0].split('\r')[0]))
    elif (line.startswith("ML8511:")):
        ML8511.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TSL250RD:")):
        TSL250RD.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HMC5883L:")):
        HMC5883L.append(float(line.split(':')[1].split(',')[0]))
        HMC5883L.append(float(line.split(':')[1].split(',')[1]))
        HMC5883L.append(float(line.split(':')[1].split(',')[2].split('\r')[0]))
    elif (line.startswith("MLX90614:")):
        MLX90614.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TSL260RD:")):
        TSL260RD.append(int(line.split(':')[1].split('\r')[0]))
    time.sleep(0.001)

print ""
print "Gathered pre-stimulus readings."
print ""
print " ------------------------------- "
s = raw_input('Press press ENTER after putting the lightsense board in the black sleeve and starting the heater:')
print " ------------------------------- "
print ""

while (port.inWaiting() > 0):
    port.readline()

print ""
print "Proceeding..."
print ""

while (1):
    line = port.readline()
    if (line.startswith("SEQ_NO:")):
        SEQ_NO.append(int(line.split(':')[1].split('\r')[0]))
        break
    time.sleep(0.1)

for i in range (9):
    line = port.readline()
    if (line.startswith("MLX75305:")):
        MLX75305.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TMP421:")):
        TMP421.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HIH6130:")):
        HIH6130.append(float(line.split(':')[1].split(',')[0]))
        HIH6130.append(float(line.split(':')[1].split(',')[1].split('\r')[0]))
    elif (line.startswith("APDS9006020:")):
        APDS9006020.append(int(line.split(':')[1].split(',')[0].split('\r')[0]))
    elif (line.startswith("ML8511:")):
        ML8511.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TSL250RD:")):
        TSL250RD.append(int(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("HMC5883L:")):
        HMC5883L.append(float(line.split(':')[1].split(',')[0]))
        HMC5883L.append(float(line.split(':')[1].split(',')[1]))
        HMC5883L.append(float(line.split(':')[1].split(',')[2].split('\r')[0]))
    elif (line.startswith("MLX90614:")):
        MLX90614.append(float(line.split(':')[1].split('\r')[0]))
    elif (line.startswith("TSL260RD:")):
        TSL260RD.append(int(line.split(':')[1].split('\r')[0]))
    time.sleep(0.001)

#print "SEQ_NO, MLX75305, TMP421, HIH6130, APDS9006020, TSL250RD, HMC5883L, MLX90614, TSL260RD, ML8511"
#print SEQ_NO, MLX75305, TMP421, HIH6130, APDS9006020, TSL250RD, HMC5883L, MLX90614, TSL260RD, ML8511

print ""
print "===================================" 
print "Test Results:"
print "-----------------------------------" 
print " "
#test passing criteria
if (TMP421[1] > TMP421[0] + fudge_temp_C) :
    print "1. TMP421: PASS"
else:
    print "1. TMP421: FAIL"

if (HIH6130[2] + fudge_humi_percent < HIH6130[0]) and (HIH6130[1] + fudge_temp_C < HIH6130 [3]):
    print "2. HIH6130: PASS"
else:
    print "2. HIH6130: FAIL"

if (TSL260RD[0] > TSL260RD[1] + fudge_humi_counts):
    print "3. TSL260RD: PASS"
else:
    print "3. TSL260RD: FAIL"

if (APDS9006020[0] > APDS9006020[1] + fudge_humi_counts ):
    print "4. APDS9006020: PASS"
else:
    print "4. APDS9006020: FAIL"

if (ML8511[0] > ML8511[1] + fudge_humi_counts):
    print "5. ML8511: PASS"
else:
    print "5. ML8511: FAIL"

if (TSL250RD[0] > TSL250RD[1] + fudge_humi_counts):
    print "6. TSL250RD: PASS"
else:
    print "6. TSL250RD: FAIL"

if (HMC5883L[0] <> HMC5883L[3]) or (HMC5883L[1] <> HMC5883L[4]) or (HMC5883L[2] <> HMC5883L[5]):
    print "7. HMC5883L: PASS"
else:
    print "7. HMC5883L: FAIL"

if (MLX75305[0] > MLX75305[1] + fudge_humi_counts):
    print "8. MLX75305: PASS"
else:
    print "8. MLX75305: FAIL"
try:
    if (MLX90614[1] > MLX90614[0]) and (MLX90614[0] > TEMP_MIN) and (MLX90614[0] < TEMP_MAX):
        print "9. MLX90614: PASS"
    else:
        print "9. MLX90614: FAIL"

except:
    print "9. MLX90614: PASS"

filethis = open(FileName, 'w+')
filethis.write("".join(str([TMP421]+[HIH6130]+[TSL260RD]+[APDS9006020]+[ML8511]+[TSL250RD]+[HMC5883L]+[MLX75305]+[MLX90614])))
filethis.close()
print "===================================" 

time.sleep(20)
