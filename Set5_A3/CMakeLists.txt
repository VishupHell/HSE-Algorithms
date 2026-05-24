cmake_minimum_required(VERSION 3.31)
project(Set5_A3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp RandomStreamGen.h RandomStreamGen.cpp
        HashFuncGen.h
        HashFuncGen.cpp)