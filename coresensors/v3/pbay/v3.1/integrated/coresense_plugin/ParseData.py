# read line

flag_TIME = False
flag_NAME = False
flag_SIGN = False

SIGN = "-------------"
FILE_NAME = "data.txt"  #Need to change file name

#**************************************************
#NAME = "TMP112"
#NAME = "HTU21D"
#NAME = "BMP180"
#NAME = "PR103J2"
#NAME = "MMA8452Q"
#NAME = "HMC5883L"
#NAME = "HIH6130"
#NAME = "APDS-9006-020"
#NAME = "TSL260RD"
#NAME = "TSL250RD"
#NAME = "MLX75305"
#NAME = "ML8511"
#NAME = "TMP421"

#NAME = "Intel MAC"
#NAME = "SHT25"
#NAME = "LPS25H"
#NAME = "Si1145"

#NAME = "Total reducing gases"
#NAME = "Total Oxidizing gases"
#NAME = "Sulfur Dioxide"
#NAME = "Hydrogen Sulphide"
#NAME = "Ozone"
#NAME = "Nitrogen Di-oxide"
#NAME = "Carbon Monoxide"

NAME = "CO ADC temp"
#NAME = "IAQ/IRR ADC temp"
#NAME = "O3/NO2 ADC temp"
#NAME = "SO2/H2S ADC temp"
#NAME = "CO LMP temp"

#NAME = "Accelerometer"
#NAME = "Gyroscope"
#**************************************************

if NAME == "TMP112":
    TITLE = "TMP112"
    num = 1
elif NAME == "HTU21D":
    TITLE = "HTU21D"
    num = 2
elif NAME == "BMP180":
    TITLE = "BMP180"
    num = 2
elif NAME == "PR103J2":
    TITLE = "PR103J2"
    num = 1
elif NAME == "MMA8452Q":
    TITLE = "MMA8452Q"
    num = 4
elif NAME == "HMC5883L":
    TITLE = "HMC5883L"
    num = 3
elif NAME == "HIH6130":
    TITLE = "HIH6130"
    num = 2
elif NAME == "APDS-9006-020":
    TITLE = "APDS_9006_020"
    num = 1
elif NAME == "TSL260RD":
    TITLE = "TSL260RD"
    num = 1
elif NAME == "TSL250RD":
    TITLE = "TSL250RD"
    num = 1
elif NAME == "MLX75305":
    TITLE = "MLX75305"
    num = 1
elif NAME == "ML8511":
    TITLE = "ML8511"
    num = 1
elif NAME == "TMP421":
    TITLE = "TMP421"
    num = 1
    
elif NAME == "SHT25":
    TITLE = "SHT25"
    num = 2
elif NAME == "LPS25H":
    TITLE = "LPS25H"
    num = 2
elif NAME == "Si1145":
    TITLE = "Si1145"
    num = 3

elif NAME == "Total reducing gases":
    TITLE = "TotalReducing"
    num = 1
elif NAME == "Total Oxidizing gases":
    TITLE = "TotalOxidizing"
    num = 1
elif NAME == "Sulfur Dioxide":
    TITLE = "SulfurDioxide"
    num = 1
elif NAME == "Hydrogen Sulphide":
    TITLE = "HydrogenSulphide"
    num = 1
elif NAME == "Ozone":
    TITLE = "Ozone"
    num = 1
elif NAME == "Nitrogen Di-oxide":
    TITLE = "NitrogenDiOxide"
    num = 1
elif NAME == "Carbon Monoxide":
    TITLE = "CarbonMonoxide"
    num = 1

elif NAME == "CO ADC temp":
    TITLE = "CO_ADCtemp"
    num = 1
elif NAME == "IAQ/IRR ADC temp":
    TITLE = "IAQ_IRR_ADCtemp"
    num = 1
elif NAME == "O3/NO2 ADC temp":
    TITLE = "O3_NO2_ADCtemp"
    num = 1
elif NAME == "SO2/H2S ADC temp":
    TITLE = "SO2_H2S_ADCtemp"
    num = 1
elif NAME == "CO LMP temp":
    TITLE = "CO_LMPtemp"
    num = 1

elif NAME == "Accelerometer":
    TITLE = "Accelerometer"
    num = 4
elif NAME == "Gyroscope":
    TITLE = "Gyroscope"
    num = 4
else:
    print "Wrong NAME"


MAX_trial = 8

#data_file = open("temp.txt", "r+")
sub_file = open("sub" + TITLE + ".txt", "w+")

try:
    #line = data_file.readline()
    sub_file.write(str(num))
    sub_file.write('\n')
    
    with open(FILE_NAME) as data_file:
        #print num
        for line in data_file:
            #print line
            
            #if TIME in line:
            if flag_SIGN == True:
                #print line
                one = line.split(" ")
                
                if len(one) > 4:
                    month = one[1]
                    day = one[3]
                    time = one[4]
                    year = one[5]
                    flag_TIME = True
                flag_SIGN = False

            elif SIGN in line:
                flag_SIGN = True

            elif NAME in line:
                two = line.split(" ")
                #print two
                if flag_TIME == False:
                    break
                for i in range (0, MAX_trial):
                    k = i
                    if two[i] == "@":
                        i = i + 2
                        for j in range (0, num):
                            one[j] = two[i + j]
                            #last_two = i + j
                            #last_val = j
                            #print "if"
                            #print one[j]
                        #tmp = two[last_two].split("\n")
                        #one[last_val] = tmp[0]
                        #print one[last_val]
                        flag_NAME = True
                        break

            if flag_TIME == True and flag_NAME == True:
                sub_file.write(year)
                sub_file.write(":")
                sub_file.write(month)
                sub_file.write(":")
                sub_file.write(day)
                sub_file.write(":")
                sub_file.write(time)
                sub_file.write(" ")
                #print time, " ",
                for i in range (0, num):
                    sub_file.write(one[i])
                    if i != num-1:
                        sub_file.write(" ")
                    #print one[i]

                flag_NAME = False
                flag_TIME = False

except (KeyboardInterrupt, SystemExit):
    data_file.close()
    sub_file.close()

data_file.close()
sub_file.close()