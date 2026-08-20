cmake_minimum_required(VERSION 3.15)

project(Matrix CXX)

set(CXX_STANDARD_VERSION 17)
set(CMAKE_BUILD_TYPE debug)

add_executable(${PROJECT_NAME} main.cpp)
