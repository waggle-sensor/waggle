from configobj import *


def is_dict(dic):
    print type(dic)
    if isinstance(dic, dict):
        for key in dic:
            is_dict(dic[key])
    else:
        print "its not a dict"
config = ConfigObj('gn.cfg')
#config["name"] = "Mjj"                   # this is my name
#config["sensors"] = {}
#config["sensors"]["name"] = "s1"
config["System_info Section"] = {}
config["System_info Section"]["fgfg"]  = "fdf"
#config.writein('gn.cfg' )
config.write()
print config
dicti = ConfigObj('gn.cfg')
for key, val in dicti.iteritems():
    print key
    is_dict(dicti[key])
print dicti["System_info Section"]
for key, val in dicti["System_info Section"].iteritems():
    print key


print config

