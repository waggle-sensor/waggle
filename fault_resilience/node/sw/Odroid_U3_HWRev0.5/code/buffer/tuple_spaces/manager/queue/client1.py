from multiprocessing.managers import BaseManager
class QueueManager(BaseManager): 
    pass

QueueManager.register('get_queue')
m = QueueManager(address=('localhost', 50000), authkey='abracadabra')
m.connect()
queue = m.get_queue()
i = 0
while True:
    queue.put('hello: ' + str(i))
    i = i + 1
