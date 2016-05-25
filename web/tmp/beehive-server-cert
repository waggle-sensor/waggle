
# Certificate Server for Waggle
 
Do not use this for production purposes ! 

## web.py
The required python package web.py is already included in the depedencies of the beehive server. If web.py is not already installed it can be installed in one of these ways:
```bash
apt-get install python-webpy
#or
pip install web.py
```

## Build image:
```bash
docker rm -f beehive-cert
docker rmi waggle/beehive-cert
docker pull waggle/beehive-server
docker build -t waggle/beehive-cert .
```



## Run
```bash
docker rm -f beehive-cert
[ ! -z "$DATA" ] && \
docker run -ti \
  -p 24181:80 \
  -v ${DATA}/waggle/SSL/:/usr/lib/waggle/SSL/ \
  --name beehive-cert \
  --net beehive \
  waggle/beehive-cert /bin/bash
cd /usr/lib/waggle/beehive-server/beehive-cert ; ./cert-serve.py
```
