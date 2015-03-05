#!/usr/bin/env python
from cassandra.cluster import Cluster
from cassandra import *
class CassConnector:
    def __init__(self, knownHosts, keyspace):
        '''
        Parameters
        ----------
        knownHosts: list of IP/host
            Look like this: ['149.165.149.14', '149.165.149.25']
        '''
        self.myCluster = Cluster(knownHosts)
        self.mySession = self.myCluster.connect(keyspace)

    def _executeCQL(self, exp):
        '''
        Danger: Use this carefully!
        '''
        return self.mySession.execute(exp)


"""
hosts = ['149.165.149.14', '149.165.149.25']
keyspace = 'weatherdb'
myConn = CassConnector(hosts, keyspace)
query1 = 'select * from test'
insert1 = "insert into test (instid, sensorid, ip, readtime, recvTime, paramname, paramType, paramVal, paramUnit, paramNote) values ('inst-100003', 'sensor-2187', '149.165.149.19', '1503703571.15', '1893103571.15',['name1', 'name2', 'name3'], ['type1','type2','type3'], ['val1','val2','val3'], ['unit1', 'unit2', 'unit3'], ['note1', 'note2', 'note3'])"
 
exp = query1
#print myConn._executeCQL(exp)
"""

'''
# Test case for remote access to Cassandra 
myCluster = Cluster(['149.165.149.14', '149.165.149.25'])
mySession = myCluster.connect('weatherdb')

myQuery = "insert into test (instid, sensorid, ip, readtime, recvTime, paramname, paramType, paramVal, paramUnit, paramNote) values ('inst-100002', 'sensor-2087', '149.165.149.19', '1403703571.15', '1863103571.15',['name1', 'name2', 'name3'], ['type1','type2','type3'], ['val1','val2','val3'], ['unit1', 'unit2', 'unit3'], ['note1', 'note2', 'note3'])"

print mySession.execute(myQuery)
'''


# Sample Cassandra DB created with following commands in CQL
# CREATE KEYSPACE weatherdb WITH replication = {'class': 'SimpleStrategy', 'replication_factor' : 1};
#create table test(instID varchar, sensorID varchar, ip varchar, readTime varchar, recvTime varchar, paramName list<text>, paramType list<text>, paramVal list<text>, paramUnit list<text>, paramNote list<text>, primary key (instID, sensorID, readTime));




'''
#Test case and example
# RabbitMQ specific parameters
RMQ_ip = '149.165.149.14' #'192.168.1.29'
RMQ_port = 5672
RMQ_user = 'clients'
RMQ_passwd = 'Ruza3que'
RMQ_exchange = ''
RMQ_routing_key = 'hello'

dataClient = NodeDataClient(RMQ_ip, RMQ_port, RMQ_user, RMQ_passwd, RMQ_exchange, RMQ_routing_key)



#Sample msg data
names = ['name1','name2','name3','name4']
types = ['type1','type2','type3','type4']
data = ['data1','data2','data3','data4']
unit = ['unit1','unit2','unit3','unit4']
note = ['note1','note2','note3','note4']
msg = NodeDataClient.msg_gen('instance-123', 'sensor-456', str(time.time()), names, types, data, unit, note)

msgArray = [msg, msg]

#dataClient.msg_send(msg)
#dataClient.multi_send( msgArray)


#dataClient.blob_send('blobSrc', 'blobDest', 'successMsg', 'failMsg')

#dataClient.connection.close()



'''
