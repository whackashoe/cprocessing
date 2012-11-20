#!/bin/sh
find ../examples -type f | xargs file | grep "ELF.*executable" | awk -F: '{print $1}' | xargs rm
