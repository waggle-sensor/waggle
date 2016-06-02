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
INSTALL_DIR=waggle_web/
INSTALL_IMG_DIR=${INSTALL_DIR}Img/

mkdir -p ${INSTALL_IMG_DIR}
cp ${RES_DIR}style.css ${INSTALL_IMG_DIR}style.css

echo "--- Web documents generating..."
for i in ${!OUT_FILES[@]} ; do
  from=${OBJ_FILES[$i]}
  dir_from=$(dirname ${from})
  to=${OUT_FILES[$i]}
  name_to=$(basename ${to} ".html")
  dir_to=$(dirname ${to})

  cnt=($(echo ${to} | awk -F/ '{ print NF - 1 }'))
  dir_from=$(dirname ${from})
  gotoroot=""
  for ((i=0;i<cnt;i++)); do
    gotoroot+="../"
  done
  
  echo -n "--- making a document ${to} <- ${from}"
  mkdir -p ${INSTALL_DIR}${dir_to}
  #echo "${gotoroot}"
  pandoc -f markdown_github -t html -c ${gotoroot}Img/style.css ${ROOT_DIR}${from} -o ${INSTALL_DIR}${to}

  echo -n "... changing image links..."
  img_links=($(grep 'img src=[a-zA-Z0-9]*' ./${INSTALL_DIR}${to} | awk -F "\"" '{print $2}'))
  #sed 's,href [a-zA-Z0-9]\"' ${to}
  for j in ${!img_links[@]}; do
    if [ "${img_links[$j]/"http"}" = "${img_links[$j]}" ]; then
      curr_link=${img_links[$j]}
      file_path=${ROOT_DIR}${dir_from}/${curr_link}
      file_name=$(basename ${file_path})
      #echo "${file_path}"
      cp ${file_path} ${INSTALL_IMG_DIR}/${file_name}
      new_link=${gotoroot}Img/${file_name}
      sed -i 's,'"${curr_link}"','"${new_link}"',g' ${INSTALL_DIR}${to}
    fi
  done
  #gotoroot+="../"
  #path_link=${gotoroot}${dir_from}/
  #sed -i 's,<img src=",<img src="'"${path_link}"',g' ${to}

  echo -n "... changing page links..."
  page_links=($(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} | tr -d "[',']"))
  #page_links=($(grep 'a href=[a-zA-Z0-9]*' ./${INSTALL_DIR}${to} | awk -F "\"" '{print $2}'))
  for j in ${!page_links[@]}; do
    if [ "${page_links[$j]/"http"}" = "${page_links[$j]}" ]; then
      curr_link=${page_links[$j]}
      for k in ${!OBJ_FILES[@]} ; do
        if [ "${dir_from}" == "." ]; then
          comp_link=${OBJ_FILES[$k]}
        else
          comp_link=$(echo ${OBJ_FILES[$k]//${dir_from}/})
        fi
        if [[ "${curr_link}" == *"${comp_link}"* ]]; then
          new_link=${gotoroot}${OUT_FILES[$k]}
          #echo "what? ${curr_link} <------- ${new_link}"
          sed -i 's,'"${curr_link}"','"${new_link}"',' ${INSTALL_DIR}${to}
        fi
      done
    fi
  done
  echo "done"
  
done

