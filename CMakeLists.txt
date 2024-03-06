cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    untitled
    ${CMAKE_SOURCE_DIR}/source/atcoder/abc343_e.cpp
)

target_include_directories(untitled PUBLIC ${CMAKE_SOURCE_DIR})