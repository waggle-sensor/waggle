# -*- coding: utf-8 -*-
import threading
import Queue
import pyinotify
from pyinotify import WatchManager, Notifier, ProcessEvent, EventsCodes
from coresense_pluginUSBSerial  import *

wm = WatchManager()
mask = pyinotify.IN_DELETE | pyinotify.IN_CREATE  # watched events

newDevice = Queue.Queue (10)
deviceDisconnect = Queue.Queue (10)

class communicatorLoader (threading.Thread):
    def __init__ ( self):
        threading.Thread.__init__ ( self )
        global newDevice
        global deviceDisconnect
        self.threadListUsbSerial = {}
        self.keepAlive = True
        self.sleepTime = 1
        self.start()
    def run (self):
        while (self.keepAlive):
            time.sleep(self.sleepTime)
            if newDevice.empty() <> 1 and self.keepAlive:
                portInfo = newDevice.get()
                self.threadListUsbSerial[portInfo]=usbSerial(portInfo)
                self.threadListUsbSerial[portInfo].start()
            if deviceDisconnect.empty() <> 1 and self.keepAlive:
                portInfo = deviceDisconnect.get()
                try:
                    self.threadListUsbSerial[portInfo].stop()
                except:
                    pass
                try :
                    del self.threadListUsbSerial[portInfo]
                except:
                    pass

    def stop (self):
        for i in self.threadListUsbSerial:
            try:
                self.threadListUsbSerial[i].stop()
            except :
                pass
        self.keepAlive = False

class PTmp(ProcessEvent):
    def process_IN_IGNORED (self, event):
        pass

    def process_IN_CREATE(self, event):
        global newDevice
        if   (event.name[0:6] == "ttyACM")  and (event.path == "/dev") :
            portInfo = event.path + "/" + event.name
            newDevice.put(portInfo)

    def process_IN_DELETE(self, event):
        global deviceDisconnect
        if  (event.name[0:6] == "ttyACM")  and (event.path == "/dev") :
            portInfo = event.path + "/" + event.name
            deviceDisconnect.put(portInfo)

def Monitor(path):
    notifier = Notifier(wm, PTmp())
    wdd = wm.add_watch(path, mask, rec=True)
    newDevice.put('/dev/waggle_coresense')
    while True:
        try:
            notifier.process_events()
            if notifier.check_events():
                notifier.read_events()
        except KeyboardInterrupt:
            notifier.stop()
            break
