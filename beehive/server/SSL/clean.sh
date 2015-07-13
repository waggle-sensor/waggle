#!/bin/bash

oldDir=.

cd DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

rm -r server
cd waggleca
rm -r certs private
rm serial* index.* cacert*