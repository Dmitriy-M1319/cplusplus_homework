cmake_minimum_required(VERSION 3.24)
project(deque_examples LANGUAGES CXX)

add_compile_options(
    -g
    -Wall
    -Wextra
    -pedantic
)

add_executable(deque_int_example main_int.cpp)
add_executable(deque_string_example main_str.cpp)
add_executable(deque_tests tests.cpp)
