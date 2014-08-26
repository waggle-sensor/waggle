from multiprocessing.managers import BaseManager
#from multiprocessing import Lock
import Queue

queue = Queue.Queue()
class QueueManager(BaseManager):
    pass

QueueManager.register('get_queue', callable=lambda:queue)
m = QueueManager(address=('', 50000), authkey='abracadabra')
s = m.get_server()
s.serve_forever()
