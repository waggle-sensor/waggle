<!--
waggle_topic=/waggle/introduction,"Waggle System"
-->


![waggle banner](http://www.mcs.anl.gov/research/projects/waggle/docs/Img/banner.png)

This github repository holds the source code of the Waggle project. The Waggle project webpage can be found here: www.wa8.gl

## A very high level view of the pieces of this project are:

1. **Node Controller.**  This is the Linux-based brain for a sensor 
node.  Currently, we are using a hardkernel.com ODROID C1+ single-board
computer to be the Node Controller.  In addition to a mostly stock
Linux, the Node Controller has waggle's communication libraries, extra
resilience features, and support for in-situ processing. [Node-controller Code Repository](https://github.com/waggle-sensor/sensors)


2. **The WagMan system management board** for managing a sensor node.
This is the failsafe for the node.  It can power-cycle components,
detect when the waggle node is too hot, etc.
[Wagman Code Repository](https://github.com/waggle-sensor/wagman)

3. **The Waggle Sensor Boards** (sensors)
[Sensor Code Repository](https://github.com/waggle-sensor/sensors)

4. **The Cloud-based software** (Beehive)
[Beehive Code Repository](https://github.com/waggle-sensor/beehive-server)

5. **The In-situ Computing** (Edge Processor)
[Edge Processor Code Repository](https://github.com/waggle-sensor/edge_processor)

