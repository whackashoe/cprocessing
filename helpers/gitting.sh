#!/bin/sh

cd ../src
make clean
make || { echo "no make no commit bra"; exit 1; }

cd ../helpers
sh deleteexamples.sh 

git add .
git commit
git push -u origin master
