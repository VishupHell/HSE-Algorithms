cmake_minimum_required(VERSION 3.31)
project(Set9_A1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Set9_A1 main.cpp
        infrastructure/StringGenerator.h
        infrastructure/StringGenerator.cpp
        algorithms/MergeSort.h
        algorithms/MergeSort.cpp
        algorithms/SortAlgorithm.h
        infrastructure/StringTester.h
        infrastructure/StringTester.cpp
        algorithms/QuickSort.h
        algorithms/QuickSort.cpp
        algorithms/RadixSort.h
        algorithms/RadixSort.cpp
        algorithms/MSBRadixQuickSort.h
        algorithms/MSBRadixQuickSort.cpp
        algorithms/BasicMergeSort.h
        algorithms/BasicMergeSort.cpp
        algorithms/BasicQuickSort.h
        algorithms/BasicQuickSort.cpp)
