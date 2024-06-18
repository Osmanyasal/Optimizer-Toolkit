#!/bin/bash

source ./uninstall.sh

for dr in $(ls -d */);
do
    cd $dr
    make clean
    make
    sudo cp optkit_* /usr/local/bin
    cd ..
done    

sudo cp optkit_sandbox_utils.py /usr/local/include
