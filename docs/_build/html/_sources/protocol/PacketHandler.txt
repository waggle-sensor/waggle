Packet Handler
==============




**About Packet Headers:**
	For working with packet headers, a dictionary containing the packet information is used.
	Note that while order does not matter when putting information into the dictionary, 
	spelling **does** matter! Also note that when you unpack a packet, a dictionary of this 
	form will be returned to you.

	The dictionary is constructed as shown below:

===============    ============================================   ==============================
Key	               Meaning                                        Data Type
===============    ============================================   ==============================
prot_ver           Protocol Version                               String of form X.Y ("0.3")
flags              Message flags (see below for more)             Tuple(Integer, Integer, Bool)
len_body           Length of message body                         Integer
time               Message timestamp in Unix time                 Integer
msg_mj_type        Message Major Type                             Integer
msg_mi_type        Message Minor Type                             Integer
resp_session       Responder Session Number                       Integer
ext_header         Extended Header                                Integer
s_uniqid           Sender Unique ID                               Integer
r_uniqid           Recipient Unique ID                            Integer
snd_session        Sender Session Number                          Integer
snd_seq            Sender sequence number                         Integer
resp_seq           Responder sequence number                      Integer
===============    ============================================   ==============================

The PacketHandler is capable of handling many of these for you automatically.
The minimum required dictionary required by PacketHandler is the following:

===============    ============================================   ==============================
Key	               Meaning                                        Data Type
===============    ============================================   ==============================
msg_mj_type        Message Major Type                             Integer
msg_mi_type        Message Minor Type                             Integer
===============    ============================================   ==============================

Any additional information in the header dictionary you supply to the packet handler will 
override the default values.

**Header Flags:**
	The header flags are a tuple of the form (Device priority, Message Priority, FIFO/LIFO)

	Device Priority
	   The priority of the device, as an integer in the range [0,15]

	Message Priority
	   The priority of the message, as an integer in the range [0,15]

	FIFO/LIFO
	   Whether the message should be treated as FIFO or LIFO by the data cache.
	      - True means it should be FIFO
	      - False means it should be LIFO

	Additional flags, such as whether or not the message is a multi-packet message, are used internally.

------------

PacketHandler Module Functions
------------------------------

.. automodule:: PacketHandler
   :members: pack, unpack, pack_header, get_header