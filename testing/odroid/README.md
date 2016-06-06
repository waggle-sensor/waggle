
These instructions explain how to create a waggle image that can stress-test the ODROID (e.g. after replacing the heatsink), and print a barcode label upon success.

## Create stress-test image 


Disable waggle services:
```bash
waggle-service stop waggle-init
ls -1 /etc/init/waggle-* | grep -v epoch | xargs -i rm {}
```



Install files:

```bash
mkdir -p /root/stress-test ; cd /root/stress-test

for file in install.sh install-stress-ng.sh stress-test.conf_tmpl stress-test.sh print_status.sh_tmpl ; do
  rm -f ${file}
  wget "https://raw.githubusercontent.com/waggle-sensor/waggle/master/testing/odroid/${file}"
done

chmod +x install.sh install-stress-ng.sh stress-test.sh

./install.sh

```

## QA testing instructions

[QA_testing_instructions.md](./QA_testing_instructions.md)
