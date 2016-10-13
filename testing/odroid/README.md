
These instructions explain how to create a waggle image that can stress-test the ODROID (e.g. after replacing the heatsink), and print a barcode label upon success.

## Create stress-test image 

Take a waggle image and modify it accordingly:

Disable waggle services:
```bash
waggle-service stop waggle-init
rm -f /recovery_p*
touch /recovery_p1.tar.gz /recovery_p2.tar.gz
ls -1 /etc/init/waggle-* | grep -v epoch | xargs -i rm {}
```

Change some configurations:
```bash
echo "stress_test_image" > /etc/hostname
echo -e "auto lo\niface lo inet loopback" > /etc/network/interfaces
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

## CPU temperature

For debugging you may want to check the CPU temperature while running the stress-test:

```bash
while [ 1 ] ; do sleep 1 ; cat /sys/class/thermal/thermal_zone0/temp ; done
```
