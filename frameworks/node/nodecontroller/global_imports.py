import threading
import Queue
import time
import copy
import os
from waggle.common.messaging_d import Message, MessageHeader, DataPayload, RegistrationPayload, ReplyPayload