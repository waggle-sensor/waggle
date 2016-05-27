#!/bin/bash

echo "--- Web documents initializing..."

if [ $# -eq 0 ]
  then
    echo "No arguments inserted! - use 'make docs'."
    exit 1
fi

FILE="$1"

OBJ_FILES=($(awk -F '[:]' '{print $2}' ${FILE}))
OUT_FILES=($(awk -F '[:]' '{print $1}' ${FILE}))

ROOT_DIR=../
WEB_DIR=${ROOT_DIR}web/
RES_DIR=./res/

echo "--- Web documents generating..."
for i in ${!OUT_FILES[@]} ; do
  from=${OBJ_FILES[$i]}
  dir_from=$(dirname ${from})
  to=${OUT_FILES[$i]}
  name_to=$(basename ${to} ".html")
  dir_to=$(dirname ${to})
  
  echo "--- making a document ${to} <- ${from}"
  mkdir -p ${dir_to}
  pandoc -f markdown_github -t html ${ROOT_DIR}${from} -o ./${to}

  #echo "--- --- changing image links..."
  cnt=($(echo ${to} | awk -F/ '{ print NF - 1 }'))
  dir_from=$(dirname ${from})
  gotoroot=""
  for ((i=0;i<cnt;i++)); do
    gotoroot+="../"
  done
  gotoroot+="../"

  path_link=${gotoroot}${dir_from}/
  sed -i 's,<img src=",<img src="'"${path_link}"',g' ${to}

  #echo "--- --- changing page links..."
  echo ${cnt}
  python ${RES_DIR}utility.py ./${to} ${dir_from} ${cnt} ${FILE}
  
done

