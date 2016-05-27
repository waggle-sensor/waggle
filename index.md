![waggle banner](./wagview/node_pages/banner.png)

Waggle is a research project at Argonne National Laboratory to design, develop, and deploy a novel wireless sensor platform to enable a new breed of sensor-driven environmental science and smart city research.

You can explore the following sub categories to be familarized yourself with Waggle and potentially contribute to the future Waggle environment.

## Getting started
* [Installation](./user_documentation/getting-started-waggle-node.md) </br>
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

* [Waggle scripts](https://github.com/waggle-sensor/nodecontroller/blob/master/nc-wag-os/waggled/README.md) </br>
    Details of executable scripts.

* [Communication](https://github.com/waggle-sensor/nodecontroller/blob/master/docs/README.md) </br>
    Communication to beehive server and its [protocol](https://github.com/waggle-sensor/waggle_protocol/blob/master/README.md).

## Payload
* [App processor](https://github.com/waggle-sensor/plugin_manager/blob/master/README.md) </br>
    App processor that interacts with connected sensors.

* [Sensor communication](./coresensors/docs/sensorStreamFormat/README.md) </br>
    Definitions of communication between app processor and core sensors.

* [Plugins](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/README.md) </br>
    Extend plugins as additional sensors attached to Waggle node.

## Beehive server
* [Introduction](https://github.com/waggle-sensor/beehive-server/blob/master/README.md) </br>
    Structures and configuration of the server.

* [Data storage](https://github.com/waggle-sensor/beehive-server/blob/master/beehive-cassandra/README.md) </br>
    A place where all the data collected from Waggle nodes stored.

* [Messaging](https://github.com/waggle-sensor/beehive-server/blob/master/beehive-rabbitmq/README.md) </br>
    Messaging protocol between Beehive server and Waggle nodes.

## Developers
* [How to create a waggle image](https://github.com/waggle-sensor/nodecontroller/blob/master/docs/create_waggle_image.md) </br>
    Instructions on how to create a Waggle image.

* [Nodecontroller configuration](https://github.com/waggle-sensor/nodecontroller/blob/master/README.md) </br>
    Step by step configuration of nodecontroller.

* [Tools](./devtools/README.md)
    Tools needed to build and extend Waggle system.
