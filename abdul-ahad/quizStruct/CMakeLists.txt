cmake_minimum_required(VERSION 3.20)

project(quizStruct CXX)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(output main.cpp quest.cpp)
