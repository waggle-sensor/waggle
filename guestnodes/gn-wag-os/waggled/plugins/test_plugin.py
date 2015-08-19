class register(object):
    
    def __init__(self):
	print 'Hello world!'
	print ' '
	print 'We are printing from the __init__ of the register class'
	print ' '
	test_function()
	testplug = test_plugin()
	testplug.run()

    def test(self):
	print 'running from test() inside register class'

def test_function():
    print 'We can print from functions defined in the test_plugin.py'
    print 'outside of the register class'
    print ' '

class test_plugin(object):
    
    def __init__(self):
        print 'We can define other objects inside of the test_plugin.py'
    
    def run(self):
        print 'And then perform functions through those objects as normal'
