import multiprocessing, time, sys, re
import plugins 
import run_plugins_multi

#instructions for user
def help_dialogue():
	print '\nIf you want to work with a specific plugin, enter the name of the plugin you would like to manipulate. \nEnter "startall" if you would like to activate all non-blacklisted plugins.\nUse "stopall" to stop all plugins, or "killall" to kill all plugins. \nUse "pauseall" or "unpauseall" to pause and unpause active plugins. \nUse "startwhite" or "sw" to start plugins from the whitelist. \nType "list" or "l" for a list of available plugins. \nType "quit" or "q" to exit. \n\n'

#takes a plugin name and adds or removes it from the blacklist or whitelist, as specified by caller
def manip_list(plugin, listtype, manipulation):
	if (listtype == "whitelist"):
		file = open('plugins/whitelist.txt','r+')
		if (on_blacklist(plugin)):
			print 'Error: Plugin',plugin,'on blacklist. Cannot be on both lists.'
	elif (listtype == "blacklist"):
		file = open('plugins/blacklist.txt','r+')
		if (on_whitelist(plugin)):
			print 'Error: Plugin',plugin,'on whitelist. Cannot be on both lists.'
	li = file.read()
	li = re.split('\n', li)
	if (manipulation == "rm"):
		if (plugin in li):
			li.remove(plugin)
			li = "\n".join(li)
			file.seek(0)
			file.truncate()
			file.write(li)
			return 1
		else:
			return 0
	if (manipulation == "add"):
		if (not (plugin in li)):
			li.insert(0,plugin)
			li = "\n".join(li)
			file.seek(0)
			file.write(li)
			return 1
		else:
			return 0

#Starts all whitelisted plugins
def start_whitelist():
	whitelist = open('plugins/whitelist.txt','r').read()
	whitelist = re.split('\n', whitelist)
	fail = 0
	for name in whitelist:
		start = plug.start_plugin(name)
		if (not start) and (not name == ""):
			print 'Failed to start plugin', name
			fail = fail + 1
	if (fail == 0):
		print "Started all", len(whitelist)-1, "whitelisted plugins."
	else:
		print "Attempted to start all whitelisted plugins, failed to start", fail

#Starts all non-blacklisted plugins
def start_all_valid():
	blacklist = open('plugins/blacklist.txt','r').read()
	blacklist = re.split('\n', blacklist)
	fail = 0
	for plugin in plugins.__all__:
		if (not (plugin in blacklist)):
			start = plug.start_plugin(plugin)
			if not start:
				print 'Failed to start plugin', plugin
				fail = fail + 1
	if (fail == 0):
		print "Started all non-blacklisted plugins."
	else:
		print "Attempted to start all non-blacklisted plugins, failed to start", fail

#Checks if the plugin is on the blacklist
def on_blacklist(name):
	blacklist = open('plugins/blacklist.txt','r').read()
	blacklist = re.split('\n', blacklist)
	return (name in blacklist)

#Checks if the plugin is on the whitelist
def on_whitelist(name):
	whitelist = open('plugins/whitelist.txt','r').read()
	whitelist = re.split('\n', whitelist)
	return (name in whitelist)

#Lists available plugins, if they are active, and whether they are present on the whitelist and blacklist
def list_plugins_full():
	print 'Plugins List:'
	for name in plugins.__all__:
		plugin = getattr(plugins, name)
		active = 0
		for j in plug.jobs:
			if (j.name == name):
				print 'Plugin', name, 'is active. Whitelist:', on_whitelist(name), '  |  Blacklist:', on_blacklist(name)
				active = 1
				break
		if (not active):
			print 'Plugin', name, 'is inactive. Whitelist:', on_whitelist(name), '  |  Blacklist:', on_blacklist(name)

if __name__ == '__main__':
	plug = run_plugins_multi.plugin_runner()
	print '\nAutomatically starting whitelisted plugins...'
	start_whitelist()
	time.sleep(2)
	print '\nPlease enter the name of the plugin you would like to manipulate. \nEnter "startall" if you would like to activate all non-blacklisted plugins. \nUse "stopall" to stop all plugins, or "killall" to kill all plugins. \nYou can also use "pauseall" and "unpauseall" on active plugins. \nUse "startwhite" to start plugins from the whitelist.\nType "quit" to exit. \n\nThe following plugins are available.'
	list_plugins_full()
	print 'To see this list again, type "list". \nIf you need to review the commands, type "help".'

	
	while True:
		
		command = raw_input('\nMain menu\nEnter your command: ')
		print ''
		if (command == "startall"):
			start_all_valid()
		elif (command == "killall" or command == "ka"):
			plug.kill_all()
		elif (command == "startwhite" or command == "sw"):
			start_whitelist()
		elif (command == "stopall"):
			plug.stop_all()
		elif (command == "pauseall"):
			plug.pause_all()
		elif (command == "unpauseall"):
			plug.unpause_all()

		#if the entry matches the name of a plugin, go to plugin menu
		elif (command in plugins.__all__):
			while True:
				print '\nWould you like to "start", "stop", "pause", "unpause", or "kill" the plugin? \nYou can also "blacklist" or "whitelist" the plugin. \nType "back" to go back to the main menu.'
				command2 = raw_input('Enter your command: ')
				if (command2 == "start"):
					if (on_blacklist(command)):
						print 'Cannot start plugin', command, 'because it is blacklisted.'
					else: 
						plug.start_plugin(command)
					break
				elif (command2 == "kill" or command2 == "k"):
					plug.kill_plugin(command)
					break
				elif (command2 == "stop"):
					plug.stop_plugin(command)
					break
				elif (command2 == "pause" or command2 =="p"):
					plug.pause_plugin(command)
					break
				elif (command2 == "unpause"):
					plug.unpause_plugin(command)
					break

				#Go to whitelist/blacklist process, choose whether to add or remove from list
				elif (command2 == "whitelist" or command2 == "blacklist"):
					print 'Would you like to add or remove from', command2 + '?'
					command3 = raw_input('Enter your command (add/remove): ')
					if (command3 == "add"):
						change = manip_list(command,command2,"add")
						if (change == 1):
							print command, command2+"ed."
						elif (change == 0):
							print command, "already on", command2 + "."
						break
					if (command3 == "remove" or command3 == "rm"):
						change = manip_list(command,command2,"rm")
						if change:
							print command, "removed from", command2 + "."
						else:
							print command, "not on", command2 + "."
						break
					else:
						print "I didn't understand your answer."

				elif (command2 == "back"):
					break
				else:
					print "I didn't understand your command."

		#stops plugins (and kills if there's a stop failure) and exits the program			
		elif (command == "quit" or command == "q"):
			if (not (plug.stop_all() == 0)):
				plug.kill_all()
			break
		elif (command == "list" or command == "l"):
			list_plugins_full()
		elif (command == "help" or command == "h"):
			help_dialogue()
		else:
			print "I didn't understand your command. Type \"help\" or \"h\" to review commands."