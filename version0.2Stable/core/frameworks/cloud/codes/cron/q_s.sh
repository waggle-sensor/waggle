export PYTHONPATH=/usr/local/lib/python2.7/dist-packages/
kill `pgrep -f "qservices"`
screen -S qservices -d -m /usr/bin/python /home/rajesh/waggle/core/frameworks/cloud/brett/v3/queue_services.py
