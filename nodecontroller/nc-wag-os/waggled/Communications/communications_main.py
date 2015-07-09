#!/usr/bin/env python


from external_communicator import *
from internal_communicator import *

if __name__ == "__main__":
    try:
            
        #start the external communication processes
        #start the pika pull client
        pika_pull = pika_pull()
        pika_pull.start()
        
        #start the pika push client 
        pika_push = pika_push()
        pika_push.start()
        
        #starts the push client
        external_push_client = external_client_push()
        external_push_client.start()
        
        #starts the pull client
        external_pull_client = external_client_pull()
        external_pull_client.start()
        
        #start the internal communication processes
        #start the pull server
        pull_serv = pull_server()
        pull_serv.start()
        
        #start the push server 
        push_serv = push_server()
        push_serv.start()
        
        #start the push client
        internal_push_client = internal_client_push()
        internal_push_client.start()
        
        #start the pull client
        internal_pull_client = internal_client_pull()
        internal_pull_client.start()
        while True:
            pass
        
    except KeyboardInterrupt, k:
        #terminate the external communication processes
        pika_pull.terminate()
        pika_push.terminate()
        external_push_client.terminate()
        external_pull_client.terminate()
        print 'External communications shut down.'
        
        #terminate the internal communication processes
        pull_serv.terminate()
        push_serv.terminate()
        internal_push_client.terminate()
        internal_pull_client.terminate()
        print 'Internal communications shut down.'