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
cp ${RES_DIR}doxygen.css ${INSTALL_IMG_DIR}doxygen.css

date > doxygen_log.txt

echo "--- Web documents generating..."
for i in ${!OUT_FILES[@]} ; do
  from=${OBJ_FILES[$i]}
  dir_from=$(dirname ${from})
  to=${OUT_FILES[$i]}
  name_to=$(basename ${to} ".html")
  dir_to=$(dirname ${to})

  # Make a path to go back to the root
  cnt=($(echo ${to} | awk -F/ '{ print NF - 1 }'))
  gotoroot=""
  for ((i=0;i<cnt;i++)); do
    gotoroot+="../"
  done
  
  echo "  making a document ${name_to}.html <- ${from}"
  mkdir -p ${INSTALL_DIR}${dir_to}
  # Convert .md to .html with .css files
  pandoc -f markdown_github -t html -c ${gotoroot}Img/style.css -c ${gotoroot}Img/doxygen.css  ${ROOT_DIR}${from} -o ${INSTALL_DIR}${to}

  echo "    ... changing image links..."
  # 
  img_links=($(grep 'img src=[a-zA-Z0-9]*' ./${INSTALL_DIR}${to} | awk -F "\"" '{print $2}'))
  
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

  echo "    ... changing page links..."
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

  echo -n "    ... generating source codes..."
  code_links=($(grep '<!-- EXTERNAL LINK' ./${INSTALL_DIR}${to} | awk -F "\"" '{print $2}'))
  code_files=""
  for j in ${!code_links[@]}; do
    code_links[$j]=${ROOT_DIR}${dir_from}/${code_links[$j]}
    code_file_name=$(basename ${code_links[$j]})
    code_files="${code_files} ${code_file_name}"
  done
  cp -f ${RES_DIR}Doxfile ${RES_DIR}Doxyfile
  echo "INPUT = ${code_links[@]}" >> ${RES_DIR}Doxyfile
  #cat ${RES_DIR}Doxyfile
  doxygen ${RES_DIR}Doxyfile >> doxygen_log.txt

  code_files=$(echo ${code_files//_/__})
  echo ${code_files}



  cp tmp/{${code_files// /,}} ${INSTALL_DIR}${dir_to}
  #code_htmls=($())
  
  #$(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} ${INSTALL_DIR}${dir_to} ${code_links[@]})
  
  echo "done"
done

echo "--- Cleaning up files..."
#rm -rf tmp

echo "--- Web documents generation done!!"

