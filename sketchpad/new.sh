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
else
	mkdir $1
	if [ $? -eq 1 ]; then
		echo "Need to change permissions to create folder" 1>&2
		exit 1
	fi
	
	cp .main.cpp $1/main.cpp
	
	unamestr=`uname`
	if [[ "$unamestr" == 'Linux' ]]; then
		cp .Makefile.lin $1/Makefile
	elif [[ "$unamestr" == 'Darwin' ]]; then
		cp .Makefile.dar $1/Makefile
	else
		cp .Makefile.win $1/Makefile
	fi
	
	cd $1
	#make
	

	echo "Sketch $1 created!"
	ls
fi
