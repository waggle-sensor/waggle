import os
from ConfigParser import SafeConfigParser

config = SafeConfigParser()
config.readfp(file('/usr/share/python/debian_defaults'))
versions = config.get('DEFAULT', 'supported-versions')
py_supported = [s.strip() for s in versions.split(',')]
versions = config.get('DEFAULT', 'old-versions')
py_oldversions = [s.strip() for s in versions.split(',')]

py_installed = [ ver for ver in py_supported if os.access('/usr/bin/'+ver,os.X_OK) ]
py_supported_short = [ a.replace("python","") for a in py_supported ]

def version_cmp(ver1,ver2):
  v1=[int(i) for i in ver1.split('.')]
  v2=[int(i) for i in ver2.split('.')]
  return cmp(v1,v2)

# Parse the version format from .version files
class version_list(list):
  def __init__(self,version_info):
    self.verlist=[]
    dummylist=[]
    for item in version_info.rstrip('\n').split(','):
      v=[i.strip() for i in item.split('-')]
      if len(v)>1:
        if v[0]:
          dummylist.append(v[0])
        else:
          v[0] = py_supported_short[0]
          dummylist.append("0")
        if v[1]:
          dummylist.append(v[1])
        else:
          v[1] = py_supported_short[-1]
          dummylist.append("100")
        for ver in py_supported_short:
          try:
            if version_cmp(ver,v[0]) >= 0 and version_cmp(ver,v[1]) <= 0:
              self.verlist.append(ver)
          except ValueError:
            pass
      else:
        dummylist.append(v[0])
        if v[0] in py_supported_short:
          self.verlist.append(v[0])
    self.verlist.sort(version_cmp)
    dummylist.sort(version_cmp)
    self.min=dummylist[0]
    if self.min=="0": self.min=None
    self.max=dummylist[-1]
    if self.max=="100": self.max=None
    for i in self.verlist:
        self.append('python'+i)

