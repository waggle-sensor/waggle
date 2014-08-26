
from commands import getoutput as bashit

f=open('global_variables').read()
f=f.split(' ,')
class_list = {}
classes = ['config_file_functions', 'get_node_info', '__init__', 'logging_module', 'nc_gn_msgs_buffer_mngr_class', 'nc_internal_communicator_class', 'nc_msg_processor_class', 'nc_server_class']
for each in classes:
    class_list[each]=[]
print f
bashit("rm -rf filtered_vars")
bashit("rm -rf classes")
for variable in f:
    cmd=str('grep '+variable+" * " + "| cut -d '.' -f1 > classes")
    bashit(cmd)
    f_class=open('classes').read()
    #print f_class
    f_class=f_class.split('\n')
    print "for var:"+str(variable)+"\nclasses:"+str(f_class)+"\n"
    for each_class in f_class:
        if each_class in class_list:
            class_name=class_list[each_class]
            if variable not in class_name:
                class_name.append(variable)
filtered_vars = open('filtered_vars','w')
#print class_list
class_list = str(class_list).replace("'",'')
filtered_vars.write(str(class_list))