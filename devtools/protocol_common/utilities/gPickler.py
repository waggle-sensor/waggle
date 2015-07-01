# GPickler.py
"""
	This module contians compression utilities intended to put objects into a format
	sendable through waggle.
"""
import cPickle as Pickle
from zlib import compress, decompress

def gPickle(data):
	"""
		Returns a gPickled representation of any information sent to it.

		:param object data: The sensor data to gPickle
		:rtype: string
	"""
	return compress(Pickle.dumps(data))

def un_gPickle(data):
	"""
	    Given some gPickled data, restores it to its original form.

	    :param string data: The data to be un gPickled
	    :rtype: object
	"""
	return Pickle.loads(decompress(data))