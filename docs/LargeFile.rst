Large File Transfer Protocol
============================

**NOTE:** This page is a work in progress. Large file transfers are not yet implemented, but
are planned for the very near future!

The transfer of large messages (defined as 1KB or larger in Waggle 0.3) requires a few extra steps
to ensure that the file is received correctly by the intended recipient.

First, you should understand that when Waggle is transferring a large message, the receiver must be
notified of intent to transmit and they must accept the transmission. This is to ensure that the
recipient is not either out of memory or already handling the maximum number of simultaneous large 
message tranmissions (which is 256 in Waggle 0.3).

The essential steps to transfer a file are as follows:

#. The sender sends a message to the reciever with one of the large file major message types containing

      - The name of the file
      - The size of the file

#. The reciever looks at the message, and checks the following:

      - Does the sender have permission to write a file to that location?
      - Do I have enough space to accept the file?
      - Am I already accepting 256 transmissions?

#. The node sends back an acknowledgement message containing a single byte representing the transfer
   number for the file. 

#. The sender then packetizes the large message and begins sending them to the receiver, setting the
   message minor type to the transfer number so that it is correctly assembled at the other side. 

#. The reciever reassembles the packets on the other end to create the original message or file, which
   is then processed accordingly.

