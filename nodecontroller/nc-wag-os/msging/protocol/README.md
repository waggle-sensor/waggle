### Waggle Protocol 0.3

### Overview

This project implements the Waggle protocol, version 0.3.

Here's an overview of what the source tree looks like:

```
src/
    Packet.py - A module containing a class that represents packet data
    [other files] 
test/
    strategies.py        # strategies to generate message examples for Hypothesis
    serialize_test.py
    message_test.py
```

### Installation and Development

Remember to run `source bin/activate` to activate virtualenv.

Install dependencies by running `pip install -r requirements.txt`.

### Testing

Tests are written using a property-based testing framework called Hypothesis. Each Hypothesis test describes a property that should hold true for all examples in a group of objects.

Hypothesis generates 100 examples to test each property.

Tests can be run by typing `nosetests` at the command line.

### TODO

* Actually check the CRCs when parsing a message (src.message.Message#parse).
* Write unit tests for src.handle_message 
	i.e. give it example messages and check that the responses are correct. 
	Don't go through pika/RabbitMQ for the unit tests.
* Update the session id - write it to a file when the server first starts (session number needs to be persisted).

### Questions
* What should the initial sequence and session number be when a communication is initiated for the first time?
* 


