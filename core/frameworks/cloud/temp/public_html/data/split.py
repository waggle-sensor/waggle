from commands import getoutput as bash

def Write(dest, ip, instance_id, sensor_id, read_time, iden_ar, type_ar, valu_ar, unit_ar, note_ar):
    if dest == "" or dest == "all":
        return
    f = open(dest + ".txt", 'a')

    data_identifiers = iden_ar.split("|::|")
    data_types = type_ar.split("|::|")
    data_values = valu_ar.split("|::|")
    data_units = unit_ar.split("|::|")
    data_notes = note_ar.split("|::|")
    rv = ""

    rv = rv + "\n##########\n\n"

    #header information
    rv = rv + "IP recieved from: " + str(ip) + "\n" \
            + "Instance ID: " + str(instance_id) + "\n" \
            + "Sensor ID: " + str(sensor_id) + "\n" \
            + "Read Time: " + str(read_time) + "\n\n"

    num_values = len(data_values)

    if (num_values == 0):
        rv = rv + "NO DATA"
    else:
        #obtaining width for columns
        max_identifier_length = len("Field Name")
        max_type_length = len("Type")
        max_value_length = len("Value")
        max_unit_length = len("Unit")
        max_note_length = len("Notes")
        i = 0;
        while i < num_values:
            if len(data_identifiers[i]) > max_identifier_length:
                max_identifier_length = len(data_identifiers[i])
            if len(data_types[i]) > max_type_length:
                max_type_length = len(data_types[i])
            if len(data_values[i]) > max_value_length:
                max_value_length = len(data_values[i])
            if len(data_units[i]) > max_unit_length:
                max_unit_length = len(data_units[i])
            if len(data_notes[i]) > max_note_length:
                max_note_length = len(data_notes[i])
            i = i + 1

        #table header information
        rv = rv + "Field Name".ljust(max_identifier_length) \
                + " | " + "Type".rjust(max_type_length) \
                + " | " + "Value".rjust(max_value_length) \
                + " | " + "Unit".rjust(max_unit_length) \
                + " | " + "Notes".ljust(max_note_length) \
                + "\n"

        i = 0
        while i < num_values:
            #print lines in the table
#            rv = rv + "-" * max_identifier_length + "-+-" \
#                    + "-" * max_type_length + "-+-" \
#                    + "-" * max_value_length + "-+-" \
#                    + "-" * max_unit_length + "-+-" \
#                    + "-" * max_note_length + "\n"
            #print data of the table
            rv = rv \
               + data_identifiers[i].ljust(max_identifier_length) \
               + " | " + data_types[i].rjust(max_type_length) \
               + " | " + data_values[i].rjust(max_value_length)\
               + " | " + data_units[i].rjust(max_unit_length) \
               + " | " + data_notes[i].ljust(max_note_length) \
               + "\n"
            i = i + 1
    f.write(rv)





















"""
    f.write("\nIP recieved from:" + ip)
    f.write("\nInstance Id: " + inst_id)
    f.write("\nSensor Id: " + sens_id)
    f.write("\nRead Time: " + read_tm)
    
    f.write("\nIdentifiers: " + iden_ar)
    print "Dest =", dest
    print ip
    print "i_i = ", inst_id
    print sens_id
    print read_tm
    print iden_ar
    print type_ar
    print valu_ar
    print unit_ar
    print note_ar
"""
lc_cmd = "wc -l all.txt | sed 's/\([^ ]*\).*/\\1/'"

sync_cmd = "rsync -v -e ssh ubuntu@149.165.149.3:/export/permanent/waggle_datastore/cerisc-internal/branches/2014/tony/cloudDBforWaggle/vm-149-3_states.dat all.txt"

before = bash(lc_cmd)

bash(sync_cmd)

after = bash(lc_cmd)

line_dif = int(after) - int(before)

#line_dif = 2

line_split_cmd = "sed 's/ *\\[3\\] */|::|/g' | sed 's/ *\\[2\\] */\\n/g' | sed 's/ *\\[1\\] */\\n/g' | sed 's/^|::|//'"

if line_dif > 0:
    to_process = bash("tail -" + str(line_dif) + " all.txt")

    line = ""
    for line in to_process.split('\n'):
        del_split = bash("echo \"" + line + "\" | " + line_split_cmd).split('\n')
        i = 1
        while i + 9 < len(del_split):
            ip = del_split[i]
            inst_id = del_split[i+1]
            sens_id = del_split[i+2]
            read_tm = del_split[i+3]
            iden_ar = del_split[i+4]
            type_ar = del_split[i+5]
            valu_ar = del_split[i+6]
            unit_ar = del_split[i+7]
            note_ar = del_split[i+8]
            print "echo " + inst_id + " | sed 's/\([A-Za-z0-9]*\).*/\\1/"
            Write(bash("echo \"" + inst_id + "\" | sed 's/\([A-Za-z0-9]*\).*/\\1/'"),
                      ip, inst_id, sens_id, read_tm, iden_ar, 
                          type_ar, valu_ar, unit_ar, note_ar)
#            bash("echo \"" + inst_id + "\" >> filenames.out")
#            bash("echo \"" + inst_id + "\" | sed 's/\([A-Za-z0-9]*\).*/\\1/' >> filenames.out")
            
            i = i + 9
#        for entry in del_split.split('\n'):
#            print "=", entry
#        print bash("echo " + line + " | 
        print "##############"
