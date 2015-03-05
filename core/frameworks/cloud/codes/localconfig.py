WWW_PREFIX = "/var/www/html/" #Where the webpages will be served from

LOCAL_DIR = "/tmp/wag/"
COUNTER_FILE = LOCAL_DIR+"lines_processed.in"
WORKING_CACHE_DIR = LOCAL_DIR+"/current" #Where the local cache of infiles will be stored
SENSOR_DATA_EXCHANGE_FILE = LOCAL_DIR+"/beehive.dat" #where the beehive datafile is stored
REG_DATA_EXCHANGE_FILE = LOCAL_DIR+"/beesnames.dat" #where the regestitation messages go. 

BEEHIVE_IP = "127.0.0.1"
BEEHIVE_PORT = 23181
BEEHIVE_UNAME = 'beehive'
BEEHIVE_PWD = 'queenB'
BEEHIVE_RTK = 'default_queue'
BEEHIVE_EXCHANGE = ''