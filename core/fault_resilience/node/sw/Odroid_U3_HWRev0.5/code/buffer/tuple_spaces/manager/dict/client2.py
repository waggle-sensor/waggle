from multiprocessing.managers import BaseManager
from time import sleep

class DictManager(BaseManager): 
    pass

DictManager.register('get_dict')
m = DictManager(address=('localhost', 50000), authkey='abracadabra')
m.connect()
dictionary = m.get_dict()

while True:
    msg = dictionary.len()
    print msg
    sleep(1)

