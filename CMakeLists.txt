cmake_minimum_required(VERSION 3.22)
project(Logger)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

file (GLOB SOURCES "src/*.cpp")

add_executable (Logger ${SOURCES})