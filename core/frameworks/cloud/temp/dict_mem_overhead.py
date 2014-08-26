from message_packer import MessagePacker
from math import pow
import sys
from commands import getstatusoutput as bash

char_in_point = 0


# Allow command arguments for Data point sizes, whether to delete or not, and
#   for the number of entries in a message
if len(sys.argv) > 1:
    char_in_point = int(sys.argv[1])
else:
    char_in_point = 20
    print "Assuming 20 character data points!"

if len(sys.argv) > 2:
    delete = int(sys.argv[2])
else:
    delete = 0
    print "Not deleting!"

if len(sys.argv) > 3:
    message_size = int(sys.argv[3])
else:
    message_size = 1000000


# Distribute the characters per point across the five fields
size = (char_in_point / 5)
char_in_point = char_in_point - size
p1 = "." * size
size = (char_in_point / 4)
char_in_point = char_in_point - size
p2 = "." * size
size = (char_in_point / 3)
char_in_point = char_in_point - size
p3 = "." * size
size = (char_in_point / 2)
char_in_point = char_in_point - size
p4 = "." * size
size = (char_in_point / 1)
char_in_point = char_in_point - size
p5 = "." * size

# obtain a new message
message = MessagePacker()

# Push messages onto the list
i = 0
limit = message_size
while i < limit:
    message.add_item(p1, p2, p3, p4, p5)
    i = i + 1

print "Done allocating!"

# delete the dictionary (if it was requested)
if delete:
    del message._id_indice_dict
    print "Done deleting!"

# capture the value of top and push it into a file
bash("sleep 3; echo `top -n 1 -b | grep python | sed 's/^ *//' | sed 's/  */ /g' | cut -d' ' -f5,6,7,10` " + str(len(p1+p2+p3+p4+p5)) + " " + str(delete) + " " + str(message_size) + " >> tmp.out")
