#!/bin/bash


export SSL_DIR = "/usr/lib/waggle/SSL"

# Begin constructing the Certificate Authority
cd ${SSL_DIR}/waggleca

# Make appropriate folders
mkdir -p certs private
chmod 700 private
echo 01 > serial
touch index.txt

# Generate the root certificate

openssl req -x509 -config openssl.cnf -newkey rsa:2048 -days 365 \
	-out cacert.pem -outform PEM -subj /CN=waggleca/ -nodes

openssl x509 -in cacert.pem -out cacert.cer -outform DER

# Make the server certificate

cd ${SSL_DIR} # in SSL/

mkdir -p server
chmod 744 server
cd ${SSL_DIR}/server

openssl genrsa -out key.pem 2048

openssl req -new -key key.pem -out req.pem -outform PEM \
	-subj /CN=$(hostname)/O=server/ -nodes

cd ${SSL_DIR}/waggleca

openssl ca -config openssl.cnf -in ${SSL_DIR}/server/req.pem -out \
	${SSL_DIR}/server/cert.pem -notext -batch -extensions server_ca_extensions

cd ${SSL_DIR}/server
openssl pkcs12 -export -out keycert.p12 -in cert.pem -inkey key.pem -passout pass:waggle


# Copy files to correct places
cp ${SSL_DIR}/rabbitmq.config /etc/rabbitmq/

#does not make sense: cp -r SSL /usr/lib/waggle/

service rabbitmq-server restart
