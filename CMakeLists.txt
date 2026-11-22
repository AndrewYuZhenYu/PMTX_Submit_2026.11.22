cmake_minimum_required(VERSION 3.16)
project(PMTX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PMTX main.cpp Point.cpp Geometry.cpp)
