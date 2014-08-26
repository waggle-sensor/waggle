from configobj import *

op = {'configspec' : "./configspec", 'configspec_only' : True}
config = ConfigObj('gn.cfg')
#config["name"] = "Mjj"                   # this is my name
#config["sensors"] = {}
#config["sensors"]["name"] = "s1"
print config
config["System_info Section"]["fgfg"]  = "name4 changed"
config.write_full = False
config.configspec_only = True
#config.writein('gn.cfg' )
#config.filename = 'gn1.cfg'
config.write_full = False
infile = ["./configspec"]
config.update(config)
print config
