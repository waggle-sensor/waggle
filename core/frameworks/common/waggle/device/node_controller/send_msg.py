from cloud_config import CLOUD_SERVER_INFO
from data_client import NodeDataClient
import time


data_client = NodeDataClient(*CLOUD_SERVER_INFO)
print data_client
# add try catch to try to establish connection if doesn't exist
def send_msg(msg):
    print data_client.msg_send(msg)

send_msg("Test")