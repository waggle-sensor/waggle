from cloud_config import CLOUD_SERVER_INFO
from data_client import NodeDataClient

def send_msg(msg):
    data_client = NodeDataClient(*CLOUD_SERVER_INFO)
    data_client.msg_send(msg)
    data_client.close()
    

