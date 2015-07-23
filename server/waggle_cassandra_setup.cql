CREATE KEYSPACE IF NOT EXISTS waggle;

CREATE TABLE waggle.sensor_data (
    node_id int,
    sensor_name ascii,
    timestamp int,
    data list<double>,
    data_types list<ascii>,
    extra_info list<ascii>,
    units list<ascii>,
    PRIMARY KEY (node_id, sensor_name, timestamp)
);