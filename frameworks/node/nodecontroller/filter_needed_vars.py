
from commands import getoutput as bashit

f=open('global_variables').read()
f=f.split(' ,')
class_list = {}
classes = ['config_file_functions', 'get_node_info', '__init__', 'logging_module', 'nc_global_definition_section', 'nc_gn_msgs_buffer_mngr_class', 'nc_internal_communicator_class', 'nc_msg_processor_class', 'nc_server_class']
for each in classes:
    class_list[each]=[]


for variable in f:
    cmd=str('grep '+variable+" * " + "| cut -d '.' -f1 > classes")
    bashit(cmd)
    f_class=open('classes').read()
    print f_class
    f_class=f_class.split('\n')
    for each_class in f_class:
        if each_class in class_list:
            class_name=class_list[each_class]
            class_name.append(variable)
filtered_vars = open('filtered_vars','w')
filtered_vars.write(class_list)