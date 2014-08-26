#
# This is a simple test routine for the MessagePacker module, this driver is
#   designed to test functionality and to both print the message that will be
#   sent to the cloud and to "pretty print" some data to the screen.
#


def Match(tested_value, matching_value, 
            message_on_failure="Test failed", message_on_success=""):
    """ Tests two values against each other. If they match, a success message
            is printed, otherwise a failure message is printed.
        Parameters
        ----------
        tested_value (?): a computed value (can really be anything)
        matching_value (?): a hardcoded value (can really be anything)
        message_on_failure(str): the message printed on failure
        message_on_success(str): the message printed on success
    """
    if tested_value == matching_value:
        if message_on_success != "":
            print message_on_success
    else:
        if message_on_failure != "":
            print message_on_failure
            

def Diff(tested_value, differing_value, 
            message_on_failure="Test failed", message_on_success=""):
    """ Tests two values against each other. If they Differ, a success message
            is printed, otherwise a failure message is printed.
        Parameters
        ----------
        tested_value (?): a computed value (can really be anything)
        differing_value (?): a hardcoded value (can really be anything)
        message_on_failure(str): the message printed on failure
        message_on_success(str): the message printed on success
    """
    if tested_value != differing_value:
        if message_on_success != "":
            print message_on_success
    else:
        if message_on_failure != "":
            print message_on_failure


from message_packer import MessagePacker

# Create a MessagePacker
message = MessagePacker()

# Set some various fields with random data
message.read_time = "time"
message.sensor_id = "sensor_id"
message.instance_id = "inst_id"

# Add some items to the message
ref_id = []
for i in range(15):
    identifier = "name " + str(i)
    data_type = "i"
    value = i
    unit = "arb"
    note = "note " + str(i)
    ref_id.append(message.add_item(identifier, data_type, value, unit, note))

# This will print a message that is ready to send to the cloud
print "This will be ugly:\n\n", message.generate(), "\n"

# This will print the data in a nice looking table
print "This should be pretty:\n\n", message, "\n"

# This is a list of all reference IDs obtained
print "list of refrences: ", ref_id, "\n"

# try removing an arbitrary element
print "Array Length: ", len(message._data_units), "\n"
print message.del_item(ref_id[3])

# try removing the last element end
print "Array Length: ", len(message._data_units), "\n"
print message.del_item(ref_id[13])

# try removing an element that was moved
print "Array Length: ", len(message._data_units), "\n"
print message.del_item(ref_id[14])

# try removing the first element
print "Array Length: ", len(message._data_units), "\n"
print message.del_item(ref_id[0])

# try adding after a remove
ref1 = message.add_item("temp One", "f", 10.0, "amps/unit of time")

# try removing an arbitrary element
print "Array Length: ", len(message._data_units), "\n"
print message.del_item(ref_id[5])

ref2 = message.add_item("temp 2", "i", 10, "mph", "I put soup in the kitchen this fast")

# try removing an element that was added late
print "Array Length: ", len(message._data_units), "\n"
print message.del_item(ref1)

# print the results
print "This should be pretty:\n\n", message, "\n"


print "Failed tests will follow:"


# .CHECK_TYPE
#   With strong typing - should return true:
Match(MessagePacker.check_type(  10.0, 'f'),  True, "c_t 100")
Match(MessagePacker.check_type(   100, 'i'),  True, "c_t 101")
Match(MessagePacker.check_type("10.0", 's'),  True, "c_t 102")
Match(MessagePacker.check_type( "100", 's'),  True, "c_t 103")
Match(MessagePacker.check_type(   "a", 's'),  True, "c_t 104")

#   With strong typing - should return false:
Match(MessagePacker.check_type("10.0", 'f'), False, "c_t 200")
Match(MessagePacker.check_type( "100", 'f'), False, "c_t 201")
Match(MessagePacker.check_type(   100, 'f'), False, "c_t 202")
Match(MessagePacker.check_type("10.0", 'i'), False, "c_t 203")
Match(MessagePacker.check_type(  10.0, 'i'), False, "c_t 204")
Match(MessagePacker.check_type( "100", 'i'), False, "c_t 205")
Match(MessagePacker.check_type(  10.0, 's'), False, "c_t 206")
Match(MessagePacker.check_type(   100, 's'), False, "c_t 207")

#   Should always return false
Match(MessagePacker.check_type("SE",   'f'), False, "c_t 300")
Match(MessagePacker.check_type("SE",   'i'), False, "c_t 301")
Match(MessagePacker.check_type("SE",   'l'), False, "c_t 302")
Match(MessagePacker.check_type("SE", 'int'), False, "c_t 303")


# .CHECK_LENGTH
#   Should return true
Match(MessagePacker.check_length("asdf", 4),  True, "c_l 100")
Match(MessagePacker.check_length("asdf", 5),  True, "c_l 101")

#   Should return false
Match(MessagePacker.check_length("asdf", 3), False, "c_l 200")


# .CHECK_ITEM
#   Random valid items
Match(message.check_item("id", "i",   111, "unit"        ), True, "c_i 100")
Match(message.check_item("id", "i",   111, "unit", "note"), True, "c_i 101")
Match(message.check_item("id", "f",  10.0, "unit", "note"), True, "c_i 102")
Match(message.check_item("id", "s",  "NW", "unit", "note"), True, "c_i 103")
Match(message.check_item("id", "s", "1.1", "unit", "note"), True, "c_i 104")
Match(message.check_item("id", "s", "111", "unit", "note"), True, "c_i 105")

#   Random parameters as integers
Match(message.check_item(   1, "i", 111, "unit", "note"), False, "c_i 200")
Match(message.check_item("id",   2, 111, "unit", "note"), False, "c_i 201")
Match(message.check_item("id", "i",   3, "unit", "note"),  True, "c_i 202")
Match(message.check_item("id", "i", 111,      4, "note"), False, "c_i 203")
Match(message.check_item("id", "i", 111, "unit",      5), False, "c_i 204")

#   Random parameters as floats
Match(message.check_item( 1.0, "f", 1.1, "unit", "note"), False, "c_i 300")
Match(message.check_item("id", 2.0, 1.1, "unit", "note"), False, "c_i 301")
Match(message.check_item("id", "f", 3.0, "unit", "note"),  True, "c_i 302")
Match(message.check_item("id", "f", 1.1,    4.0, "note"), False, "c_i 303")
Match(message.check_item("id", "f", 1.1, "unit",    5.0), False, "c_i 304")

#   Random invalid type/values
Match(message.check_item("id", "f", "a", "unit", "note"), False, "c_i 400")
Match(message.check_item("id", "i", "b", "unit", "note"), False, "c_i 401")

# .ADD_ITEM
#   Random valid items
Diff(message.add_item("id", "i",   111, "unit"        ), -1, "a_i 100")
Diff(message.add_item("id", "i",   111, "unit", "note"), -1, "a_i 101")
Diff(message.add_item("id", "f",  10.0, "unit", "note"), -1, "a_i 102")
Diff(message.add_item("id", "s",  "NW", "unit", "note"), -1, "a_i 103")
Diff(message.add_item("id", "s", "1.1", "unit", "note"), -1, "a_i 104")
Diff(message.add_item("id", "s", "111", "unit", "note"), -1, "a_i 105")

#   Random parameters as integers
Match(message.add_item(   1, "i", 111, "unit", "note"), -1, "a_i 200")
Match(message.add_item("id",   2, 111, "unit", "note"), -1, "a_i 201")
Diff (message.add_item("id", "i",   3, "unit", "note"), -1, "a_i 202")
Match(message.add_item("id", "i", 111,      4, "note"), -1, "a_i 203")
Match(message.add_item("id", "i", 111, "unit",      5), -1, "a_i 204")

#   Random parameters as floats
Match(message.add_item( 1.0, "f", 1.1, "unit", "note"), -1, "a_i 300")
Match(message.add_item("id", 2.0, 1.1, "unit", "note"), -1, "a_i 301")
Diff (message.add_item("id", "f", 3.0, "unit", "note"), -1, "a_i 302")
Match(message.add_item("id", "f", 1.1,    4.0, "note"), -1, "a_i 303")
Match(message.add_item("id", "f", 1.1, "unit",    5.0), -1, "a_i 304")

#   Random invalid type/values
Match(message.add_item("id", "f", "a", "unit", "note"), -1, "a_i 400")
Match(message.add_item("id", "i", "b", "unit", "note"), -1, "a_i 401")
