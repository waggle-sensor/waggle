from multiprocessing import Process

"""
    A simple outline for a plug in architecture. 
    
"""

import plugins 


for name in plugins.__all__:
    plugin = getattr(plugins, name)
    print 'Plug in name: ', name 

    try:
    	# see if plugin has a 'register' attribute
    	register_plugin = plugin.register
    except AttributeError:
    	#raise an exception, log a message, or just ignore problem
    	print 'no register attribute'
	pass
    else:
    	#try to call it, without catching any errors
	print 'Calling plugin: ', name
    	register_plugin()

    #TODO The idea is to make each plug-in a separate thread or process. 
    #TODO Could experiment with using Daemons - the stipulation being that Daemon processes cannot spawn children. 
