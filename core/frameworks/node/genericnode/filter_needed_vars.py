from commands import getoutput as bashit

f=open('global_variables').read()
f=f.split(',')
class_list = {}

classes = ['config_file_functions', 'get_node_info', '__init__', 'gn_buffer_mngr_class', 'gn_external_communicator_class', 'gn_main_class', 'gn_sensor_controller_class', 'sensor_plugin', 'add_sensor_info']

for each in classes:
    class_list[each]=[]

bashit("rm -rf test_filtered_vars")
bashit("rm -rf classes")

for variable in f:
    cmd=str('grep '+variable+" * " + "| cut -d '.' -f1 > classes")
    bashit(cmd)
    f_class=open('classes').read()
    f_class=f_class.split('\n')
    for each_class in f_class:
        if each_class in class_list:
            class_name=class_list[each_class]
            if variable not in class_name:
                class_name.append(variable)
filtered_vars = open('filtered_vars','w')
class_list = str(class_list).replace("'",'')
filtered_vars.write(str(class_list))