class bytequeue(object):

    def __init__(self, capacity):
        self.buffer = bytearray(capacity)
        self.front = 0
        self.length = 0

    def __len__(self):
        return self.length

    def __getitem__(self, key):
        if isinstance(key, int):
            if key >= 0:
                return self.buffer[(self.front + key) % len(self.buffer)]
            else:
                return self[key + self.length]
        elif isinstance(key, slice):
            if key.step is None:
                indices = range(key.start, key.stop)
            else:
                indices = range(key.start, key.stop, key.step)
            return bytearray(self.buffer[(self.front + i) % len(self.buffer)]
                             for i in indices)
        else:
            raise TypeError('key not int or slice')

    def enqueue(self, x):
        if self.length == len(self.buffer):
            raise IndexError('enqueue to full bytequeue')

        self.buffer[(self.front + self.length) % len(self.buffer)] = x
        self.length += 1

    def dequeue(self):
        if self.length == 0:
            raise IndexError('dequeue from empty bytequeue')

        x = self.buffer[self.front]
        self.front = (self.front + 1) % len(self.buffer)
        self.length -= 1
        return x
