
These instructions explain how to create a waggle image that can stress-test the ODROID, and print a barcode label upon success.


Download files:

```bash
for file in install-stress-ng.sh stress-test.conf_tmpl stress-test.sh ; do wget "https://raw.githubusercontent.com/waggle-sensor/waggle/master/testing/odroid/${file}" ; done
```