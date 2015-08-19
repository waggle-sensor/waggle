Plugin system based on Super Simple Python Plugins
from https://github.com/samwyse/sspp

To create a Python plugin, simply create a .py file in the plugins folder.
The plugin should define a callable object named "register" that will be 
invoked when the plugin is loaded.
Outside the plugin folder, run the run_plugins.py script to run the plugins

The __init__.py file within the plugin folder turns the directory into a module,
and automatically loads any python files in the plugins folder into the
__all__ list variable. From there, you can do anything you want with the
plugins.

The run_plugins.py script only tries to invoke the "register" object in each
of the plugins in the __all__ list variable in sequence, but can be
 changed to perform different functions instead or in addition to this.
