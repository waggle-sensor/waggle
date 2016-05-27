#!/bin/bash

set -e
set -x

VERSION="0.06.05"

apt-get install -y libattr1-dev libkeyutils-dev libbsd-dev

wget http://kernel.ubuntu.com/~cking/tarballs/stress-ng/stress-ng-${VERSION}.tar.gz
tar xvzf stress-ng-${VERSION}.tar.gz
cd stress-ng-${VERSION}
make