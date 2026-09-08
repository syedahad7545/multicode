cmake_minimum_required(VERSION 3.15)

project(Date CXX)

set(CMAKE_STANDARD_VERSION 17)

set(CMAKE_BUILD_TYPE debug)

add_executable(${PROJECT_NAME} Date.cpp
        main.cpp)
