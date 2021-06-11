#!/bin/bash

mkdir cocov
cp include/Addition.h cocov
cp source/Addition.cpp cocov
cp test/Addition_test.cpp cocov
cp test/main.cpp cocov
cd cocov
g++ -std=c++11 -fprofile-arcs -ftest-coverage -o add Addition.cpp Addition_test.cpp  -lgtest -lpthread
./add
gcovr -r .
gcovr -r . --html --html-details -o index.html
gcovr -r . --xml-pretty -o cobertura.xml
