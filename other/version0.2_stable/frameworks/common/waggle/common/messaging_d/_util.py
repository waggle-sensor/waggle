#!/usr/bin/env python2.7

from waggle.common.util import get_instance_id
from waggle.common.util import get_current_time
from waggle.common.util import get_mac_addr
from waggle.common.util import table
#from waggle.common.util import Record
#from waggle.common.util import * # this is bad, and temporary

'''
        DELIMITERS[i]:
        [0]: used only for string message type
        [1]: used to separage different msg in a string
        [2]: for data fields in a msg
        [3]: for sub fields in a data field
'''

def Delimiters(x):
    #return unichr(200+x)
    return ' [' + str(x) + '] '

def DiffDelimiters(x):
    return ' [[' + str(x) + ']] '


NUM_DELIMITERS = 20
#DELIMITERS = [unichr(200+i) for i in xrange(NUM_DELIMITERS)]
    # Unicode DELIMITERS, for real use.
DELIMITERS = [' [' + str(i) + '] ' for i in xrange(NUM_DELIMITERS)]
    # DELIMITERS for test only. 

NONE = -1
API_VERSION = 2

#
ROOT_DELIM_INDEX = 0

PAYLOAD_SEP_DELIM_INDEX = 1
HEADER_ROOT_DELIM_INDEX = 1
PAYLOAD_ROOT_DELIM_INDEX = 2

_char_type_dict = {'i' : int, 's' : str, 'd' : dict, 'l' : list, 'f' : float, 't' : tuple, int : 'i', str : 's', dict : 'd', list : 'l', float : 'f', tuple : 't'}

def type_to_char(t):
    # Needs revisted
    if t in _char_type_dict:
        return _char_type_dict[t]
    else:
        raise NotImplementedError("Type " + str(t) + " is not supported.")
    

def char_to_type(c):
    # Needs revisted
    if c in _char_type_dict:
        return _char_type_dict[c]
    else:
        raise NotImplementedError("Type " + str(c) + " is not supported.")


a = dict()
for i in range(4):
    a[i] = i * i

#a[3] = dict(a)

def encode_prim(value, delim_index):
    if isinstance(value, dict):
	t_s = 'd'
    else:
        t_s = type_to_char(type(value))
	
    cur_delim = DiffDelimiters(delim_index)
    if type(value) in (str, int, float): # type & value
        rv = cur_delim.join([t_s, str(value)])
    elif isinstance(value, dict): # type & list
        rv = cur_delim.join([t_s] + [encode_prim(value.items(), delim_index + 1)])
    elif type(value) is list: # type & 
        rv = cur_delim.join([t_s] + [encode_prim(x, delim_index+1) for x in value])
    elif type(value) is tuple:
        rv = cur_delim.join([t_s] + [encode_prim(x, delim_index+1) for x in value])
    else:
        raise NotImplementedError("Type " + str(type(value)) + " is not supported.")
    return rv

def decode_prim(v, delim_index):
    parts = v.split(DiffDelimiters(delim_index))
    value_type = char_to_type(parts[0])
#    print value_type, "\t", v
    if value_type in (str, int, float):
        rv = value_type(parts[1])
    elif value_type is dict:
        rv = value_type(decode_prim(parts[1], delim_index+1))
        """
        value = parts[1]
        rv = value_type()
        if value == '':
            return rv
        values = value.split(DiffDelimiters(delim_index+1))
        for kv in values:
            kv_tuple = kv.split(DiffDelimiters(delim_index+2))
            key = decode_prim(kv_tuple[0], delim_index+3)
            value = decode_prim(kv_tuple[1], delim_index+3)
            rv[key] = value
        return rv
        """
    elif value_type in (list, tuple):
        rv = value_type([decode_prim(x, delim_index+1) for x in parts[1:]])
    else:
        raise NotImplementedError("Type " + str(type(v)) + " is not supported.")
    return rv
        
            
        
#    print value_type
#    print value
    

def kv_encode(k, v, delim_index):
    delim = DiffDelimiters(delim_index)
    return delim.join([encode_prim(k, delim_index+1),
                       encode_prim(v, delim_index+1)])
    


def dict_encode(d, delim_index):
    return DELIMITERS[delim_index].join([kv_encode(key, value[key]) for key in value])
    rv = ""
    for key in d:
        if type(key) is str or type(key) is int or type(key) is float:
            rv =(rv + type_to_char(type(key)) + DELIMITERS[delim_index]
                    + str(key) + DELIMITERS[delim_index]
                    + type_to_char(type(d[key])) + DELIMITERS[delim_index]
                    + str(d[key]) + DELIMITERS[delim_index])
        elif type(key) is dict:
            rv =(rv + type_to_char(type(key)) + DELIMITERS[delim_index]
                    + dict_encode(d[key], delim_index+1) + DELIMITERS[delim_index])
        elif type(key) is list:
            pass
        else:
            return ""
        
    return rv
    


def get_api_version():
    return 2


def test_eq(a, b, msg):
    if a == b:
        print msg, "success"
    else:
        raise Exception(msg, "failure")

def indented(string):
    """ Might be used in pretty printing. """
#    print str(string)
    return ("\t" + str(string).replace('\n','\n\t'))[:-1]

class WaggleDefaults(object):
    def __eq__(self,other):
        """
        for key in self.__dict__:
            if not key.startswith('_'):
                print key
            if not getattr(self,key) == getattr(other,key):
                print "^ that one"
        """
        try:
            return all(getattr(self,key)==getattr(other,key)
                       for key in self.__dict__ if not key.startswith('_'))
        except AttributeError:
            return False

def _encode(to_encode, index):
    """ Takes a list containing only strings and lists, inserts delimiters
        and returns the encoding.
    """
    # print "List = ", to_encode
    # int/float/long/complex?
    if type(to_encode) is str:
        return to_encode

    # tuple?
    if type(to_encode) is list:
        return DELIMITERS[index].join(
                    [_encode(piece, index+1) for piece in to_encode])

    raise TypeError("Expected string or list, got " + str(type(to_encode))
                    + "(" + str(to_encode) + ").")
    
def _decode(to_decode, index):
    split = to_decode.split(DELIMITERS[index])
    
    if len(split) == 1:
        return to_decode
    else:
        return [_decode(item, index+1) for item in split]

"""    
def type_to_int(payload_type):
    if payload_type == RegistrationPayload:
        return 0
    if payload_type == DataPayload:
        return 1
    if payload_type == CommandPayload:
        return 2
    if payload_type == ReplyPayload:
        return 3

def int_to_type(payload_type):
    if payload_type == 0:
        return RegistrationPayload
    if payload_type == 1:
        return DataPayload
    if payload_type == 2:
        return CommandPayload
    if payload_type == 3:
        return ReplyPayload
"""

###############################################################################
# Unit testing
