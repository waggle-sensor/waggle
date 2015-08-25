import multiprocessing, time, sys

"""
    A simple outline for a plug in architecture. 
    
"""

import plugins 

if __name__ == '__main__':
    jobs = []
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
	    #Starts plugin as a process named the same as plugin name
	    j = multiprocessing.Process(name=name, target=register_plugin)
	    jobs.append(j)
	    j.start()
	
    #stops all processes after one minute (arbitrary)
    time.sleep(60)
    print 'Terminating all processes...'
    for j in jobs:
        j.terminate()
	print j.name, 'terminated'
    print 'All processes terminated'

        #TODO The idea is to make each plug-in a separate thread or process. 
        #TODO Could experiment with using Daemons - the stipulation being that Daemon processes cannot spawn children. 
