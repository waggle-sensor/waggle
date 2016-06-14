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

IMG_START_TAG='<img src="'
IMG_END_TAG='>'
A_START_TAG='<a href="'
A_END_TAG='</a>'
EXT_CODE_START_TAG='<!-- EXT_CODE_LINK="'
EXT_CODE_END_TAG='-->'

# Create a image folder and copy style class files
mkdir -p ${INSTALL_IMG_DIR}
cp ${RES_DIR}style.css ${INSTALL_IMG_DIR}style.css
cp ${RES_DIR}doxygen.css ${INSTALL_IMG_DIR}doxygen.css

# For doxygen log
date > doxygen_log.txt

echo "--- Web documents generating..."
for i in ${!OUT_FILES[@]} ; do
  # Extract names and paths of the files
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
  
  # For .md files convert them into html files
  target_extension=${from##*.}

  if [ "${target_extension}" = "md" ]; then
    # Convert .md to .html with .css files
    pandoc -f markdown_github -t html -c ${gotoroot}Img/style.css -c ${gotoroot}Img/doxygen.css  ${ROOT_DIR}${from} -o ${INSTALL_DIR}${to}
  elif [ "${target_extension}" = "html" ]; then
    # Just copy the file to the destination
    cp ${ROOT_DIR}${from} ${INSTALL_DIR}${to}
  fi


  echo "    ... changing image links..."
  # Find image links from the html file
  #img_links=($(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} ${IMG_START_TAG} ${IMG_END_TAG} | tr -d "[',']"))
  img_links=($(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} "${IMG_START_TAG}" "${IMG_END_TAG}" | tr -d "[',']"))
  
  for j in ${!img_links[@]}; do
    # Ignor absolute path links
    if [ "${img_links[$j]/"http"}" = "${img_links[$j]}" ]; then
      curr_link=${img_links[$j]}
      file_path=${ROOT_DIR}${dir_from}/${curr_link}
      file_name=$(basename ${file_path})
      
      # Copy the image from the source to waggle-web dir
      cp ${file_path} ${INSTALL_IMG_DIR}/${file_name}
      new_link=${gotoroot}Img/${file_name}
      # Change the link to the one under waggle-web/img dir
      sed -i 's,'"${curr_link}"','"${new_link}"',g' ${INSTALL_DIR}${to}
    fi
  done

  echo "    ... changing page links..."
  # Find page links
  page_links=($(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} "${A_START_TAG}" "${A_END_TAG}" | tr -d "[',']"))
  #page_links=($(grep 'a href=[a-zA-Z0-9]*' ./${INSTALL_DIR}${to} | awk -F "\"" '{print $2}'))
  for j in ${!page_links[@]}; do
    # Ignore absolute path links
    if [ "${page_links[$j]/"http"}" = "${page_links[$j]}" ]; then
      curr_link=${page_links[$j]}
      for k in ${!OBJ_FILES[@]} ; do
        # Ignore the path itself
        if [[ ${OBJ_FILES[$k]} != ${from} ]]; then
          # Root path should not be involved
          if [ "${dir_from}" == "." ]; then
            comp_link=${OBJ_FILES[$k]}
          else
            comp_link=$(echo ${OBJ_FILES[$k]//${dir_from}/})
          fi

          # Re-direct the link. This only works if the designated link is in our file-list.txt
          if [[ "${curr_link}" == *"${comp_link}"* ]]; then
            new_link=${gotoroot}${OUT_FILES[$k]}
            sed -i 's,'"${curr_link}"','"${new_link}"',' ${INSTALL_DIR}${to}
          fi
        fi
      done
    fi
  done

  # THIS CODE IS FOR IN-TEXT LINKING
  echo "    ... generating in-text links to the source codes..."
  # Find source code links
  in_text_code_links=($(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} "${A_START_TAG}" "${A_END_TAG}" | tr -d "[',']"))
  code_files=""
  for j in ${!in_text_code_links[@]}; do
    code_file_name=$(basename ${in_text_code_links[$j]})
    code_file_ext=${code_file_name##*.}

    # The types of code files will only be considered
    if [ "${code_file_ext}" = "py" ] || [ "${code_file_ext}" = "ino" ] || [ "${code_file_ext}" = "c" ]; then
      in_text_code_links[$j]=${ROOT_DIR}${dir_from}/${in_text_code_links[$j]}
      code_files="${code_files} ${code_file_name%.*}"
    else
      in_text_code_links[$j]=""
    fi
  done

  # If more than one special tag found
  if [ ! -z "$code_files" ]; then
    cp -f ${RES_DIR}Doxfile ${RES_DIR}Doxyfile
    echo "INPUT = ${in_text_code_links[@]}" >> ${RES_DIR}Doxyfile

    # Replace any '_' with '__' because doxygen creates '__' files
    code_files=$(echo ${code_files//_/__})

    # Run doxygen with those input files
    doxygen ${RES_DIR}Doxyfile >> /dev/null

    # Make the code file a list
    in_text_code_links=(${in_text_code_links[@]})
    code_files=(${code_files})

    # Copy generated html files of the source code into the directory where
    # the code link file exists"
    for j in ${!code_files[@]}; do
      thefiles=($(find tmp -name "*${code_files[$j]}*.html"))
      for k in ${!thefiles[@]}; do
        # Re-direct doxygen.css
        sed -i 's,'"doxygen.css"','"${gotoroot}/Img/doxygen.css"',g' ${thefiles[$k]}
      done
      cp ${thefiles[@]} ${INSTALL_DIR}${dir_to}
      
      tmp="${ROOT_DIR}${dir_from}/"
      original_filename=$(echo ${in_text_code_links[$j]//${tmp}/})
      entry_file=$(find ${INSTALL_DIR}${dir_to} -name "${code_files[$j]}_8${in_text_code_links[$j]##*.}.html")
      entry_filename=$(basename ${entry_file})

      # Finally change the link of the a tag to the source code
      sed -i 's,'"${original_filename}"','"${entry_filename}"',' ${INSTALL_DIR}${to}
    done
  fi


  # # THIS CODE IS FOR CODE EMBEDDMENT
  # echo -n "    ... generating embedded source codes..."
  # Find a special tag, indicating an external link to a source code
  # code_links=($(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} "${EXT_CODE_START_TAG}" "${EXT_CODE_END_TAG}" | tr -d "[',']"))
  # echo ${code_links[@]}
  # code_files=""
  # for j in ${!code_links[@]}; do
  #   code_links[$j]=${ROOT_DIR}${dir_from}/${code_links[$j]}
  #   code_file_name=$(basename ${code_links[$j]})
  #   code_files="${code_files} ${code_file_name%.*}"
  # done

  # # If more than one special tag found
  # if [ ! -z "$code_files" ]; then
  #   # Configure Doxyfile with the files
  #   cp -f ${RES_DIR}Doxfile ${RES_DIR}Doxyfile
  #   echo "hi hello"
  #   echo ${code_links[@]}
  #   echo "INPUT = ${code_links[@]}" >> ${RES_DIR}Doxyfile

  #   # Replace any '_' with '__' because doxygen creates '__' files
  #   code_files=$(echo ${code_files//_/__})
    
  #   # Run doxygen with those input files
  #   doxygen ${RES_DIR}Doxyfile >> /dev/null

  #   # Make the code file a list
  #   code_files=(${code_files})

  #   # Copy generated html files of the source code into the directory where
  #   # the code link file exists
  #   for j in ${!code_files[@]}; do
  #     thefiles=($(find tmp -name "*${code_files[$j]}*.html"))
  #     for k in ${!thefiles[@]}; do
  #       # Re-direct doxygen.css
  #       sed -i 's,'"doxygen.css"','"${gotoroot}/Img/doxygen.css"',g' ${thefiles[$k]}
  #     done
  #     cp ${thefiles[@]} ${INSTALL_DIR}${dir_to}

  #     # Find the namespace of the source code to link it to the html file
  #     # namespace file is the representative file of the source file
  #     tmp="${ROOT_DIR}${dir_from}/"
  #     original_filename=$(echo ${code_links[$j]//${tmp}/})
  #     namespace_file=$(find ${INSTALL_DIR}${dir_to} -name "*namespace*${code_files[$j]}*.html")
  #     namespace_filename=$(basename ${namespace_file})
      
  #     # Finally change the special tags with the namespace html file
  #     $(python ${RES_DIR}utility.py ./${INSTALL_DIR}${to} "${EXT_CODE_START_TAG}" "${EXT_CODE_END_TAG}" ${original_filename} ${namespace_filename} ${namespace_filename%.*})
  #   done
  # fi
  
  echo "done"
done

echo "--- Cleaning up files..."
rm -rf tmp

echo "--- Web documents generation done!!"

