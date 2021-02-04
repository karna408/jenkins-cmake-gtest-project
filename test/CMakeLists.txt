CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

PROJECT(app-sample-addition-test CXX)

SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 

FIND_PACKAGE(app-sample-addition_lib REQUIRED)

SET(CMAKE_INSTALL_RPATH "${app-sample-addition_DIR}/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(CMAKE_INSTALL_RPATH "${app-sample-addition_DIR}/lib")

ENABLE_TESTING()
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

# Create application test ######################################################
ADD_EXECUTABLE(${PROJECT_NAME} 
  main.cpp 
  Addition_test.cpp
  )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} app-sample-addition::app-sample-addition_lib GTest::GTest GTest::Main)

# Include application test #######################################################
ADD_TEST(NAME ${PROJECT_NAME}
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
         COMMAND ${PROJECT_NAME})
