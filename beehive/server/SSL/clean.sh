#!/bin/bash

oldDir=.

cd $WAGGLE/beehive/server/SSL

rm -r server
cd waggleca
rm -r certs private
rm