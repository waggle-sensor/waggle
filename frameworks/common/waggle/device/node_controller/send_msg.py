from cloud_config import CLOUD_SERVER_INFO
from data_client import NodeDataClient
import time


data_client = NodeDataClient(*CLOUD_SERVER_INFO)
# add try catch to try to establish connection if doesn't exist
def send_msg(msg):
    print ("Ready to send msg:%0.4f"%time.time())
#    print ("connection established:%0.4f"%time.time())
    data_client.msg_send(msg)
    print ("Msg sent :%0.4f"%time.time())
#    data_client.close()
#    print ("Socket closed:%0.4f"%time.time())

