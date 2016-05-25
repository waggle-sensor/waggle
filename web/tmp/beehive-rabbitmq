## RabbitMQ for Waggle


Be sure that environment variable $DATA is defined, e.g.:
```bash
export DATA="/mnt/"
```

### rabbitmq.config
```bash
mkdir -p ${DATA}/rabbitmq/config/ && \
curl https://raw.githubusercontent.com/waggle-sensor/beehive-server/master/beehive-rabbitmq/rabbitmq.config > ${DATA}/rabbitmq/config/rabbitmq.config
```

### Create SSL server certificate for RabbitMQ
```bash
docker pull waggle/beehive-server:latest

[ ! -z "$DATA" ] && docker run -ti \
  --name certs \
  --rm \
  -v ${DATA}/waggle/SSL/:/usr/lib/waggle/SSL/ \
  waggle/beehive-server:latest ./SSL/create_server_cert.sh
```

This will create server ceritifcates in ${DATA}/waggle/SSL/server. Make sure rabbitmq my can access the directory.

```bash
chmod +x ${DATA}/waggle/SSL/server
```


### CA certificate cacert.pem
In addition to its own private key (key.pem) and certificate (cert.pem), located under /usr/lib/waggle/SSL/beehive-server, RabbitMQ also needs access to the public certificate of the CA. You can either mount that file/directory into the docker container or copy it into the container. The example below mounts the SSL directory.


### Start RabbitMQ server
```bash
docker rm -f beehive-rabbitmq
[ ! -z "$DATA" ] && docker run -d \
  --hostname beehive-rabbitmq \
  --name beehive-rabbitmq \
  -e RABBITMQ_NODENAME=beehive-rabbitmq \
  -v ${DATA}/rabbitmq/config/:/etc/rabbitmq:rw \
  -v ${DATA}/rabbitmq/data/:/var/lib/rabbitmq/:rw \
  -v ${DATA}/waggle/SSL:/usr/lib/waggle/SSL/:ro \
  --expose=23181 \
  -p 23181:23181 \
  --net beehive \
  rabbitmq:3.5.6
```

Or, in case you have problems with file permissions on the host, you might want to call the rabbitmq-server binary directly to invoke it with root rights. Add the full path of the rabbitmq-server binary as an addtional argument to the call above.
```bash
...
rabbitmq:3.5.6 /usr/lib/rabbitmq/bin/rabbitmq-server
```

Confirm RabbitMQ is running:
```bash
docker logs beehive-rabbitmq
```


Create users, set permissions and enable rabbitmq_auth_mechanism_ssl plugin:
```bash
docker exec -ti  beehive-rabbitmq bash -c '\
    rabbitmqctl add_user node waggle  ; \
    rabbitmqctl add_user server waggle  ; \
    rabbitmqctl set_permissions node "node_.*" ".*" ".*"  ; \
    rabbitmqctl set_permissions server ".*" ".*" ".*"  ; \
    rabbitmq-plugins enable rabbitmq_auth_mechanism_ssl'
```


### Alternative installation methods for RabbitMQ:
```bash
# Ubuntu
apt-get install rabbitmq-server
```
or https://www.rabbitmq.com/download.html

