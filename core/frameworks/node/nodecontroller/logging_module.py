import logging

## used for logging msgs
#logging.basicConfig(filename = './NC_output.log', level=logging.INFO,format='%(asctime)s %(name)s: %(message)s',)
logging.basicConfig(level=logging.NOTSET,format='%(asctime)s %(name)s: %(message)s',)


# handler for logging msgs                    
logging_level = 2


def set_logging_level(context_name):
    logger = logging.getLogger(None)        
    if logging_level == 0:
        logger.setLevel(0)                                               # all msgs will be displayed
    elif logging_level == 1:
        logger.setLevel(10)                                              # msgs at debug level or higher than that will be displayed
    elif logging_level == 2:
        logger.setLevel(20)                                              # msgs at info level or higher than that will be displayed
    elif logging_level == 3:
        logger.setLevel(30)                                              # msgs at warning level or higher than that will be displayed                               
    elif logging_level == 4:
        logger.setLevel(40)                                              # msgs at error level or higher than that will be displayed
    elif logging_level == 5:
        logger.setLevel(50)                                              # noly critical msgs will be displayed
    logger.debug("Logging level set."+"\n\n")    
    return logger

