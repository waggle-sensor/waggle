import multiprocessing, time, sys

"""
    A simple outline for a plug in architecture. 
    
"""

import plugins 


#Lists all available plugins and their status
def list_plugins():
    print 'Plugins List:'
    for name in plugins.__all__:
        plugin = getattr(plugins, name)
        active = 0
        for j in jobs:
            if (j.name == name):
                print 'Plugin', name, 'is active.'
                active = 1
                break
        if (not active):
            print 'Plugin', name, 'is inactive.'

#Tries to start a plugin with the name given by argument. Returns 1 for successful start, 0 for failure
def start_plugin(plugin_name):
    #checks if plugin is in list of plugins
    if (plugin_name in plugins.__all__):
        #checks if plugin is already active
        for j in jobs:
            if (j.name == plugin_name):
                print 'Plugin', plugin_name, 'is already active.'
                return 0

        #checks for register attribute in plugin
        plugin = getattr(plugins, plugin_name)
        try:
            register_plugin = plugin.register
        except AttributeError:
            print 'Plugin', plugin_name, 'has no register attribute'

        else:
            print 'Calling plugin', plugin_name, '...'
            #Starts plugin as a process named the same as plugin name
            j = multiprocessing.Process(name=plugin_name, target=register_plugin)
            jobs.append(j)
            j.start()
            print 'Plugin', j.name, 'started.'
            return 1
 
        print 'Plugin', plugin_name, 'not found - cannot start.'
        return 0
    
#Tries to stop a plugin with the name given by argument. Returns 1 for successful stop, 0 for failure
def stop_plugin(plugin_name):
    killed = 0
    for j in jobs:
        if (j.name == plugin_name):
            j.terminate()
            print 'Plugin', j.name, 'terminated.'
            j.join()
            killed = 1
            #removes plugin from list of active plugins
            jobs[:] = [x for x in jobs if x.is_alive()]
            return killed
    if (killed == 0):
        print 'Plugin', plugin_name, 'not active - cannot terminate.'
        return killed


#runs stop_plugin, then start_plugin if the first is successful
def restart_plugin(plugin_name):
    print 'Restarting plugin', plugin_name
    if (stop_plugin(plugin_name)):
        if(start_plugin(plugin_name)):
            print 'Plugin', plugin_name, 'restarted.'
        else:
            print 'Plugin', plugin_name, 'stopped, but not restarted. Did you alter the plugin?'
    else:
        print 'Plugin', plugin_name, 'did not terminate - cannot restart.'


#terminates all active processes
def kill_all():
    print 'Terminating all processes...'
    for j in jobs:
        j.terminate()
        print j.name, 'terminated'
        j.join()
    print 'All processes terminated'


if __name__ == '__main__':
    jobs = []
    for name in plugins.__all__:
        plugin = getattr(plugins, name)
        print 'Plugin name: ', name 

        try:
            # see if plugin has a 'register' attribute
            register_plugin = plugin.register
        except AttributeError:
            #raise an exception, log a message, or just ignore problem
            print 'Plugin', name, 'has no register attribute.'
            pass
        else:
            #try to call it, without catching any errors
	       print 'Calling plugin', name, '...'
	       #Starts plugin as a process named the same as plugin name
	       j = multiprocessing.Process(name=name, target=register_plugin)
	       jobs.append(j)
	       j.start()
	

    #Tests on functions
    time.sleep(10)
    list_plugins()
    start_plugin("print_plugin")
    stop_plugin("print_plugin")
    time.sleep(5)
    start_plugin("print_plugin")
    stop_plugin("simple_sensor_plugin")
    start_plugin("nonexistent_plugin")
    stop_plugin("nonexistent_plugin")
    restart_plugin("nonexistent_plugin")
    list_plugins()
    time.sleep(5)
    restart_plugin("simple_sensor_plugin")
    restart_plugin("print_plugin")
    time.sleep(5)


    kill_all()