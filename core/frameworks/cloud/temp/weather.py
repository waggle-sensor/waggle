#
# This is another test routine, with meaningful data, that sends the data
#   to the cloud.
#

from commands import getoutput as bashit
from message_packer import MessagePacker
from weather_client import data_client

# Set up the command
command = "curl 'http://www.atmos.anl.gov/ANLMET/anltower.now' | tr -s '\n' | head -16 | sed '12,16s/^/0m /' | sed '5s/$/ #.# #/' | sed '9s/$/ #.# #/' | sed '11s/$/ #.# #/' | sed '13,14s/$/ #.# #/' | sed '2s/.*\( [0-9]* CST.*\)/\\1/' | tr -s ' ' | sed 's/^ //' | sed '4s/ [0-9]/ dir&/' | sed '15s/$/ #.# #/' | sed '3,16s/\([^ ]*\) \(.*\) \([^ ]*\) \([^ ]*\) \([^ ]*\) \([^ ]*\)/\\1;\\2;\\3;\\4;\\5;\\6;/' | sed 's/#.#;#;//' | sed '12,16s/^[^;]*//' | sed 's/^;//' | tr '\\n' '#' | sed 's/\([0-9][0-9]*\)\\.;/\\1;/g'"

# Run it
weatherData=bashit(command)
# Parse it some
weatherParam=weatherData.split('#')

# Get a MessagePacker
message = MessagePacker()

# Fill the MessagePacker with data from the weather command
message.time_read = weatherParam[1].split(';')[0]
message.instance_id = "http://www.atmos.anl.gov/ANLMET/anltower.now"
message.sensor_id = "sensor_123 " + message.time_read
message.add_item("60m Wind Speed", "f", float(weatherParam[2].split(';')[2]), "mph")
message.add_item("60m Wind Direction", "s", str(weatherParam[3].split(';')[2]), "compass", "I like the cardinal directions.")
message.add_item("60m Temperature", "f", float(weatherParam[5].split(';')[2]), "fahrenheit")
message.add_item("10m Wind Speed", "f", float(weatherParam[6].split(';')[2]), "mph")
message.add_item("10m Wind Direction", "s", str(weatherParam[7].split(';')[3]), "compass")
message.add_item("10m Temperature", "f", float(weatherParam[9].split(';')[2]), "fahrenheit")
message.add_item("10m Rel. Humidity", "i", int(weatherParam[10].split(';')[2]), "%")
message.add_item("Barometric Pressure", "f", float(weatherParam[11].split(';')[3]), "kPa")
message.add_item("Solar Irradiation", "i", int(weatherParam[12].split(';')[1]), "w/m^2")
message.add_item("Net Irradiation", "i", int(weatherParam[13].split(';')[1]), "w/m^2")
message.add_item("Stability", "s", str(weatherParam[14].split(';')[1]), "grade", "Im not really sure what grade is.")
message.add_item("Wet Bulb Globe Temprature", "f", float(weatherParam[15].split(';')[3]), "fahrenheit")

# generate a message form our weather data
msg_to_send = message.generate()

# send the message to the cloud
data_client.msg_send(msg_to_send)
