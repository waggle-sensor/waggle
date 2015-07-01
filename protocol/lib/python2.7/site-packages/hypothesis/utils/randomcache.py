from __future__ import division, print_function, absolute_import, \
    unicode_literals

from random import Random


class RandomCache(object):

    def __init__(self):
        self.data = {}

    def __call__(self, seed):
        try:
            state = self.data[seed]
        except KeyError:
            random = Random(seed)
            state = random.getstate()
            self.data[seed] = state
        result = Random()
        result.setstate(state)
        return result
