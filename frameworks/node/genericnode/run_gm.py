import time
from gn_global_definition_section import logger
from gn_main_class import main_class

#truncating gn.cfg file
#cfg_truncate = open('gn.cfg','w')
#time.sleep(1)
#cfg_truncate.close()
from commands import getoutput
print getoutput('rm gn.cfg')



# Everything starts here
if __name__ == "__main__":
    logger.critical("Starts:"+str('%0.4f' % time.time())+"\n\n")
    # port at which GN can contact NC
    nc_port = 7001
    # main_thread starts everything else
    main_thread = main_class("main_thread", nc_port)
    main_thread.run()
