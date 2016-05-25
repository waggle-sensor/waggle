### Cassandra

Be sure that environment variable $DATA is defined.
```bash
[ ! -z "$DATA" ] && \
docker run -d \
--name beehive-cassandra \
--net beehive \
-v ${DATA}/cassandra/:/var/lib/cassandra/ \
--ulimit memlock=-1 \
--ulimit nofile=100000 \
--ulimit nproc=32768 \
--cap-add IPC_LOCK \
cassandra:3.2 -R
```
For simple testing without much data you can omit option "-v" above. Without "-v" Cassandra data is not stored persistently and data is lost when the container is removed. Add port mapping "-p 7000:7000" if the beehive server does not run on the same host as the cassandra database.


Installation instructions for Cassandra without Docker:

http://docs.datastax.com/en/cassandra/2.0/cassandra/install/installDeb_t.html


#### Notes

To directly connect to cassandra:
```bash
docker run -it --net beehive --rm cassandra:3.2 cqlsh beehive-cassandra
```
To view database, e.g.:
```bash
use waggle;
DESCRIBE TABLES;
SELECT * FROM nodes;
SELECT * FROM sensor_data;
```


#### Troubleshooting

In case of multiple corrupt commit log files, files can be deleted in a more automated way using a bash loop. Start the cassandra container using --entrypoint=/bin/bash to get a terminal.

```bash
BAD_FILE='x'
while [ "${BAD_FILE}x" != 'x' ] ; do 
  export BAD_FILE=$(cassandra -f -R | grep CommitLogReplayException | grep -o "/var/lib/cassandra/commitlog/CommitLog-6-[0-9]*.log")
  echo "delete ${BAD_FILE}"
  rm -f ${BAD_FILE}
done
```
