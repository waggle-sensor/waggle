# Designing a Waggle Plugin

The purpose of this document is to guide the user through the design of a node
and server side plugin pair to be used with the Waggle platform.

## Overview

A Waggle plugin consists of two pieces: a node side and a server side plugin
pair which are linked through a common plugin name and version. The node side
plugin is responsible for reading data from a device and sending it to the
Beehive server. The server side plugin is responsible for post processing and
decoding of data received from the node. We provide a brief example here to
illustrate this.

### Example: Coresense

The Coresense is a PCB containing a collection of many different sensors. It
periodically sends a binary packet over a USB serial port containing readings
from each of the onboard sensors. The node side plugin reads this packet from
the serial port, checks it for validity and then sends it as-is to the server.
The server side plugin takes this packet, decodes the various readings from it
and forwards it further down the server side data pipeline.

## Development

To simplify development of a plugin, we've provided the
[pywaggle](https://github.com/waggle-sensor/pywaggle) Python module. Throughout
this guide, we'll be assuming that you're using this.

### Node Plugin

The node side plugin is responsible getting data from the sensor and forwarding
it to the cloud. We'll dive in and provide a full example to start with.

```python
import waggle.pipeline
import time

# This is where we define our plugin. Notice that it requires a name,
# version and run method.
class MyPlugin(waggle.pipeline.Plugin):

    plugin_name = 'myplugin'
    plugin_version = '1.0'

    def run(self):
        while True:
            self.send(sensor='mysensor', data='17.38')
            time.sleep(10)


# This is used to instantiate a plugin in the plugin manager.
def register(name, man, mailbox_outgoing):
    MyPlugin(name, man, mailbox_outgoing).run()


# This snippit allows us to run a plugin in standalone mode for testing.
if __name__ == '__main__':
    def callback(data):
        print(data)

    waggle.pipeline.run_standalone(MyPlugin, callback)
```


## Additional Remarks

Please note that a typical Waggle node may have limited network bandwidth. For
example, the Array of Things nodes are all transmitting over a wireless modem,
which is somewhat limited in both speed and available data usage. These are
important considerations when deciding on the both the rate and volume of data
intended to be transmitted. Our suggestion is to restrict the rate to at most
one message to be sent every 10 seconds and that the message size is at most 1K.

Also note that the design of a plugin should have fault tolerance in mind. Under
circumstances where the network or server has malfunctioned, the node *will*
continue to queue and timestamp data being produced by plugins. We recommend
that you design your plugins with this in mind.
