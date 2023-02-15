cmake_minimum_required(VERSION 3.10)

project(lfu_cache_demo)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -pedantic -O2")

file(GLOB
    CPP_SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${CPP_SOURCES})
