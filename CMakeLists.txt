cmake_minimum_required(VERSION 3.3)
project(Assignment_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.cpp DatabaseUtils.cpp DatabaseUtils.h)
add_executable(Assignment_1 ${SOURCE_FILES})
