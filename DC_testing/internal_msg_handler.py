import socket, os, os.path
    
    
class internal_msg_handler(object):
    """ This class acts as the channel of communication to and from the GN and the NC. The internal_msg_handler pulls messages from the data cache, parses the header, and sends the message to the appropriate location. 
    It also recieves messages from the GNs and pushes them into the data cache.""" 
    
    def __init__(self):
        pass
    
    def client(self):
        print "Connecting to data cache..."
        if os.path.exists('/tmp/Data_Cache_unix_socket_example'):
            client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            client_sock.connect('/tmp/Data_Cache_unix_socket_example')
            print "Ready"
            print "Ctrl-C to quit."
            print "Sending 'DONE' shuts down the server and quits."
            while True:
                try: 
                    data = 'some stuff in a message'
                    if "" != data:
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