#!/usr/bin/python3

###
### 
###

## Imports
import logging
from time import strftime
from optparse import OptionParser
from shutil import move, rmtree
from os.path import isfile
from os import remove

from cpu_tester import CPUTester
from base_tester import DEFAULT_LOG_FILE, DEFAULT_LOCKSTEP_FILE, DEFAULT_CONFIG_FILE, DEFAULT_LOCKSTEP_FILE_BACKUP

if __name__ == "__main__":
    ### Command line arguments
    parser = OptionParser()
    parser.add_option("--validate",
                      action="store_true",
                      dest="validate",
                      default=True,
                      help="Check if a previous stress attempt resulted in a system crash and limit application attributes accordingly")
    parser.add_option("--dry-run",
                      action="store_true",
                      dest="dry_run",
                      default=False,
                      help="Only update the system configuration file (default values or a configuration file can be used and finally if a lockstep file is present it is parsed)")
    parser.add_option("--stress-cpu",
                       action="store_true",
                       dest="enable_cpu_stress",
                       default=False,
                       help="Enable CPU stress suite")
    parser.add_option("--config",
                       action="store",
                       dest="config_file",
                       default=DEFAULT_CONFIG_FILE,
                       help="Configuration file")
    parser.add_option("--use-defaults",
                       action="store_true",
                       dest="use_defaults",
                       default=False,
                       help="Do not limit the stress suites based on previous configuration")
    parser.add_option("--lockstep",
                       action="store",
                       dest="lockstep_file",
                       default=DEFAULT_LOCKSTEP_FILE,
                       help="Lockstep file")

    (options, args) = parser.parse_args()

    # Log start of main stress application
    logging.basicConfig(filename=DEFAULT_LOG_FILE,level=logging.DEBUG)
    logger = logging.getLogger("self_test")
    logger.info('Stress test started at: {}'.format(strftime("%X %x %Z")))


    ### Main logic

    #### Populate list of tester apps
    stress_list = []
   
    if options.enable_cpu_stress:
        stress_list.append(CPUTester())

    #### Load stress applications attributes from a configuration file
    if not options.use_defaults:
        if isfile(options.config_file):
            logger.info("Using configuration file: {}".format(options.config_file))
            for app in stress_list:
                app.load_configuration(options.config_file)
            else:
                logger.info("Provided configuration file does not exist: {}".format(options.config_file))
    else:
        logger.info("Using default options for stress applications")
        
    #### Check if a previous stress test crashed and change the attributes of
    #### the stress applications accordingly
    if options.validate:
        if isfile(options.lockstep_file):
            logger.info("There was an improper shutdown and a lockstep file was found")
            for app in stress_list:
                app.parse_lockstep_file(options.lockstep_file)
            # Backup the lockstep file so it is not overwritten by the one of the current
            # stress test
            move(options.lockstep_file, DEFAULT_LOCKSTEP_FILE_BACKUP)


    #### Start stress test
    if not options.dry_run:
        lockstep_out = open(options.lockstep_file, "w")

        for app in stress_list:
            logger.info("Running: {}".format(app.name))
            app.set_lockstep_out(lockstep_out)
            app.stress()
            
        # close and remove lockstep_file
        lockstep_out.close()
        remove(options.lockstep_file)

    #### Write configuration
    config_out = open(options.config_file, "w")

    for app in stress_list:
        app.save_configuration(config_out)

    config_out.close()
