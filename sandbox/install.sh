#!/bin/bash

for dr in $(ls -d */);
do
    cd $dr
    make
    sudo cp optkit_* /usr/local/bin
    cd ..
done    