import socket, os, os.path
from multiprocessing import Process, Queue
    
    
class internal_communicator(object):
    """ This class acts as the channel of communication to and from the GN and the NC. The internal_msg_handler pulls messages from the data cache, parses the header, and sends the message to the appropriate location. 
    It also recieves messages from the GNs and pushes them into the data cache.""" 
    
    def __init__(self):
        pass
    DC_push = queue
    incoming_1 = queue
    #temporary dictionary containing device IDs and priorities 
    devices = {'device1' : 1, 'device2' : 2}
    
class client(Process):
    """ A client process that connects to the data cache. """
    #TODO might need two client process: one for push and one for pull
    def run(self):
        comm = internal_communicator()
        print "Connecting to data cache..."
        if os.path.exists('/tmp/Data_Cache_unix_socket_example'):
            client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            client_sock.connect('/tmp/Data_Cache_unix_socket_example')
            print "Ready"
            print "Ctrl-C to quit."
            print "Sending 'DONE' shuts down the server and quits."
            while True:
                #TODO add another layer that can sleep if no messages are in the queue
                try: 
                    data = comm.DC_push.get() #theoretically pushes messages from the GN into a queue
                    if not data:
                        print "sending: " , data
                        client_sock.send(data)
                        if 'DONE' == data:
                            print 'Shutting down.'
                            break
                except KeyboardInterrupt, k:
                    print "Shutting down."
            client_sock.close()
        else:
            print "Couldn't Connect!"
        print "Done."
        
class server(Process):
    """ Server process that listens for connections from GNs. Gets messages from the guest nodes, parses head to get device ID (can also use device IP), and msg_p, 
    puts in tuple form along with indicator flag specifying that it is an outgoing message, stores it in DC_push queue... for now."""
    #TODO handle outgoing messages
    def run(self):
        comm = internal_communicator()
        HOST = ''
        PORT = 9090
        server = socket.socket(socket.AF_INET, socket.SOCKET_STREAM)
        server.bind((HOST,PORT))
        server.listen(5) #supports up to 5 threads, one for each GN
        
        while True:
            conn, addr = server.accept()
            print "Connected to ", addr
            while True:
                try:
                    data = conn.recv(1024) 
                    if not data:
                        break
                    else:
                        #TODO parses header to get device ID and msg_p
                        out_bound = (o, device_p, msg_p, msg)
                        comm.outgoing.put(out_bound)
                except KeyboardInterrupt, k:
                    print "Shutting down."
        server.close()
    
