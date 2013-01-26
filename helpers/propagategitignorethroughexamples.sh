#!/bin/sh

mv gitignore .gitignore
find ../examples/ -type d -exec cp .gitignore {} \;
mv .gitignore gitignore
