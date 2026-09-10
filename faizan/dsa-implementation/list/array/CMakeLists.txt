cmake_minimum_required(VERSION 3.14)

project(arrayList CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE DEBUG)

add_executable(out
    src/main.cpp
)

target_include_directories(out PRIVATE
    include
)