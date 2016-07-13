# read line

flag_TIME = False
flag_NAME = False
flag_SIGN = False

SIGN = "-------------"
FILE_NAME = "test_data.txt"  #Need to change file name

MAX_trial = 4
count = 0

def sensor_data(num):
	two = line.split(" ")

	for i in range (0, MAX_trial):
		if two[i] == "@":
			i = i + 2
			for j in range (0, num):
				one[i] = two[i + j]

def write_data():
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


try:
	while (count < 10)
		count = count + 1
		with open(FILE_NAME) as data_file:
			for line in data_file:

				#if TIME in line:
				if flag_SIGN == True:
					one = line.split(" ")

					year = one[5]
					month = one[1]
					day = one[3]
					time = one[4]

					flag_SIGN = False
					print "one: ",one

				#if data lines will be following:
				elif SIGN in line:
					flag_SIGN = True

				# data
				elif "Sensor" in line:
					two = line.split(" ")
					print two
					if two[1] == "7" | two[1] == "38" | two[1] == "39":
						num = 4
					elif two[1] == "10" | two[1] == "31":
						num = 3
					sensor_data(num)
					write_data()

except (KeyboardInterrupt, SystemExit):
	data_file.close()
	sub_file.close()

data_file.close()
sub_file.close()