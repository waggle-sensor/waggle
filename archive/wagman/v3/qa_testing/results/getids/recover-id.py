from serial import Serial


ser = Serial('/dev/tty.usbmodem1421', 115200)

ser.readline()  # skip possibly incomplete line
mac = ser.readline().decode().strip()
board_id = input('{} ID: '.format(mac)).strip()

with open('boards.csv', 'a') as outfile:
    outfile.write('{},{}\n'.format(board_id, mac))
