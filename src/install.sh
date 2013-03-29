#!/bin/bash

#libcprocessing linux install script

version="0.2"   #increment this if testing to spot regressions
libDest="/usr/local/lib"
incDest="/usr/local/include"

make -j12 || { echo 'make failed' ; exit 1; }

if [ ! -d "$incDest/cprocessing" ]; then
	sudo mkdir /usr/local/include/cprocessing || { echo 'creating /usr/local/include/cprocessing failed'; exit 2; }
fi

sudo cp *hpp $incDest/cprocessing || { echo 'copying headers to $incDest/cprocessing failed'; exit 2; }

cd objects || { echo 'cd objects failed, run mkdir objects'; exit 3; }


gcc -shared -fPIC -o libcprocessing.so.$version *.o || { echo 'building .so failed'; exit 4; }
sudo cp libcprocessing.so.$version $libDest/libcprocessing.so.$version || { echo 'cp libcprocessing.so.$version $libDest/libcprocessing.so.$version failed'; exit 5; }

cd $libDest || { echo 'cd $libDest failed'; exit 6; }
if [ -e "libcprocessing.so" ]
    then
        echo "removing old libcprocessing symbolic link" &&
        sudo rm libcprocessing.so
fi

echo "linking"
sudo ln libcprocessing.so.$version libcprocessing.so || { echo 'linking libcprocessing failed'; exit 7; }
echo "processing ldconfig"
sudo ldconfig || { echo 'running ldconfig failed'; exit 8; }
echo "Done"

