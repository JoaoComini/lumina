#!/bin/bash

set -e

build_dir=$1

if ! [ -n "$build_dir" ]; then
    build_dir="build";
fi

if ! [ -d $build_dir ]; then
    mkdir $build_dir;
fi

cd $build_dir

cmake ..

make