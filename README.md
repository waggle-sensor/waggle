
![waggle bannder](./wagview/node_pages/banner.png)

This github repository holds the source code of the Waggle project. The Waggle project webpage can be found here: www.wa8.gl

## A very high level view of the pieces of this project are:

1. **A Node Controller.**  This is the Linux-based brain for a sensor
node.  Currently, we are using a hardkernel.com ODROID single-board
computer to be the Node Controller.  In addition to a mostly stock
Linux, the Node Controller has waggle's communication libraries, extra
resilience features, and support for in-situ processing

2. **The WagMan system management board** for managing a sensor node.
This is the failsafe for the node.  It can power-cycle components,
detect when the waggle node is too hot, etc.

3. **The Waggle Sensor Board** (EnvSense)

4. **The Cloud-based software** (Beehive)

## Directories

The directories are organized as follows (in alphabetical order)

**beehive**: the software run on the cloud server
- docs: documentation of the cloud server
- msging: the cloud-side of the message layer
- wag-view: A nice front end for browsing the data
- wag-db: the backend storage scripts 

**build**: all of the pieces are built (compiled, configured) and installed into this directory

**comlink**: the communication link (wifi router, etc)

**devtools**: tools needed to build and install waggle

**docs**: waggle-wide documentation.  This directory is the result of building all the docs found in the subdirectories

**guestnode**: All the software that lives on the guestnodes (ODROID)
- docs: documentation of guestnodes
- nc-baseos: The core Linux OS distro from which we start
- nc-wag-os: The guestnode software stack, including the basic OS
  - waggled: The command controller and client console
  - resilience: tools and scripts, such as heartbeat for deep-space operation
  - personalization: scripts and config files for personalizing a node
  - externs: external packages added to make the basic Waggle OS better
- in-situ: audio and image computing done inside the guestnode

**nodecontroller**: All the software that lives on the Node Controller (ODROID)
- docs: documentation of node controller
- nc-baseos: The core Linux OS distro from which we start
- nc-wag-os: The Node Controller software stack, including the basic OS
  - waggled: The command controller and client console
  - msging: The remote messaging service to the cloud
  - resilience: tools and scripts, such as heartbeat for deep-space operation
  - personalization: scripts and config files for personalizing a node
  - externs: external packages added to make the basic Waggle OS better

**sensors**: all of the code to interact with and read data from sensors
- envsense: the core environmental sensing board
  - docs: documentation of the envsense software / hardware environment, and sensors
  - reader: code (firmware) running on the envsense board
- anemometer: an experiemental anemometer
  - docs: documentation of the system
  - reader: code to read and generate a value

**testing**: the waggle testing framework

**wagman**: waggle system management board software
- docs: documentation of the waggle management software / hardware environment
- manager: code (firmware) loaded onto system management board

**other**: a temporary holding place for things that have not yet found
a home in the structure above.
