#!/bin/sh
echo "Bugs with examples"
ls ../bugs
echo "Example Errors that prevent builds"
./makeexamples.sh | grep -C6 "fail"
echo "Source code references"
cd ../src
grep -ir -C6 "TODO" ./
grep -ir -C6 "FIXME" ./
