from multiprocessing.managers import BaseManager
class QueueManager(BaseManager): 
    pass

QueueManager.register('get_queue')
m = QueueManager(address=('localhost', 50000), authkey='abracadabra')
m.connect()
queue = m.get_queue()
while True:
    msg = queue.get()
    print msg

