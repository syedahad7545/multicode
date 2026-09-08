cmake_minimum_required(VERSION 3.15)

project(Raylib CXX)

set(CMAKE_CXX_REQUIRED 17)

find_package(raylib 5.0 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
