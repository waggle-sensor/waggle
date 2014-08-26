from multiprocessing.managers import SyncManager
from multiprocessing import Lock
import sys, time

class MyManager(SyncManager):
    pass

MyManager.register("syncdict")
MyManager.register("synclock")

if __name__ == "__main__":
    manager = MyManager(("127.0.0.1", 5000), authkey="password")
    manager.connect()
    syncdict = manager.syncdict()
    synclock = manager.synclock()

    time.sleep(5)
    print "Start"
    key = "counter"
    inc = 1

    #if the key doesn't exist create it
    synclock.acquire()
    if not syncdict.has_key(key):
        syncdict.update([(key, 0)])
    synclock.release()

    i = 0
    while i < 100000:
        synclock.acquire()
        syncdict.update([(key, syncdict.get(key) + inc)])
        synclock.release()
        #print "%s" % (syncdict)
        i = i + 1
        

    print "%s" % (syncdict)
