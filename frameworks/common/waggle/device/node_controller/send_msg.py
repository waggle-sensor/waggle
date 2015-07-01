from cloud_config import CLOUD_SERVER_INFO
from data_client import NodeDataClient
import time


data_client = NodeDataClient(*CLOUD_SERVER_INFO)

# add try catch to try to establish connection if doesn't exist
def send_msg(msg):
    try: 
        data_client.msg_send(msg)
        print "...."
    except:
        while 1:
            try: 
                data_client = NodeDataClient(*CLOUD_SERVER_INFO)
                break
            except:
                print "Lost connection to cloud ... retrying..."
                time.sleep(3)
    data_client.msg_send(msg)
            
        

