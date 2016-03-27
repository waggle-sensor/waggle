I'd heard some good things about Redis and used it a little bit before. I thought
it'd be interesting to write a short example of something possibly relevant to our
own work.

In about an hour or so, along with zeromq for messaging, I was able to get this
staged data cache running. It serves a few purposes:

1. It acts as a persistant data cache. You can queue items up and it automatically
writes to disk after a certain number of writes are done or every so often. This can
be configured if the defaults aren't good enough.

2. The script stage-sensor-data.py basically checks in on how much data is in the
cache. When it's surpassed a certain window, it compresses the window and adds
pushes it back into Redis in a separated staging queue. Using LMZA/XZ, this was
dropping the data size down to about 0.05 times the original data size for the
kind of sensor data I was collecting. Not bad! :) Additionally, even if you
aggressively do this compression, you won't need to do it more than every 5-10
minutes or so. On my machine, this step takes about 0.15 seconds, so it's
basically irrelevent relative to other things.

3. Although the previous step dramatically reduces memory usage, hypothetically,
you can now dequeue the compressed items and push them to the cloud. Reduced bandwidth! :)
