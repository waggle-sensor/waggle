from nc_global_definition_section import port_for_gn, logger, time
from nc_msg_processor_class import msg_processor_class

logger.critical("NC Starts:"+str('%0.4f' % int(time.time()))+"\n")

# msg_processor object is initialized which starts everything else
msg_processor = msg_processor_class("msg_processor_class", port_for_gn)
msg_processor.run()

