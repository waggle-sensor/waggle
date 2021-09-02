Waggle Server Installation and Configuration
============================================

When running a waggle server, it is assumed that you are running
a version of ubuntu on your machine, and that it is set up to clone
via ssh from git.

For assistance setting up git in this way on your machine, follow
these instructions:
`Git SSH Setup
<https://help.github.com/articles/generating-ssh-keys/>`_

If you are SSHing into a remote machine to set up a server,
you should set up SSH forwarding according to these instructions: 
`SSH Forwarding
<https://developer.github.com/guides/using-ssh-agent-forwarding/>`_

To set up a machine to run as a waggle server, do the following:

#. Clone the git repo from `git@github.com:waggle-sensor/waggle.git`

#. In the cloned repo, go to the waggle/beehive directory

#. Run the ``configure.sh`` script in the beehive directory

#. Once this setup is complete, move to the beehive/server directory

#. To start the server, run the command ``python Server.py``.


Quick install
=============

To do a quick install, move to the directory where you want the files
and simply run these commands. (Assumes git ssh is set up.)

:: 

   git clone git@github.com:waggle-sensor/waggle.git
   cd waggle/beehive
   ./configure
   cd server


Once this has been run, you can just type ``python Server.py`` and the server will start.