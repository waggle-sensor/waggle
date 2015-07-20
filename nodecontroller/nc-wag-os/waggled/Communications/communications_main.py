#!/usr/bin/env python

import os, os.path, pika
#from external_communicator import *
#from internal_communicator import *

"""

    Communications main starts the internal and external communication processes.
"""

if __name__ == "__main__":
    try:
        #TODO if the pika_push and pika_pull clients can be combined into one process, add an if statement to that process that checks for initial contact with the cloud
        if not os.path.isfile('/etc/waggle/queuename'):
            #get the connection parameters
            params = pika.connection.URLParameters("amqps://waggle:waggle@10.10.10.104:5671/%2F") #This will need to change according to where the server is
            #make the connection
            connection = pika.BlockingConnection(params)
            #create the channel
            channel = connection.channel()
            #queue_declare is left empty so RabbitMQ assigns a unique queue name
            result = channel.queue_declare()
            #get the name of the randomly assigned queue
            queuename = result.method.queue
            #close the connection
            connection.close()
            
            #strip 'amq.gen-' from queuename
            junk, queuename = queuename.split('-', 1)
            
            #write the queuename to a file
            file_ = open('/etc/waggle/queuename', 'w') 
            file_.write(queuename)
            file_.close()
        
        from external_communicator import *
        from internal_communicator import *
        
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
            if not pika_pull.is_alive():
                print 'Pika pull has crashed. Restarting...'
                pika_pull = pika_pull()
                pika_pull.start()
                print 'Pika pull restarted.'
            
            if not pika_push.is_alive():
                print 'Pika push has crashed. Restarting...'
                pika_push = pika_push()
                pika_push.start()
                print 'Pika push restarted.'
                
            if not external_push_client.is_alive():
                print 'External push client has crashed. Restarting...'
                external_push_client = external_client_push()
                external_push_client.start()
                print 'External_push_client restarted.'
                
            if not external_pull_client.is_alive():
                print 'external_pull_client has crashed. Restarting...'
                external_pull_client = external_client_pull()
                external_pull_client.start()
                print 'external_pull_client restarted.'
                
            if not pull_serv.is_alive():
                print 'pull_serv has crashed. Restarting...'
                pull_serv = pull_server()
                pull_serv.start()
                print 'pull_serv restarted.'
                
            if not push_serv.is_alive():
                print 'push_serv has crashed. Restarting...'
                push_serv = push_server()
                push_serv.start()
                print 'push_servrestarted.'
                
            if not internal_push_client.is_alive():
                print 'internal_push_client has crashed. Restarting...'
                internal_push_client = internal_client_push()
                internal_push_client.start()
                print 'internal_push_client restarted.'
                
            if not internal_pull_client.is_alive():
                print 'internal_pull_client has crashed. Restarting...'
                internal_pull_client = internal_client_pull()
                internal_pull_client.start()
                print 'internal_pull_client restarted.'
                
            time.sleep(3)

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