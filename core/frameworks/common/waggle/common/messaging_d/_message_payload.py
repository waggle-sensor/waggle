#!/usr/bin/env python2.7
from _util import WaggleDefaults
from _util import _encode
from _util import _decode
from _util import PAYLOAD_ROOT_DELIM_INDEX


class MessagePayload(WaggleDefaults):
    type_registry = dict()  # Stores relationship {PAYLOAD_ID : <class:Payload>
    PAYLOAD_ID = -1


    # Registration magic
    class __metaclass__(type):
        """ Puts an execution hook in all derived classes to auto-register
            them. requires all subclasses to have a 'PAYLOAD_ID' variable
            with a unique integer id.
        """
        def __init__(cls, name, bases, cdict):
            type.__init__(cls, name, bases, cdict)
            cls._register(cdict['PAYLOAD_ID'], cls)


    @classmethod
    def _register(cls, key, value):
        """ Register an integer as a mapping to a class type. Useful for
                intepreting message types on the fly.
            Parameters
            ----------
            key(int): a unique PAYLOAD_ID
            value(class type): the class which 'owns' the PAYLOAD_ID
        """
        if key < 0:
            # Non-Registering class
            return
        elif key in cls.type_registry:
            # Already Registered
            if cls.type_registry[key] is value:
                # Non-Conflicting Registration
                return
            else:
                # Conflicting Registration
                raise ValueError
        else:
            # First time registerring
            cls.type_registry[key] = value
    
    
    def __init__(self):
        """ This class is an Abstract Base Class, don't allow an instance to be
                created.
        """
        raise NotImplementedError


    def __repr__(self):
        """ Return a str representation of the class sufficient to reconstruct
                the payload.
        """
        return self.__class__.__name__ + ".decode(\"" + self.encode() + "\")"


    def encode(self):
        """ Created a properly formatted payload as a string. """
        to_encode = self._convert_to_list()
        return _encode(to_encode, PAYLOAD_ROOT_DELIM_INDEX)


    @classmethod
    def decode(cls, to_decode, payload_type = -1):
        """ Decode a message and attempt to create an appropriate payload from
                it. If no payload type is given, a payload type is provided by
                the calling class.
            Parameters
            ----------
            to_decode(str): the message to decode
            payload_type(int): the type of payload to be created
                a value of -1 will use class information to decode
        """
        if payload_type == -1:
            payload_type = cls.PAYLOAD_ID

        rv = cls._new_payload(payload_type)

        list_from_decode = _decode(to_decode, PAYLOAD_ROOT_DELIM_INDEX)
        
        rv._restore_from_list(list_from_decode)
        if 1 or rv.verify():
            return rv
        else:
            raise TypeError("Message/Type pairing was not valid.")


    @classmethod
    def _new_payload(cls, payload_type):
        """ From a payload_type attempt to create a payload of the given type. 
            Parameters
            ----------
            payload_Type(int): the type of payload to be created
        """
        if payload_type in cls.type_registry:
            return cls.type_registry[payload_type]()
        else:
            raise TypeError("Bad payload_type")
