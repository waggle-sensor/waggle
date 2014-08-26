#!/bin/bash

ARCHIVE_FILE=miBenchBinariesAndData.tar

if [ -e ${ARCHIVE_FILE} ]
then
    echo "MV"
    mv "${ARCHIVE_FILE}" "${ARCHIVE_FILE}.old"
fi

### Automotive applications

## Copy binaries and execution scripts
find ./automotive \( -iname "*.galileo.bin"  -print -o -iname "*.galileo.sh" -print \) | xargs tar -cf ${ARCHIVE_FILE}


## Append data
find ./automotive \( -iname "*.dat"  -print -o -iname "*.pgm" -print \) | xargs tar -rf ${ARCHIVE_FILE}







## Compress
gzip ${ARCHIVE_FILE}
