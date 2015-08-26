Plugin system based on Super Simple Python Plugins
from https://github.com/samwyse/sspp

To create a Python plugin, simply create a .py file in the plugins folder.
The plugin should define a callable object named "register" that will be 
invoked when the plugin is loaded.
Outside the plugin folder, run the plugin_manager.py script and follow the
instructions printed to run the plugins.

The __init__.py file within the plugin folder turns the directory into a module,
and automatically loads any python files in the plugins folder into the
__all__ list variable. From there, you can do anything you want with the
plugins.

The run_plugins_multi.py script only tries to invoke the "register" object in each
of the plugins in the __all__ list variable in sequence, but can be
changed to perform different functions instead or in addition to this.
It will run all of the called plugins as a separate process, and can start
or stop plugins individually or all at once.

Not implemented yet: plugins should also take an argument "run" that determines 
if the process runs or not. This allows the run_plugins_multi.py script to
pause any process. They should also have a stop function which allows the plugins
script to close the process without hard killing it.