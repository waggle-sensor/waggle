import logging
import subprocess
from sys import exit
from sys import stdout
from os.path import isfile
import re

import base_tester
from base_tester import flush_print
from base_tester import DEFAULT_LOG_FILE, DEFAULT_LOCKSTEP_FILE, \
                        DEFAULT_CONFIG_FILE, DEFAULT_LOCKSTEP_FILE_BACKUP

from base_tester import SELF_TEST_APP_DIR 

"""
Default values for Memory stress application stress tests
"""

DEFAULT_MEMORY_STRESS_APP = SELF_TEST_APP_DIR + "/stressapptest-read-only/install/bin/stressapptest"
DEFAULT_MEMORY_STRESS_APP_ARGS = ""
DEFAULT_TIMEOUT = 2


DEFAULT_LOCKSTEP_GREPID = "MEMORY_LOCKSTEP"
DEFAULT_CONFIG_GREPID = "MEMORY_CONFIG"

class CPUTester(base_tester.BaseTester):
    """
    """

    def __init__(self):
        """
        Constructor that initializes all attributes to default values, and opens
        the logger and the lockstep handlers
        """

        logging.basicConfig(filename=DEFAULT_LOG_FILE, level=logging.DEBUG)
        self.logger = logging.getLogger("memory_tester")
        
        self.name = "Memory stress application"

        self.attr = { "stress_app": DEFAULT_MEMORY_STRESS_APP,
                      "stress_app_args": DEFAULT_MEMORY_STRESS_APP_ARGS,
                      "timeout": DEFAULT_TIMEOUT}

        self.lockstep_out = stdout
        self.logger.info("Memory stress object generated successfuly")

    def set_lockstep_out(self, out):
        """ Assign new stream to the lockstep_out attribute of the object instance """
        self.lockstep_out = out

    def validate_integrity(self):
        """ Validate the integrity of the object configuration. File existence """
        if not isfile(self.attr["stress_app"]):
            self.logger.error("File \"{}\" does not exist".format(self.attr["stress_app"]))
            return False
        return True
    
    def load_configuration(self, config_file = DEFAULT_CONFIG_FILE):
        """ Load attributes from given configuration file """

        if not isfile(config_file):
            self.logger.error("Could not find configuration file \"{}\"".format(config_file))
            return False

        config_in = open(config_file, "r")
        for line in config_in:
            if re.match("(.*){}(.*)".format(DEFAULT_CONFIG_GREPID), line):
                line = line.strip("\n")
                token = line.split(",")
                self.logger.info("FROM LOADED CONFIG: {} {}".format(token[1], token[2]))
                self.attr[token[1]] = token[2]

        config_in.close()

        return True

    def save_configuration(self, config_out = stdout):
        """ Save attributes to given configuration file stream """
        for key in self.attr.keys():
            config_out.write("{},{},{}\n".format(DEFAULT_CONFIG_GREPID,
                                                 key,
                                                 self.attr[key]))

        return True

    def parse_lockstep_file(self, lockstep_file = DEFAULT_LOCKSTEP_FILE):
        """
        Parse a lockstep file to find the last stress test configuration of this
        module that did not crash the system.
        """
           
        if not isfile(lockstep_file):
            self.logger.error("Could not find lockstep file \"{}\"".format(lockstep_file))
            return False

        lockstep_in = open(lockstep_file, "r")
        for line in lockstep_in:
            if re.match("(.*){}(.*)".format(DEFAULT_LOCKSTEP_GREPID), line):
                line = line.strip("\n")
                token = line.split(",")
                token_num = len(token)
                assert((token_num-1) % 2 == 0)

                i = 1
                while i < token_num:
                    self.logger.info("FROM PREVIOUS LOCKSTEP: {} {}".format(token[i], token[i+1]))
                    self.attr[token[i]] = token[i+1]
                    i = i + 2

        lockstep_in.close()
        return True
        

    def stress(self):
        """
        Performs the stress routines on the CPU
        """


	### The executed stress application needs to be one string
        ### TODO: expand on why we can not use subprocess.call 
 	###       with split binary and argument list
        call_str = self.attr["stress_app"] + " " + self.attr["stress_app_args"].format(cpus,
                                                                                       util,
                                                                                       self.attr["timeout"])
        self.logger.info("Iteration: {} {}".format(cpus, util))
        # Call cpu stress application
        return_code = subprocess.call(call_str, shell=True)

        # Something went wrong with the execution of our stress test
        if return_code:
            self.logger.error("Error {0} at cpu stress {1} {2}".format(return_code, cpus, util))
            self.attr["cpu_max"] = str(cpus)
            self.attr["util_max"] = str(util)
            flush_print(self.lockstep_out, "{},END,ERROR,{}\n".format(DEFAULT_LOCKSTEP_GREPID, return_code))
            return False

        # Update lockstep log
        flush_print(self.lockstep_out, "{},cpu_max,{},util_max,{}\n".format(DEFAULT_LOCKSTEP_GREPID,
                                                                            cpus,
                                                                            util))
  
        return True

if __name__ == "__main__":
    ###
    ### Independent test of the module
    ###
    # from shutil import move
    
    # parse_previous_lockstep = False
    # imprecise_shutdown = True
    # if isfile(DEFAULT_LOCKSTEP_FILE) and imprecise_shutdown:
    #     print("There was an improper shutdown and I found a lockstep file")
    #     move(DEFAULT_LOCKSTEP_FILE, DEFAULT_LOCKSTEP_FILE_BACKUP)
    #     parse_previous_lockstep = True
    # else:
    #     print("No Improper shutdown or lockstep file")

    # # Generate stress object
    # cpu_tester = CPUTester()
    
    # if isfile(DEFAULT_CONFIG_FILE):
    #     print("Found default configuration file")
    #     cpu_tester.load_configuration()
    # else:
    #     print("No default configuration file")

    # if parse_previous_lockstep:
    #     print("Parsing previous lockstep file")
    #     cpu_tester.parse_lockstep_file(DEFAULT_LOCKSTEP_FILE_BACKUP)



    # lockstep_out = open(DEFAULT_LOCKSTEP_FILE, "w")
    # cpu_tester.set_lockstep_out(lockstep_out)
    # print("Stress CPU")
    # cpu_tester.stress()
    # lockstep_out.close()

    # # write configuration
    # config_out = open(DEFAULT_CONFIG_FILE, "w")
    # cpu_tester.save_configuration(config_out)
    # config_out.close()

    # # remove lockstep_file
    # #rm(DEFAULT_LOCKSTEP_FILE)

    return 0
