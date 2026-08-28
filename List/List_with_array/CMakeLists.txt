cmake_minimum_required(VERSION 3.15)

project(list_with_array CXX)
set(CMAKE_STANDARD_VERSION 17)
set(CMAKE_BUILD_TYPE debug)

add_executable(out main.cpp List.cpp sorting.cpp)
