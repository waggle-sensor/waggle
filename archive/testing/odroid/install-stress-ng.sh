#!/bin/bash

set -e
set -x

VERSION="0.07.18"

apt-get install -y libattr1-dev libkeyutils-dev libbsd-dev

if [ ! -e stress-ng-${VERSION}.tar.gz ] ; then
  wget http://kernel.ubuntu.com/~cking/tarballs/stress-ng/stress-ng-${VERSION}.tar.gz
fi
tar xvzf stress-ng-${VERSION}.tar.gz
cd stress-ng-${VERSION}

if [ ! -e stress-ng-${VERSION}/stress-ng ] ; then 
  make
fi

cp stress-ng /usr/local/bin/
