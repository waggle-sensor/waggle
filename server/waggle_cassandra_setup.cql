CREATE KEYSPACE IF NOT EXISTS waggle WITH replication = {'class': 'SimpleStrategy', 'replication_factor': '2'}  AND durable_writes = true;


CREATE TABLE waggle.sensor_data (
    node_id int,
    sensor_name ascii,
    timestamp timestamp,
    data list<double>,
    data_types list<ascii>,
    extra_info list<ascii>,
    units list<ascii>,
    PRIMARY KEY (node_id, sensor_name, timestamp)
);


CREATE TABLE waggle.node_info (
    node_id int PRIMARY KEY,
    timestamp timestamp,
    config_file ascii,
    extra_notes list<ascii>,
    sensor_names list<ascii>,
    height double,
    latitude double,
    longitude double,
    name ascii
);

