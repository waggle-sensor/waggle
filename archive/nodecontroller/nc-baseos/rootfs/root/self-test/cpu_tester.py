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
Default values for CPU stress application stress tests
"""

DEFAULT_CPU_STRESS_APP = SELF_TEST_APP_DIR + "/stress-ng/stress-ng"
DEFAULT_CPU_STRESS_APP_ARGS = "-c {0} -l {1} -t {2} -q"
DEFAULT_CPU_MAX = "4"
DEFAULT_CPU_MIN = "1"
DEFAULT_CPU_STEP = "1"
DEFAULT_UTIL_MAX = "100"
DEFAULT_UTIL_MIN = "25"
DEFAULT_UTIL_STEP = "25"
DEFAULT_TIMEOUT = "30"
DEFAULT_AVAILABLE_CPUS = "0,1,2,3"


DEFAULT_LOCKSTEP_GREPID = "CPU_LOCKSTEP"
DEFAULT_CONFIG_GREPID = "CPU_CONFIG"

class CPUTester(base_tester.BaseTester):
    """
    Application to stress the CPUs of the system. Runs start from a minimum
    configuration and increases to the maximum number of CPUs and utilization
    as specified from the default value, provided configuration, or a lockstep
    file from a previous (crashed) stress test.
    """

    def __init__(self):
        """
        Constructor that initializes all attributes to default values, and opens
        the logger and the lockstep handlers
        """

        logging.basicConfig(filename=DEFAULT_LOG_FILE, level=logging.DEBUG)
        self.logger = logging.getLogger("cpu_tester")
        
        self.name = "CPU stress application"

        self.attr = { "stress_app": DEFAULT_CPU_STRESS_APP,
                      "stress_app_args": DEFAULT_CPU_STRESS_APP_ARGS,
                      "cpu_max": DEFAULT_CPU_MAX,
                      "cpu_min": DEFAULT_CPU_MIN,
                      "cpu_step": DEFAULT_CPU_STEP,
                      "util_max": DEFAULT_UTIL_MAX,
                      "util_min": DEFAULT_UTIL_MIN,
                      "util_step": DEFAULT_UTIL_STEP,
                      "timeout": DEFAULT_TIMEOUT,
                      "available_cpus": DEFAULT_AVAILABLE_CPUS}

        self.lockstep_out = stdout
        self.logger.info("CPU stress object generated successfuly")

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
        
    def stress_individual_cpus(self):
        print("TOBE")


    def stress(self):
        """
        Performs the stress routines on the CPU
        """

        cpus = int(self.attr["cpu_min"])
        cpu_max = int(self.attr["cpu_max"])
        util_min = int(self.attr["util_min"])
        util_max = int(self.attr["util_max"])
        util_step = int(self.attr["util_step"])
        cpu_step = int(self.attr["cpu_step"])

        self.stress_individual_cpus()

        # Iterate from 'cpu_min' to 'cpu_max' with step 'cpu_step'
        while cpus <= cpu_max:
            util = util_min
            # Iterate from 'util_min' to 'util_max' with step 'util_step'
            while util <= util_max:

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

                util += util_step
            cpus += cpu_step
          
        return True

if __name__ == "__main__":
    ###
    ### Independent test of the module
    ###
    from shutil import move
    
    parse_previous_lockstep = False
    imprecise_shutdown = True
    if isfile(DEFAULT_LOCKSTEP_FILE) and imprecise_shutdown:
        print("There was an improper shutdown and I found a lockstep file")
        move(DEFAULT_LOCKSTEP_FILE, DEFAULT_LOCKSTEP_FILE_BACKUP)
        parse_previous_lockstep = True
    else:
        print("No Improper shutdown or lockstep file")

    # Generate stress object
    cpu_tester = CPUTester()
    
    if isfile(DEFAULT_CONFIG_FILE):
        print("Found default configuration file")
        cpu_tester.load_configuration()
    else:
        print("No default configuration file")

    if parse_previous_lockstep:
        print("Parsing previous lockstep file")
        cpu_tester.parse_lockstep_file(DEFAULT_LOCKSTEP_FILE_BACKUP)



    lockstep_out = open(DEFAULT_LOCKSTEP_FILE, "w")
    cpu_tester.set_lockstep_out(lockstep_out)
    print("Stress CPU")
    cpu_tester.stress()
    lockstep_out.close()

    # write configuration
    config_out = open(DEFAULT_CONFIG_FILE, "w")
    cpu_tester.save_configuration(config_out)
    config_out.close()

    # remove lockstep_file
    #rm(DEFAULT_LOCKSTEP_FILE)
