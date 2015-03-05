#!/usr/bin/env python2.7
from commands import getoutput as bash

cmd = "ls -lh --time-style=long-iso `find -name '*.txt'` | sed 's/  */ /g'"

output = bash(cmd)

table = output.split('\n')

for i in xrange(len(table)):
    table[i] = [a for a in table[i].split(' ')]
#    print table[i][7]

table = sorted(table, key = lambda x: x[6], reverse = True)
table = sorted(table, key = lambda x: x[5], reverse = True)

seen = []
print "Last Modification     Size    File"
for i in xrange(len(table)):
    b = table[i][7].find('/', 2) + 1
    e = table[i][7].find('/', b) + 2
    if not table[i][7][b:e] in seen:
        seen.append(table[i][7][b:e])
        print table[i][5],' ', table[i][6],'  ', table[i][4].rjust(4),'  ', table[i][7][2:]

#    exit()
        

#print output
