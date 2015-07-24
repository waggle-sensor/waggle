#!/bin/bash

# This script packs up the server in a nice easy-to-distribute .tar.gz file
read -p "Enter the name of the server as you want it distributed: " dirName
mkdir $dirName
cp -r server $dirName/
mkdir $dirName/devtools
cp -r devtools/protocol_common $dirName/devtools
cp WaggleServer.sh $dirName/
chmod 777 -R $dirName
tar -cvzf $dirName.tar.gz $dirName
rm -rf $dirName
exit 0