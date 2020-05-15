cmake_minimum_required(VERSION 3.15)
project(cpp17test)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp17test main.cpp BaseMatrix.h Matrix.h Array.h errors.h)