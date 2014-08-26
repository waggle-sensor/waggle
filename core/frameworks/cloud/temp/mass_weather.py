#
# This is another test routine, with meaningful data, that sends the data
#   to the cloud.
#

from message_packer import MessagePacker
from weather_client import data_client
import sys

# allow support for command line argument for number of readings to send
if len(sys.argv) > 1:
    print "Sending the first " + sys.argv[1] + " readings!\n"
    num_to_send = int(sys.argv[1])
else:
    print "Sending the first 10 readings!\n"
    num_to_send = 10

messages = []

# access our readings
f = open('data/weather.txt')
weatherData = f.readline()

i = 0
total_size = 0
while weatherData != "" and i < num_to_send:
    # Parse it some
    weatherParam=weatherData.split('#')
    
    # Get a MessagePacker
    message = MessagePacker()
    
    # Fill the MessagePacker with data from the weather command
    message.time_read = weatherParam[1].split(';')[0]
    message.instance_id = "ATMOS123"
    message.sensor_id = "MESSAGE_" + str(i)
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

    # Add this message to our list of messages
    messages.append(message.generate())
    
    # Collect an estimate of our data size
    total_size = total_size + sys.getsizeof(messages[i])
    
    # Prepare for the next loop
    weatherData = f.readline()
    i = i + 1

# send the message to the cloud
data_client.multi_send(messages)

print "Sent about " + str(total_size) + " bytes of data!"
