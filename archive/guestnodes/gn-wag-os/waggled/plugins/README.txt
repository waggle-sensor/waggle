Plugin system based on Super Simple Python Plugins
from https://github.com/samwyse/sspp

To create a Python plugin, simply create a .py file in the plugins folder.
The plugin should define a callable object named "register" that will be 
invoked when the plugin is loaded. This object should take three arguments:
self, name, and man. It should then initialize man[name] = 1. This is a
controller so the plugin manager can tell the plugin to stop or pause.
A man[name] value of 0 should result in your plugin ending, while a man[name]
value of -1 should result in your plugin doing nothing until it receives 
another signal.

To run plugins, run the plugin_manager.py script outside the plugins folder
and follow the instructions printed.

The __init__.py file within the plugin folder turns the directory into a module,
and automatically loads any python files in the plugins folder into the
__all__ list variable. From there, you can do anything you want with the
plugins. By default, when you open plugin_manager.py, it will automatically run
all of the plugins listed in the whitelist.txt file, which can be manipulated
from within the manager. The blacklist.txt file can also be manipulated from
the manager, and any plugin listed within is disallowed from being run by the
manager.

The run_plugins_multi.py script only tries to invoke the "register" object in each
of the plugins in the __all__ list variable in sequence, but can be
changed to perform different functions instead or in addition to this.
It will run all of the called plugins as a separate process, and can start
or stop plugins individually or all at once.