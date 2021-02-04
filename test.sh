#!/bin/bash

cd test
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=../install
make
./app-sample-addition-test
cd ../..
