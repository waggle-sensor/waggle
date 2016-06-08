# read line

flag_TIME = False
flag_NAME = False

TIME = "Tue Jun"
NAME = "Carbon Monoxide"
TITLE = "CarbonMonoxide"
num = 1
MAX_trial = 8

data_file = open("data.txt", "r+")
sub_file = open("sub" + TITLE + ".txt", "w+")

try:
    line = data_file.readline()
    while (line != ""):
        line = data_file.readline()

        if TIME in line:
            one = line.split(" ")
            time = one[4]
            flag_TIME = True

        if NAME in line:
            two = line.split(" ")
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

        if flag_TIME == True and flag_NAME == True:
            sub_file.write(time)
            sub_file.write(" ")
            #print time, " ",
            for i in range (0, num):
                sub_file.write(one[i])
                #print one[i]

            flag_NAME = False
            flag_TIME = False

except (KeyboardInterrupt, SystemExit):
    data_file.close()
    sub_file.close()

data_file.close()
sub_file.close()
