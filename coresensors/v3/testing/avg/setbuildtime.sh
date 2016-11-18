#!/bin/bash
echo "#define BUILD_TIME "$(echo $(date +%s)+12 | bc) > ./header/buildinfo.cpp
echo "#define BUILD_GIT \"$(git rev-parse HEAD | tail -c 5)\"" >> ./header/buildinfo.cpp
