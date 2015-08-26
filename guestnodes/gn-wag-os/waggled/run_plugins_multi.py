import multiprocessing, time, sys

"""
    A simple multiprocessing plugin architecture. 
    Kyle Lueptow 2015
    
"""

import plugins 

class plugin_runner(object):
    def __init__(self):
        self.jobs = []

    #Lists all available plugins and their status
    def list_plugins(self):
        print 'Plugins List:'
        for name in plugins.__all__:
            plugin = getattr(plugins, name)
            active = 0
            #checks if listed plugin is in list of active processes
            for j in self.jobs:
                if (j.name == name):
                    print 'Plugin', name, 'is active.'
                    active = 1
                    break
            if (not active):
                print 'Plugin', name, 'is inactive.'

    #Tries to start a plugin with the name given by argument. Returns 1 for successful start, 0 for failure
    def start_plugin(self, plugin_name):
        #checks if plugin is in list of plugins
        if (plugin_name in plugins.__all__):
            #checks if plugin is already active
            for j in self.jobs:
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
                print 'Calling plugin', plugin_name + '...'
                #Starts plugin as a process named the same as plugin name
                j = multiprocessing.Process(name=plugin_name, target=register_plugin)
                self.jobs.append(j)
                j.start()
                print 'Plugin', j.name, 'started.'
                return 1
     
            print 'Plugin', plugin_name, 'not found - cannot start.'
            return 0
        
    #Tries to stop a plugin with the name given by argument. Returns 1 for successful stop, 0 for failure
    def stop_plugin(self, plugin_name):
        killed = 0
        #Tries to find plugin in list of active processes
        for j in self.jobs:
            if (j.name == plugin_name):
                j.terminate()
                print 'Plugin', j.name, 'terminated.'
                j.join()
                killed = 1
                #removes plugin from list of active plugins
                self.jobs[:] = [x for x in self.jobs if x.is_alive()]
                return killed
        if (killed == 0):
            print 'Plugin', plugin_name, 'not active - cannot terminate.'
            return killed


    #runs stop_plugin, then start_plugin if the first is successful
    def restart_plugin(self, plugin_name):
        print 'Restarting plugin', plugin_name
        if (self.stop_plugin(plugin_name)):
            #If stopping plugin worked, try to start it again
            if(self.start_plugin(plugin_name)):
                print 'Plugin', plugin_name, 'restarted.'
            else:
                print 'Plugin', plugin_name, 'stopped, but not restarted. Did you alter the plugin?'
        else:
            print 'Plugin', plugin_name, 'did not terminate - cannot restart.'


    #terminates all active processes
    def kill_all(self):
        print 'Terminating all processes...'
        kill = 1
        fail = 0
        #Must be range(len()) instead of self.jobs because stop_plugin() removes plugin from beginning of list, confusing loop.
        #If self.jobs is used, only half the processes are stopped.
        for count in range(len(self.jobs)):
            j = self.jobs[0]
            kill = self.stop_plugin(j.name)
            if not kill:
                fail = fail + 1
        if (fail == 0):
            print 'All active processes killed.'
        else:
            print 'Attempted to kill all active processes with', fail, 'failures.'

    #Starts all processes (ignores if the process is already active)
    def start_all(self):
        print 'Starting all processes...'
        start = 1
        fail = 0
        for plugin_name in plugins.__all__:
            start = self.start_plugin(plugin_name)
            if not start:
                fail = fail + 1
        if (fail == 0):
            print 'All processes started.'
        else:
            print 'Attempted to start all processes with', fail, 'failures.'

"""
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
    """