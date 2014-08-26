bash_tools="cd chmod cp echo export mkdir mv pwd python rm tar wget which"
for CMD in $bash_tools
do
    if ! type "$CMD" 2> /dev/null > /dev/null; then
        echo "Can not automate install, missing shell command \"$CMD\"." 
        echo "Exiting..."
        exit
    fi
done

if ! python -c "import setuptools" 2> /dev/null > /dev/null; then
    echo "Can not automate install, missing python package setuptools."
    echo "Exiting..."
    exit
fi

echo "Installing WAggLE client..."
echo
echo "Creating root directory..."

ROOT_DIR="`pwd`/waggle_files"
mkdir -p $HOME/local/lib/python2.7/site-packages
export PYTHONPATH=$PYTHONPATH:$HOME/local/lib/python2.7/site-packages
rm -rf ${ROOT_DIR} > /dev/null
rm -rf ./WAggLESensors.sh > /dev/null
mkdir ${ROOT_DIR}
cd ${ROOT_DIR}
echo
echo "Fetching WAggLE packages and dependencies..."

wget -q  "http://www.mcs.anl.gov/~brhodes/waggle_commons-1.tar.gz" > /dev/null
wget -q  "https://pypi.python.org/packages/source/P/PySensors/PySensors-0.0.2.tar.gz" > /dev/null
wget -q  "https://pypi.python.org/packages/source/p/pika/pika-0.9.13.tar.gz" > /dev/null

tar -xzf PySensors-0.0.2.tar.gz > /dev/null
tar -xzf pika-0.9.13.tar.gz > /dev/null
#tar -xzf waggle_commons-1.tar.gz > /dev/null

cd PySensors-0.0.2
echo
echo "Installing dependencies - Pika and PythonSensors."
python setup.py install --prefix=$HOME/local > /dev/null

cd ../pika-0.9.13
python setup.py install --prefix=$HOME/local > /dev/null

cd ..
rm -rf PySensors-0.0.2* > /dev/null
rm -rf pika-0.9.13* > /dev/null


WAGGLE_COMMONS_PACKAGE="${ROOT_DIR}/waggle_commons-1.tar.gz"
echo
echo "Installing waggle_commons package..."

cd ${ROOT_DIR}
mkdir install_dir
mv ${WAGGLE_COMMONS_PACKAGE} install_dir/
cd install_dir
tar -xzf waggle_commons-1.tar.gz > /dev/null
cd waggle_commons-1
python setup.py install --prefix=$HOME/local > /dev/null

echo
echo "Installing Node Controller package..."
cd ${ROOT_DIR}
wget -q  "http://www.mcs.anl.gov/~brhodes/waggle_node_controller-1.tar.gz" > /dev/null
tar -xzf waggle_node_controller-1.tar.gz > /dev/null
rm waggle_node_controller-1.tar.gz > /dev/null
rm -rf install_dir > /dev/null

cd waggle_node_controller-1

# echo "Run node controller"
echo
python welcome.py

echo
#echo "In order for WAggLE to operate correctly, please make sure" 
#echo "$HOME/local/lib/python2.7/site-packages"
#echo "is in your PYTHONPATH environment variable. The following "
#echo "command will add it for you:"
#echo "export PYTHONPATH=\$PYTHONPATH:$HOME/local/lib/python2.7/site-packages"
#echo 
echo "__________________________________________________________"
echo
cd ${ROOT_DIR}
cd ..
cp ${ROOT_DIR}/waggle_node_controller-1/WAggLESensors.sh .
chmod +x WAggLESensors.sh
./WAggLESensors.sh
