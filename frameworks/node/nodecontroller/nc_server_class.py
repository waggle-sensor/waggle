from nc_internal_communicator_class import internal_communicator
from global_imports import threading, time, random
import asyncore
import asynchat
import socket
from nc_global_definition_section import gn_socket_list, logger, gn_socket_list_lock


"""
# Listens for incoming registration requests of guest nodes and once a request
# is received, it creates a new object of class internal_communicator and passes
# the new socket's details to that.
"""
class nc_server_class(threading.Thread, asyncore.dispatcher):

    ##############################################################################
    def __init__(self, thread_name, socket_type, port_for_gn):
        asyncore.dispatcher.__init__(self)
        threading.Thread.__init__(self)
        # can be used by logging module for printing messages related to this thread
        self.thread_name = "Thread_" + thread_name
        self.daemon = True
        self.port_for_gn = port_for_gn
        self.buffer_mngr= ''
        self.create_socket(socket_type, socket.SOCK_STREAM)
        logger.debug(self.thread_name+" Initialized."+"\n\n")


    ##############################################################################
    # Listens for GN's requests and creates new internal_communicator object for each GN
    def run(self):
        try:
            self.bind(("0.0.0.0", self.port_for_gn))
            # Backlog argument: 5 specifies the maximum number of queued connections\
            # and should be at least 1; the maximum value is system-dependent (usually 5)
            self.listen(5)
            logger.info("Listening on port_for_gn: " + str(self.port_for_gn)+"\n\n")
            # starts the loop which constantly checks whether the socket is readable or writable
            while True:
                # Starts the loop which polls all the open sockets one by one,
                # comes out of the asyncore loop after polling for *count*
                # times and then repeats after 0.011s.
                # Performance widely varies based on sleep time and count's value
                # When count=0/None control will never come out of the asyncore loop
                # internal timeout of 0.01s between 2 polls
                asyncore.loop(timeout=0.01, use_poll=True, map=None) # , count=n) can be added. n>=1
                time.sleep(0.011)
        except Exception as inst:
            logger.critical("ERROR: Exception in nc_server run(): " + str(inst)+"\n\n")
            time.sleep(1)
            self.run()


    ##############################################################################
    # Called by msg_processor thread to pass the address of buffer_mngr to this thread
    def pass_thread_address(self, buffer_mngr):
        self.buffer_mngr = buffer_mngr
        logger.debug("buffer address of gn_buffer_mngr saved."+"\n\n")


    ##############################################################################
    # Called when a GN tries to contact the NC server for the first time
    def handle_accept(self):
        try:
            logger.info("New GN connection available." + "\n\n")
            # returns the newly allocated socket and ip address
            gn_socket_conn, gn_addr = self.accept()
            socket = internal_communicator(gn_socket_conn, gn_addr, self.buffer_mngr)
            # Lock acquired to access global list variable and released when the 'with' block ends
            with gn_socket_list_lock:
                # Pass GN's details and new socket's details to a new socket object created for that GN
                gn_socket_list.append(socket)
            #logger.debug("Socket object corresponding to new GN created and running.")
        except:
            logger.critical("Error: Exception in handling the GN connection request."+ "\n\n")
            pass


    ##############################################################################
    # Closes all individual GN sockets and then itself
    def handle_close(self):
        # close all individual gn sockets
        self.close_gn_socket()
        self.close()
        logger.critical("Server Socket closed."+"\n\n")


    ##############################################################################
    # Closes all alive sockets present in the gn_socket_list
    def close_gn_socket(self):
        # Lock acquired to access global list variable and released when the 'with' block ends
        with gn_socket_list_lock:
            for socket in gn_socket_list:
                #socket.shutdown = 1
                gn_socket_list.remove(socket)
                socket.close()
                logger.info("Individual GN socket closed.")
        logger.critical("NC's individual GN sockets closed."+"\n\n")


    ##############################################################################
    # Called when an error occurs
    def handle_error(self):
        logger.critical("Server ERROR."+"\n\n")
        self.run()


    ##############################################################################
    def __del__(self):
        print self, 'Server object died\n\n'
