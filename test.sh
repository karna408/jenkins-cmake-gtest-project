#!/bin/bash

cd test
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=../install
make
./app-sample-addition-test
./app-sample-addition-test --gtest_output="xml:testresults.xml"
cd ../..
