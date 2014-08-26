f=open('global_variables').read()
print f
f= f.replace('\n',', ')
print f
fh=open('global_variables','w')
fh.write(f)

# cat nc_global_definition_section.py | grep = |cut -d "=" -f1 > global_variables | python write_global_variables.py 
# cat nc_global_definition_section.py | grep def |cut -d " " -f2 |cut -d "(" -f1 > global_func|python write_global_variables.py 
