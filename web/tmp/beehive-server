# Beehive Server

Waggle cloud software for aggregation, storage and analysis of sensor data from Waggle nodes

## Installation

The recommended installation method for the waggle beehive server is Docker. But it should be easily possible to install everything in a non-virtualized ubuntu environment. In that case we recommend ubuntu trusty (14.04). If you are using Docker, you can use any operating system with a recent Linux kernel that runs Docker. 

### Docker

To get the latest version of Docker in Ubuntu use this (simply copy-paste the whole block):
```
apt-key adv --keyserver hkp://pgp.mit.edu:80 --recv-keys 58118E89F3A912897C070ADBF76221572C52609D
export CODENAME=$(lsb_release --codename | grep -o "[a-z]*$" | tr -d '\n')
echo "deb https://apt.dockerproject.org/repo ubuntu-${CODENAME} main" >> /etc/apt/sources.list.d/docker.list
apt-get update
apt-get install -y  docker-engine
```

### Data directory
While services are running in containers, configuration files, SSL certificates and databases have to be stored persistently on the host. This is configured in Docker with the -v option (format: "host:container"). Depending on your system you might want to use a different location to store these files.

```bash
export DATA="/mnt"

# other examples:
# export DATA="${HOME}/waggle"
# export DATA="/media/ephemeral/"
```

It might be helful to set this variable permanently. For example, if you are using bash:
```bash
echo "export DATA=/mnt/" >> ~/.bash_profile
```

### Docker network
Docker network provides a mechanism for service discovery. To us it create the network "beehive":
```bash
docker network create beehive
```

To verify these command can be used:
```bash
docker network ls
docker network inspect beehive
```

### SSL certificates

Create certificate authority
```bash
docker pull waggle/beehive-server:latest

[ ! -z "$DATA" ] && docker run -ti \
  --name certs \
  --rm \
  -v ${DATA}/waggle/SSL/:/usr/lib/waggle/SSL/ \
  waggle/beehive-server:latest ./SSL/create_certificate_authority.sh
```  

### Cassandra

See [beehive-cassandra/README.md](./beehive-cassandra/README.md)

### RabbitMQ

See [beehive-rabbitmq/README.md](./beehive-rabbitmq/README.md)

### Beehive Server

If you are not using a Docker container you can install dependencies with this script.
```bash
./install_dependencies.sh
```

#### Build beehive-server Docker image

This step is not needed, as the image is available on Docker Hub.

```bash
docker rm -f beehive-server
docker rmi waggle/beehive-server
docker build -t waggle/beehive-server .
```

#### Client certificate for beehive server
```bash
docker pull waggle/beehive-server:latest

[ ! -z "$DATA" ] && docker run -ti \
  --name certs \
  --rm \
  -v ${DATA}/waggle/SSL/:/usr/lib/waggle/SSL/ \
  waggle/beehive-server:latest ./SSL/create_client_cert.sh server beehive-server
```  


#### Starting the docker container
If cassandra or RabbitMQ are running remotely, omit the corresponding option "--link ..." and configure /etc/waggle/beehive-server.cfg accordingly.

```bash
docker rm -f beehive-server
docker pull waggle/beehive-server
docker run -ti --name beehive-server \
  --net beehive \
  -v ${DATA}/waggle/SSL/:/usr/lib/waggle/SSL/ \
  waggle/beehive-server:latest
```

You should now be inside the container.

**Tip:** For developing purposes you can also mount the git repo into the container.
```bash
-v ${HOME}/git/beehive-server:/usr/lib/waggle/beehive-server
```


#### Configure the beehive server

You can set RabbitMQ and Cassandra hostnames in /etc/waggle/beehive-server.cfg if they are installed remotely. The configure script will create this file if it does not yet exist. 

Run configure script.
```bash
./configure
```

Start the server.
```bash
./Server.py [--logging]
```

The beehive server should be running at this point. 

If you are in a Docker container, leave the container and put it in background using key combinations "Ctrl-P" "Ctrl-Q". You can re-attach to the container with
```bash
docker attach beehive-server
```
or enter the container without attaching to the main process (Server.py) with "docker exec":
```bash
docker exec -ti beehive-server /bin/bash
```

