from multiprocessing.managers import SyncManager
from multiprocessing import Lock

class MyManager(SyncManager):
    pass


syncdict = {}
def get_dict():
    return syncdict

synclock = Lock()
def get_lock():
    return synclock

if __name__ == "__main__":
    MyManager.register("syncdict", get_dict)
    MyManager.register("synclock", get_lock)
    manager = MyManager(("127.0.0.1", 5000), authkey="password")
#    lock = manager.Lock()
#    manager.register("synclock", callable=lambda:lock)

    server = manager.get_server()
    server.serve_forever()
