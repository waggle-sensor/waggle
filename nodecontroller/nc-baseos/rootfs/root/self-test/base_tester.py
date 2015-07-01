import sys
import logging
import re
from os.path import isfile
from os import environ

SELF_TEST_LOG_DIR=environ['SELF_TEST_LOG_DIR']

### Lock file
DEFAULT_LOCK_FILE=SELF_TEST_LOG_DIR + "/stress_test.lock"

### Log file
DEFAULT_LOG_FILE=SELF_TEST_LOG_DIR + "/stress_test.log"

### Lockstep file
DEFAULT_LOCKSTEP_FILE=SELF_TEST_LOG_DIR + "/lockstep.log"
DEFAULT_LOCKSTEP_FILE_BACKUP=SELF_TEST_LOG_DIR + "/lockstep.log.old"

### Configuration file
DEFAULT_CONFIG_FILE=SELF_TEST_LOG_DIR + "/stress_test.conf"

SELF_TEST_APP_DIR=environ['SELF_TEST_APP_DIR']

def flush_print(out, msg):
    out.write(msg)
    out.flush()

class BaseTester:
    def __init__(self):
        logging.basicConfig(filename=DEFAULT_LOG_FILE, level=logging.DEBUG)
        self.logger = logging.getLogger("base_tester")
    
    ### Validate object's integrity before running anything
    def validate_integrity(self):
        self.logger.error("Implement validate_integrity")
        return True
        
    ### System configuration
    def load_last_configuration(self):
        self.logger.error("Implement load_last_configuration")
        return True

    def save_configuration(self):
        self.logger.error("Implement save_configuration")
        return True

    def file_exists(self, f, msg):
        if not isfile(f):
            self.logger.error(msg)
            return False
        return True
