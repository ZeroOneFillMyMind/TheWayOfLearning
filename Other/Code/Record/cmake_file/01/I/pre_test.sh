#!/bin/bash

ROOT_DIR=`pwd`

dir="01/I"

if [ -d "$ROOT_DIR/$dir/build.clang" ]; then
    echo "deleting $dir/build.clang"
    rm -r $dir/build.clang
fi
