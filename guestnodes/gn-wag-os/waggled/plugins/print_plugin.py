class register(object):
	def __init__(self, name, man):
		import time
		man[name] = 1
		print 'This is the printing plugin!'
		print 'All it does it print a few lines'
		print 'And then increment until 100'
		i = 0
		while True:
			while ((i < 100) and (man[name] == 1)):
				print 'the count is', i
				i = i + 1
				time.sleep(2)

			if (man[name] == 0):
				print name, "exiting."
				break
			elif (man[name] == -1):
				print name, "paused."
				while(man[name] == -1):
					pass
			elif (man[name] != 1):
				print "Error in",name,"- Run value must be -1, 0, or 1"
				time.sleep(2)