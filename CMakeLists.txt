CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
cmake_policy(SET CMP0048 NEW)

# Initialize Conan
#INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)

project(
  app-sample-addition
  LANGUAGES C CXX
  VERSION 0.0.1
)

#CONAN_BASIC_SETUP()

# Add the cmake folder so the cmake utilities are found
set(CMAKE_MODULE_PATH "${UTILS_PATH}/cmake/modules" ${CMAKE_MODULE_PATH})

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

set(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 

add_subdirectory(source)

# add_subdirectory (doc)
