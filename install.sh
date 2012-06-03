#!/bin/bash

#libcprocessing linux install script

version="0.1"
libDest="/usr/local/lib"
incDest="/usr/local/include"

make

sudo cp cprocessing.hpp $incDest/cprocessing.hpp

cd objects
gcc -shared -fPIC -o libcprocessing.so.$version *.o && 
sudo cp libcprocessing.so.$version $libDest/libcprocessing.so.$version

cd $libDest 
if [ -e "libcprocessing.so" ]
    then
        echo "removing old libcprocessing" &&
        sudo rm libcprocessing.so
fi

echo "linking"
sudo ln libcprocessing.so.$version libcprocessing.so
echo "processing ldconfig"
sudo ldconfig
echo "Done"
