#!/usr/bin/env python

from waggle.common.util import *
from waggle.common.messaging import *
import logging
from waggle.cloud.connectors import *

def register(msg, cass_connector):
    inst_id = 'inst_id-' + str(uuid.uuid4())
    sensor_id_list = ['sensor_id-' + randomStringGen(5), 'sensor_id-' + randomStringGen(5)]
    last_reg_time = str(time.time())
    status = 'pending'
    part1 = "insert into registration( inst_id, sensor_id, status, last_reg_time) values ( "
    part2 = "'" + inst_id + "', " + converToStr(sensor_id_list) + ", '" + status + "', '" + last_reg_time + "'"
    statement = part1 + part2  + ")"
    print statement
    cass_connector._executeCQL(statement)
    #pass

def pushCMD(msg, cass_connector):
    username ='Tony'
    seq_num = str(id(username))
    inst_id = 'inst_id-' + str(uuid.uuid4())
    command = 'cmd-' + randomStringGen(40)
    execution_status = 'pending'
    timestamp = str(time.time())
    part1 = "insert into commands(username, seq_num, inst_id, command, execution_status, timestamp) values ( "
    part2 = "'" + username + "', '" + seq_num + "', '" + inst_id + "', '" + command + "', '" + execution_status + "', '" + timestamp + "'"
    statement = part1 + part2  + ")"
    print statement
    cass_connector._executeCQL(statement)
    cass_connector._executeCQL(statement)
    #pass

def checkCMD(inst_id, status, cass_connector):
    part1 = "select command from commands where inst_id = '" + inst_id 
    part2 = "' and execution_status = '" + status + "' ALLOW FILTERING;"
    statement = part1 + part2
    print statement
    rows = cass_connector._executeCQL(statement)
    results = []
    for it in rows:
        results.append(it[0])
    return results

def unitTest():
    cass_connector = CassConnector(['149.165.149.3', '149.165.149.8'], 'weatherdb')
    #pushCMD('something', cass_connector)
    #register('something', cass_connector)
    result = checkCMD('aainst_id-843c0fed-4b5d-4171-8358-d641493623ec', 'pending', cass_connector)
    print result
    for it in result:
        print it


unitTest() 
