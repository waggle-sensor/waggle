import multiprocessing, time, sys
from multiprocessing import Manager

"""
    A simple multiprocessing plugin architecture. 
    Kyle Lueptow 2015
    
"""

import plugins 

class plugin_runner(object):
    def __init__(self):
        self.jobs = []
        self.manager = Manager()
        self.man = self.manager.dict()

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
                j = multiprocessing.Process(name=plugin_name, target=register_plugin, args=(plugin_name,self.man))
                self.jobs.append(j)
                j.start()
                print 'Plugin', j.name, 'started.'
                return 1
     
            print 'Plugin', plugin_name, 'not found - cannot start.'
            return 0
        
    #Tries to stop a plugin with the name given by argument. Returns 1 for successful stop, 0 for failure
    def kill_plugin(self, plugin_name):
        killed = 0
        #Tries to find plugin in list of active processes
        for j in self.jobs:
            if (j.name == plugin_name):
                j.terminate()
                j.join()
                print 'Plugin', j.name, 'terminated.'
                killed = 1
                #removes plugin from list of active plugins
                self.jobs[:] = [x for x in self.jobs if x.is_alive()]
                return killed
        if (killed == 0):
            print 'Plugin', plugin_name, 'not active - cannot terminate.'
            return killed

    #sends plugin a stop signal
    def stop_plugin(self, plugin_name):
        stopped = 0
        for j in self.jobs:
            if (j.name == plugin_name):
                self.man[plugin_name] = 0
                j.join()
                print 'Plugin', j.name, 'stopped.'
                stopped = 1
                self.jobs[:] = [x for x in self.jobs if x.is_alive()]
                return stopped
        if (stopped == 0):
            print 'Plugin', plugin_name, 'not active - cannot stop.'
            return stopped

    #sends plugin a pause signal
    def pause_plugin(self, plugin_name):
        paused = 0
        for j in self.jobs:
            if (j.name == plugin_name):
                self.man[plugin_name] = -1
                paused = 1
                time.sleep(2)
                return paused
        if (paused == 0):
            print 'Plugin', plugin_name, 'not active - cannot pause.'
            return paused

    #sends plugin a run/resume signal
    def unpause_plugin(self, plugin_name):
        unpaused = 0
        for j in self.jobs:
            if (j.name == plugin_name):
                if (self.man[plugin_name] != -1):
                    print 'Plugin', plugin_name, 'not paused - cannot unpause.'
                    return unpaused
                self.man[plugin_name] = 1
                unpaused = 1
                print "Plugin",plugin_name,"unpaused."
                return unpaused
        if (unpaused == 0):
            print 'Plugin', plugin_name, 'not active - cannot unpause.'
            return unpaused

    #runs kill_plugin, then start_plugin if the first is successful
    def restart_plugin(self, plugin_name):
        print 'Restarting plugin', plugin_name
        if (self.kill_plugin(plugin_name)):
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
        #Must be range(len()) instead of self.jobs because kill_plugin() removes plugin from beginning of list, confusing loop.
        #If self.jobs is used, only half the processes are stopped.
        for count in range(len(self.jobs)):
            j = self.jobs[0]
            kill = self.kill_plugin(j.name)
            if not kill:
                fail = fail + 1
        if (fail == 0):
            print 'All active processes killed.'
        else:
            print 'Attempted to kill all active processes with', fail, 'failures.'

    #sends all active plugins a stop signal
    def stop_all(self):
        print 'Stopping all processes...'
        stop = 1
        fail = 0
        for count in range(len(self.jobs)):
            j = self.jobs[0]
            stop = self.stop_plugin(j.name)
            if not stop:
                fail = fail + 1
        if (fail == 0):
            print 'All active processes stopped.'
        else:
            print 'Attempted to stop all active processes with', fail, 'failures.'
        return fail

    #sends all active, unpaused plugins a pause signal
    def pause_all(self):
        print 'Pausing all processes...'
        pause = 1
        fail = 0
        for j in self.jobs:
            if (self.man[j.name] == 1):
                pause = self.pause_plugin(j.name)
            if not pause:
                fail = fail + 1
        if (fail == 0):
            print 'All active processes sent pause signal.'
        else:
            time.sleep(2)
            print 'Attempted to pause all active processes with',fail,'failures.'
        return fail

    #Sends all paused plugins a run/resume signal.
    def unpause_all(self):
        print 'Unpausing all processes...'
        unpause = 1
        fail = 0
        for j in self.jobs:
            if (self.man[j.name] == -1):
                unpause = self.unpause_plugin(j.name)
            if not unpause:
                fail = fail + 1
        if (fail == 0):
            print 'All paused processes unpaused.'
        else:
            print 'Attmepted to unpause all paused processes with',fail,'failures.'
        return fail

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