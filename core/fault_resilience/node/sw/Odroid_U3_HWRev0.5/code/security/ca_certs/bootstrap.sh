#!/bin/bash


ROOT_DIR=`pwd`
LOCAL_OPENSSL_CONFIG=${ROOT_DIR}/openssl.cnf

COMMAND=$1

CA_DIR=${ROOT_DIR}/CA
OPENSSL_CONFIG=${CA_DIR}/openssl.cnf

SERVER_ID="$2"

if [ ! -e ${CA_DIR} ]
then
    echo "Initializing directory structure"
##
    mkdir ${CA_DIR}
    cd ${CA_DIR}
    mkdir {certsdb,certreqs,crl,private}
    chmod 700 private
    touch index.txt
    cp ${LOCAL_OPENSSL_CONFIG} .
fi

ROOT_KEY=${CA_DIR}/private/ca.key.pem
ROOT_CSR=${CA_DIR}/certreqs/ca.req.pem
ROOT_CERT=${CA_DIR}/certsdb/ca.cert.pem

# Server variables
SERVER_KEY=${CA_DIR}/private/${SERVER_ID}.key.pem
SERVER_CSR=${CA_DIR}/certreqs/${SERVER_ID}.req.pem
SERVER_CERT=${CA_DIR}/certsdb/${SERVER_ID}.cert.pem


if [ "$COMMAND" == "GEN_CA" ]
then
    cd ${CA_DIR}
    
    echo "Generating key pair (private key and CSR)"
    openssl req -verbose -new -newkey rsa:2048 -keyout ${ROOT_KEY} -out ${ROOT_CSR} -config ${OPENSSL_CONFIG}
    
    echo "Generate self signed certificate"
    openssl ca -verbose -create_serial -out ${ROOT_CERT} -days 365 -keyfile ${ROOT_KEY} -selfsign -extensions v3_ca_has_san -config ${OPENSSL_CONFIG} -infiles ${ROOT_CSR}

elif [ "$COMMAND" == "SERVER_CSR" ]
then
    cd ${CA_DIR}

    echo "Generate server key"
    openssl genrsa -out ${SERVER_KEY} 4096
    chmod 400 ${SERVER_KEY}

    echo "Generate certificate signing request"
    openssl req -new -key ${SERVER_KEY} -out ${SERVER_CSR} -config ${OPENSSL_CONFIG}

elif [ "$COMMAND" == "SERVER_SIGN" ]
then
    cd ${CA_DIR}
    echo "Sign server certificate"
    openssl ca -keyfile ${ROOT_KEY} -cert ${ROOT_CERT} -extensions usr_cert -notext -md sha1 -in ${SERVER_CSR} -out ${SERVER_CERT} -config ${OPENSSL_CONFIG}
#openssl ca -verbose -config ${OPENSSL_CONFIG} -keyfile ${ROOT_KEY} -cert ${ROOT_CERT} -extensions v3_ca -infiles ${SERVER_CSR} -out ${SERVER_CERT} 
fi
