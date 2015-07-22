#!/usr/bin/env python

import os, os.path, pika, logging, datetime
#from external_communicator import *
#from internal_communicator import *

time = str(datetime.datetime.now())
LOG_FILE = 'comms_' + time + '.log'
#f = open(LOG_FILE, 'w') #make the new log file
#f.close()
logging.basicConfig(filename=LOG_FILE)

"""

    Communications main starts the internal and external communication processes. It then continuously monitors each of the processes. It restarts the processes of it ever crashes.
"""

if __name__ == "__main__":
    try:
        #TODO if the pika_push and pika_pull clients can be combined into one process, add an if statement to that process that checks for initial contact with the cloud
        if not os.path.isfile('/etc/waggle/queuename'):
            #get the connection parameters
            params = pika.connection.URLParameters("amqps://waggle:waggle@10.10.10.110:5671/%2F") #This will need to change according to where the server is
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
                #print 'Pika pull has crashed. Restarting...'
                logging.warning('Pika pull has crashed. Restarting...' + str(datetime.datetime.now()))
                pika_pull = pika_pull()
                pika_pull.start()
                logging.info('Pika pull restarted.')
                #print 'Pika pull restarted.'
            
            if not pika_push.is_alive():
                #print 'Pika push has crashed. Restarting...'
                logging.warning('Pika push has crashed. Restarting...' + str(datetime.datetime.now()))
                pika_push = pika_push()
                pika_push.start()
                logging.info('Pika push restarted.')
                #print 'Pika push restarted.'
                
            if not external_push_client.is_alive():
                #print 'External push client has crashed. Restarting...'
                logging.warning('External push client has crashed. Restarting...' + str(datetime.datetime.now()))
                external_push_client = external_client_push()
                external_push_client.start()
                logging.info('External_push_client restarted.')
                #print 'External_push_client restarted.'
                
            if not external_pull_client.is_alive():
                #print 'external_pull_client has crashed. Restarting...'
                logging.warning('external_pull_client has crashed. Restarting...' + str(datetime.datetime.now()))
                external_pull_client = external_client_pull()
                external_pull_client.start()
                logging.info('external_pull_client restarted.')
                #print 'external_pull_client restarted.'
                
            if not pull_serv.is_alive():
                #print 'pull_serv has crashed. Restarting...'
                logging.warning('pull_serv has crashed. Restarting...' + str(datetime.datetime.now()))
                pull_serv = pull_server()
                pull_serv.start()
                logging.info('pull_serv restarted.')
                #print 'pull_serv restarted.'
                
            if not push_serv.is_alive():
                #print 'push_serv has crashed. Restarting...'
                logging.warning('push_serv has crashed. Restarting...' + str(datetime.datetime.now()))
                push_serv = push_server()
                push_serv.start()
                logging.info('push_servrestarted.')
                #print 'push_servrestarted.'
                
            if not internal_push_client.is_alive():
                #print 'internal_push_client has crashed. Restarting...'
                logging.warning('internal_push_client has crashed. Restarting...' + str(datetime.datetime.now()))
                internal_push_client = internal_client_push()
                internal_push_client.start()
                logging.info('internal_push_client restarted.')
                #print 'internal_push_client restarted.'
                
            if not internal_pull_client.is_alive():
                #print 'internal_pull_client has crashed. Restarting...'
                logging.warning('internal_pull_client has crashed. Restarting...' + str(datetime.datetime.now()))
                internal_pull_client = internal_client_pull()
                internal_pull_client.start()
                logging.info('internal_pull_client restarted.')
                #print 'internal_pull_client restarted.'
                
            time.sleep(3)

        ##terminate the external communication processes
        #pika_pull.terminate()
        #pika_push.terminate()
        #external_push_client.terminate()
        #external_pull_client.terminate()
        #print 'External communications shut down.'

        ##terminate the internal communication processes
        #pull_serv.terminate()
        #push_serv.terminate()
        #internal_push_client.terminate()
        #internal_pull_client.terminate()
        #print 'Internal communications shut down.'                
                
                
        
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