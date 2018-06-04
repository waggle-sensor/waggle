<!--
waggle_topic=/waggle
-->

# Getting Started

You can explore the following sub categories to be familarized yourself with Waggle and potentially contribute to the future Waggle environment.

## Setup

* [Installation](./user_documentation/getting-started-waggle-node.md)

    Check part lists of a Waggle and see how they are connected.

* [Assembly](./user_documentation/assemble.md) </br>
    Assemble hardware parts to get ready to run a Waggle node.

* [Install firmware](./user_documentation/install-firmwares.md) </br>
    Download and install firmware to the Waggle node.

## Wagman

* [Introduction](./wagman/v3/README.md) </br>
    Wagman that manage power systems and sustainability.

* [Bootloader](./wagman/v3/bootloader/README.md) </br>
    Burn the Arduino Micro Caterina bootloader on the Wagman.

* [Management](./wagman/v3/manager/README.md) </br>
    Show how Wagman actually manages Waggle node.

## Nodecontroller

* [Setup](./user_documentation/getting_started.md) </br>
    Instructions on how to setup nodecontroller and send data to beehive server.

* [Waggle service](./user_documentation/waggle_services.md) </br>
    Services that provide various functionality for nodecontroller.

* [Waggle scripts](./nodecontroller/nc-wag-os/waggled/README.md) </br>
    Details of executable scripts.

* [Communication](./nodecontroller/docs/README.md) </br>
    Communication to beehive server and its [protocol](./guestnodes/waggle_protocol/README.md).

## Payload

* [App processor](./guestnodes/README.md) </br>
    App processor that interacts with connected sensors.

* [Core sensors](./coresensors/v3/pbay/integrated/README.md) </br>
    Instructions of the air/light/chem sensors. Sensor specifications can be found [here](./user_documentation/sensors/SensorTable.html)

* [Sensor communication](./coresensors/docs/sensorStreamFormat/README.md) </br>
    Definitions of communication between app processor and core sensors.

* [Plugins](./guestnodes/plugins/README.md) </br>
    Extend plugins as additional sensors attached to Waggle node.

## Beehive server

* [Introduction](./beehive-server/README.md) </br>
    Structures and configuration of the server.

* [Data storage](./beehive-server/beehive-cassandra/README.md) </br>
    A place where all the data collected from Waggle nodes stored.

* [Messaging](./beehive-server/beehive-rabbitmq/README.md) </br>
    Messaging protocol between Beehive server and Waggle nodes.

## Developers

* [How to create a waggle image](./nodecontroller/docs/create_waggle_image.md) </br>
    Instructions on how to create a Waggle image.

* [Nodecontroller configuration](./nodecontroller/README.md) </br>
    Step by step configuration of nodecontroller.

* [Tools](./devtools/README.md)
    Tools needed to build and extend Waggle system.
