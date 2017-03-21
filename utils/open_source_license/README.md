
![waggle banner](http://www.mcs.anl.gov/research/projects/waggle/docs/Img/banner.png)

This directory holds tools and instructions for managing the BSD-style
open source license for Waggle.

## Instructions and Procedures:

1. **Every repo should have a LICENSE file** The root directory for
every waggle-based software repository should have the file
"LICENSE.waggle.txt".  That file should be copied directly from this
directory, and if changes are made to the version here, the file
should be pushed out to all the repos.

2. **Source code authored by a Waggle contributor must include a
license reference** This is the Linux-based brain for a sensor node.
Currently, we are using a hardkernel.com ODROID C1+ single-board
computer to be the Node Controller.  In addition to a mostly stock
Linux, the Node Controller has waggle's communication libraries, extra
resilience features, and support for in-situ
processing. [Node-controller Code
Repository](https://github.com/waggle-sensor/sensors)


2. **The WagMan system management board** for managing a sensor node.
This is the failsafe for the node.  It can power-cycle components,
detect when the waggle node is too hot, etc.
[Wagman Code Repository](https://github.com/waggle-sensor/wagman)

3. **The Waggle Sensor Boards** (sensors)
[Sensor Code Repository](https://github.com/waggle-sensor/sensors)

4. **The Cloud-based software** (Beehive)
[Beehive Code Repository](https://github.com/waggle-sensor/beehive-server)

5. **The In-situ Computing payload** (Edge Processor)
[Edge Processor Code Repository](https://github.com/waggle-sensor/edge_processor)

