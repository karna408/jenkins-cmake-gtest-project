# jenkins-cmake-gtest-project
#README_

## Package Addition

Qualified name: `app-sample-addition`

File name: `README.md`

This library allows to make some additions:
* Between two integers
* One integer with the ID, or the values 1 or 2.

### Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 
See deployment for notes on how to deploy the project on a live system.

#### Prerequisites
This project has no direct dependencies.

#### Installing
This project generates the library app-sample-addition_lib.

It uses cmake toolchains to configure the compiler options:
<https://cmake.org/cmake/help/git-stage/manual/cmake-toolchains.7.html>

* Building with CMake and Make
To build the project, run the following commands:

```bash

./build.sh

```

* Output 

It will create an install folder containing
* The headers
* The Cmake Configuration file 
* The libray file



### Running the tests

The Tests are developped using Google Test.

In order to install GTest on your machine, follow these instructions:
https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

To run the tests,run the following commands

```bash

./test.sh

```








