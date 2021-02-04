#!/bin/bash

toolchain=$1/platforms/tc_linux_x86.cmake

if [ -z "$2" ]
then
  echo "Use default toolchain: $toolchain"
else
  toolchain=$1/platforms/$2
  echo "Use toolchain: $toolchain"
fi
  

rm -rf build/*
mkdir build
cd build
cmake .. -DUTILS_PATH=$1
make install
cd ..
