from configobj import ConfigObj
import ElementTree as ET


config = ''
tree = '' #replace file name with a file containing the system info

parentkey = ''
newroot = []
depth = []
listdict = {}
list_of_keys = []
tags_list = []

d = {}
i = 0
max_depth = 0

def dict_check(child):
    if child.text == '\n  ' or child.tag == "node" or child.text == '\n    ' or child.text == '\n     ' or child.text == '\n      ' or child.text == '\n       ' or child.text == '\n         ' or child.text == '\n           ':
        return True
    else:
        return False

def addchildren(parent, pdepth, cur_key):
    global max_depth
    global i
    if parent.tag == "node":
        tag = parent.get("id")
    else:
        tag = parent.tag
    tags_list.append(tag)
    #print tags_list
    if tag != "capabilities" and tag != "configuration" and tag != "resources":
        if pdepth > max_depth:
            max_depth = pdepth
            listdict[max_depth] = []
        mytag = ""
        for k in range(len(tags_list)):
            if k == len(tags_list) - 1:
                mytag = mytag + tags_list[k]
            else:
                mytag = mytag + tags_list[k] + "."
        #print mytag
        listdict[pdepth].append(mytag)
    cur_key = cur_key[tag]

    for child in parent:
        if dict_check(child):
            if child.tag == "node":
                cur_key[child.get("id")] = {}
                ctag = child.get("id")
            else:
                cur_key[child.tag] = {}
                ctag = child.tag
            addchildren(child, pdepth + 1, cur_key)
        else:
            if child.get("id") != None:
                if child.get("value") != None:
                    cur_key[child.get("id")] = child.get("value")
                else:
                    cur_key[child.get("id")] = child.text
            elif child.get("type") != None:
                if child.get("value") != None:
                    #FIXED
                    if child.get("type") in cur_key:
                        if type(cur_key[child.get("type")]) is list:
                            cur_key[child.get("type")].append(child.get("value"))
                        else:
                            d["list" + str(i)] = []
                            d["list" + str(i)].append(cur_key[child.get("type")])
                            d["list" + str(i)].append(child.get("value"))
                            cur_key[child.get("type")] = d["list" + str(i)]
                            i += 1
                    else:
                        cur_key[child.get("type")] = child.get("value")
                else:
                    #FIXED
                    if child.get("type") in cur_key:
                        if type(cur_key[child.get("type")]) is list:
                            cur_key[child.get("type")].append(child.text)
                        else:
                            d["list" + str(i)] = []
                            d["list" + str(i)].append(cur_key[child.get("type")])
                            d["list" + str(i)].append(child.text)
                            cur_key[child.get("type")] = d["list" + str(i)]
                            i += 1
                    else:
                        cur_key[child.get("type")] = child.text
            elif child.get("units") != None:
                cur_key[child.tag] = child.text + " " + child.get("units")
            else:
                #FIXED
                if child.tag in cur_key:
                    if type(cur_key[child.tag]) is list:
                        cur_key[child.tag].append(child.text)
                    else:
                        d["list" + str(i)] = []
                        d["list" + str(i)].append(cur_key[child.tag])
                        d["list" + str(i)].append(child.text)
                        cur_key[child.tag] = d["list" + str(i)]
                        i += 1
                else:
                    cur_key[child.tag] = child.text
    tags_list.pop()

    
def lshw_parser(config_file_name, lshw_xml__file_name):
    global config
    global tree
    global parentkey
    global newroot
    global depth
    global listdict
    global list_of_keys
    global tags_list

    global d 
    global i
    global max_depth

    
    config = ConfigObj(config_file_name)
    tree = ET.parse(lshw_xml__file_name) #replace file name with a file containing the system info
    parentkey = config["Systems Info"]
    root = tree.getroot()

    parentkey["id"] = root.get("id")
    parentkey["list_of_keywords"] = list_of_keys

    for child in root:
        if dict_check(child):
            if child.tag == "node":
                parentkey[child.get("id")] = {}
            else:
                parentkey[child.tag] = {}
            newroot.append(child)
            depth.append(1)
        elif child.get("units") != None:
            parentkey[child.tag] = child.text + " " + child.get("units")
        else:
            parentkey[child.tag] = child.text

    while len(newroot) != 0:
        parent = newroot.pop()
        pdepth = depth.pop()

        addchildren(parent, pdepth, parentkey)
        for child in parent:
            if type(child.tag) is dict:
                addchildren(child, pdepth + 1, parentkey)

    for j in range(1,max_depth+1):
        list_of_keys.append(listdict[j])

    config.write()
    #print config
