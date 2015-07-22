from multiprocessing import Process

"""
    A simple outline for a plug in architecture. 
    
"""

import plugins 


for name in plugins.__all__:
    plugin = getattr(plugins, name)
    print 'Plug in name: ', name 
    
    #TODO The idea is to make each plug-in a separate thread or process. 
    #TODO Could experiment with using Daemons - the stipulation being that Daemon processes cannot spawn children. 