#!/usr/bin/python3 

import socket, ssl

bindsocket = socket.socket()
bindsocket.bind(('localhost', 12345))
bindsocket.listen(5)

def do_something(connstream, data):
    print (data)
    return False

def deal_with_client(connstream):
    data = connstream.read()
    # null data means the client is finished with us
    while data:
        if not do_something(connstream, data):
            # we'll assume do_something returns False
            # when we're finished with client
            break
        data = connstream.read()
    # finished with client



while True:
    newsocket, fromaddr = bindsocket.accept()
    connstream = ssl.wrap_socket(newsocket,
                                 server_side=True,
                                 certfile="/digital/g/projects/forest/getziadz/code/ca_certs/CA/certsdb/server.cert.pem",
                                 keyfile="/digital/g/projects/forest/getziadz/code/ca_certs/CA/private/server.key.pem",
                                 ca_certs="/digital/g/projects/forest/getziadz/code/ca_certs/CA/certsdb/ca.cert.pem",
                                 ssl_version=ssl.PROTOCOL_TLSv1,
                                 cert_reqs=ssl.CERT_REQUIRED)
    try:
        deal_with_client(connstream)
    finally:
        connstream.shutdown(socket.SHUT_RDWR)
        connstream.close()

