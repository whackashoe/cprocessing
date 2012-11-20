#!/bin/sh

cd src
sh install.sh
cd ..
doxygen
cd helpers
sh makeexamples.sh
echo "done"
