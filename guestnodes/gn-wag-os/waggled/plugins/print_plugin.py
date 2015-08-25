class register(object):
    def __init__(self):
	import time
	print 'This is the printing plugin!'
	print 'All it does it print a few lines'
	print 'And then increment until 100'
	i = 0
	while (i < 100):
	    print 'the count is', i
	    i = i + 1
	    time.sleep(2)
	print "print_plugin over"
