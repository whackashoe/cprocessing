#!/bin/sh

cd src
sh install.sh
cd ../helpers
sh makectags.sh
echo "done"
