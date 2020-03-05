<!--
waggle_topic=/waggle/introduction,"Waggle System"
-->

# Waggle System

The Waggle Platform is a research project at Argonne National Laboratory to design, develop, and deploy a novel wireless sensor platform with advanced edge computing capabilities to enable a new breed of sensor-driven environmental science and smart city research.

The project is led by Pete Beckman. Senior contributors include Rajesh Sankaran, Nicola Ferrier, Charlie Catlett. The software and hardware designs from the Waggle project are used by the ArrayOfThings project, which is building a smart city and open data with urban sensors in Chicago.  We are also working to deploy Waggle at the Chicago Botanic Garden, and the Nature Conservancy’s Indian Boundary Prairies.

The Waggle project started in the summer of 2013, leveraging several Argonne wireless sensor projects going as far back as 2004, when Pete Beckman and Rick Stevens taught a wireless sensor class at the University of Chicago.  Pete then started a research lab for sensor networks and explored environmental sensing of data centers. Waggle is funded via internal Argonne research funds (LDRD).

The innovative architecture leverages emerging technology in low-power processors, sensors, and cloud computing to build powerful and reliable sensor nodes that can actively analyze and respond to data. Cloud computing provides elastic resources for storing and computing on data.

Waggle is designed from the ground up with security, privacy, extensability, and survivability as key design points. The Waggle reference platforms and software are launching points. All of the software is Open Source, and the software is modular, so researchers can add their own sensors, computing pipelines, and data analysis.

The name for the project comes from nature’s wireless sensors — honeybees. Bees search far and wide for pollen, and report their findings back to the hive using a sophisticated dance called a “waggle dance“. The dance encodes the distance and angle to the food source, and is often similar to a figure-8 — which is why we picked wa8.gl as our domain name. 

## A very high level view of the pieces of this project are:

1. **Node Controller.**  This is the Linux-based brain for a sensor 
node.  Currently, we are using a hardkernel.com ODROID C1+ single-board
computer to be the Node Controller.  In addition to a mostly stock
Linux, the Node Controller has waggle's communication libraries, extra
resilience features, and support for in-situ processing. [Node-controller Code Repository](https://github.com/waggle-sensor/nodecontroller)


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
