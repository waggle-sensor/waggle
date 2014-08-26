f=open('global_func').read()
print f
f= f.replace('\n',', ')
print f
fh=open('global_func','w')
fh.write(f)

# cat gn_global_definition_section.py | grep = |cut -d "=" -f1 global variables | python write_global_variables.py 
# cat gn_global_definition_section.py | grep def |cut -d " " -f2 |cut -d "(" -f1 > global_func|python write_global_variables.py 
