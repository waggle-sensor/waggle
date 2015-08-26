import multiprocessing, time, sys, re
import plugins 
import run_plugins_multi

#instructions for user
def help_dialogue():
	print '\nIf you want to work with a specific plugin, enter the name of the plugin you would like to manipulate. \nEnter "startall" or "sa" if you would like to activate all plugins, or "killall" or "ka" to kill all plugins. \nUse "startwhite" or "sw" to start plugins from a whitelist, or "startblack" or "sb" to start plugins not on a blacklist. \nType "list" or "l" for a list of available plugins. \nType "quit" or "q" to exit. \n\n'

#takes a plugin name and adds or removes it from the blacklist or whitelist, as specified by caller
def manip_list(plugin, listtype, manipulation):
	if (listtype == "whitelist"):
		file = open('plugins/whitelist.txt','r+')
	elif (listtype == "blacklist"):
		file = open('plugins/blacklist.txt','r+')
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
def start_blacklist():
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

if __name__ == '__main__':
	plug = run_plugins_multi.plugin_runner()
	print '\nPlease enter the name of the plugin you would like to manipulate. \nEnter "startall" if you would like to activate all plugins, or "killall" to kill all plugins. \nUse "startwhite" to start plugins from a whitelist, or "startblack" to start plugins not on a blacklist. \nType "quit" to exit. \n\nThe following plugins are available.'
	plug.list_plugins()
	print 'To see this list again, type "list". \nIf you need to review the commands, type "help".'
	while True:
		
		command = raw_input('\nMain menu\nEnter your command: ')
		print ''
		if (command == "startall" or command == "sa"):
			plug.start_all()
		elif (command == "killall" or command == "ka"):
			plug.kill_all()
		elif (command == "startwhite" or command == "sw"):
			start_whitelist()
		elif (command == "startblack" or command == "sb"):
			start_blacklist()

		#if the entry matches the name of a plugin, go to plugin menu
		elif (command in plugins.__all__):
			while True:
				print '\nWould you like to "kill" or "start" the plugin? \nYou can also "blacklist" or "whitelist" the plugin. \nType "back" to go back to the main menu.'
				command2 = raw_input('Enter your command: ')
				if (command2 == "start" or command2 == "s"):
					plug.start_plugin(command)
					break
				elif (command2 == "kill" or command2 == "k"):
					plug.stop_plugin(command)
					break

				#Go to whitelist/blacklist process, choose whether to add or remove from list
				elif (command2 == "whitelist" or command2 == "blacklist"):
					print 'Would you like to add or remove from', command2 + '?'
					command3 = raw_input('Enter your command (add/remove): ')
					if (command3 == "add"):
						change = manip_list(command,command2,"add")
						if change:
							print command, command2+"ed."
						else:
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

		#kills plugins and exits program			
		elif (command == "quit" or command == "q"):
			plug.kill_all()
			break
		elif (command == "list" or command == "l"):
			plug.list_plugins()
		elif (command == "help" or command == "h"):
			help_dialogue()
		else:
			print "I didn't understand your command. Type \"help\" or \"h\" to review commands."