#!/usr/bin/python3 

import socket, ssl, pprint

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# require a certificate from the server
ssl_sock = ssl.wrap_socket(s,
                           certfile="/digital/g/projects/forest/getziadz/code/ca_certs/CA/certsdb/client0.cert.pem",
                           keyfile="/digital/g/projects/forest/getziadz/code/ca_certs/CA/private/client0.key.pem",
                           ca_certs="/digital/g/projects/forest/getziadz/code/ca_certs/CA/certsdb/ca.cert.pem",
                           cert_reqs=ssl.CERT_REQUIRED)

ssl_sock.connect(('localhost', 12345))

peername = ssl_sock.getpeername()
cert = ssl_sock.getpeercert()


## We verify the hostname as suggested in https://docs.python.org/3.3/library/ssl.html#ssl-security
ssl.match_hostname(cert, "other_name")
##

print ("--------------------------------------")
print (repr(peername))
print ("--------------------------------------")
print (ssl_sock.cipher())
print ("--------------------------------------")
print (pprint.pformat(cert))
print ("--------------------------------------")


# Set a simple HTTP request -- use httplib in actual code.
ssl_sock.write(bytes("""This is a test""", 'UTF-8'))

# Read a chunk of data.  Will not necessarily
# read all the data returned by the server.
data = ssl_sock.read()

# note that closing the SSLSocket will also close the underlying socket
ssl_sock.close()
