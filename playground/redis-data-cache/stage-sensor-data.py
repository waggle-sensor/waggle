"""
Fetches a window of messages from Redis cache and stages a compressed version
ready to be sent to the cloud.

For sensor data I was collecting at home, I was able to compress batches of
1000 down to 0.05 times their raw size using lzma/xz compression as done here.

Sean
"""
from redis import Redis
import lzma


redis = Redis()
window_size = 1000

if redis.llen('sensor-data') > window_size:
    data = b'\n'.join(redis.lrange('sensor-data', -window_size, -1))
    comp = lzma.compress(data)

    redis.lpush('sensor-data-compressed', comp)
    redis.ltrim('sensor-data', 0, -window_size - 1)

    print('data size', len(data))
    print('compress size', len(comp))
    print('compress ratio', len(comp) / len(data))
