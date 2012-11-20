#!/bin/sh

# CProcessing sketchpad creator
###############################
# Takes name as input
# Creates new folder with name
# Creates main.cpp and Makefile in folder
#########################################


if [ $# -eq 0 ]
then
	echo "You must give a name to sketch"
	echo "e.g.: \"./new.sh myfirstsketch\""
	exit 1
fi

#arg was given
#TODO:check for "bad" characters


if [ -d $1 ]; then
	echo "Sketch Already Exists" 1>&2
	exit 1
fi

mkdir $1
if [ $? -eq 1 ]; then
    echo "Need to change permissions to create folder" 1>&2
    exit 1
fi
	
cp ../helpers/sketchmain.cpp $1/main.cpp
cp ../helpers/sketchdebug.sh $1/debug.sh

unamestr=`uname`
if [ "$unamestr" = "Linux" ]; then
    cp ../helpers/SketchMakefile.lin $1/Makefile
elif [ "$unamestr" = "Darwin" ]; then
    cp ../helpers/SketchMakefile.dar $1/Makefile
else
    cp ../helpers/SketchMakefile.win $1/Makefile
fi
	
cd $1
#make
	

echo "Sketch $1 created!"
ls

