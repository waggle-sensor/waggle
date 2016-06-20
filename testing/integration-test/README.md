

Purpose: Use software test to test hardware functionality and connections after node has been assembled.


Access to node will only be possible via serial port (diagnostics port).


Installation (copy-paste this block):
```bash
rm -f integration-test.py ; \
  wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/testing/integration-test/integration-test.py ; \
  chmod +x integration-test.py ; \
  ./integration-test.py
```

