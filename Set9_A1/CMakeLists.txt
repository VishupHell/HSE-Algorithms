cmake_minimum_required(VERSION 3.31)
project(Set9_A1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Set9_A1 main.cpp
        StringGenerator.h
        StringGenerator.cpp
        MergeSort.h
        MergeSort.cpp
        SortAlgorithm.h
        StringTester.h
        StringTester.cpp
        QuickSort.h
        QuickSort.cpp
        RadixSort.h
        RadixSort.cpp
        MSBRadixQuickSort.h
        MSBRadixQuickSort.cpp
        BasicMergeSort.h
        BasicMergeSort.cpp
        BasicQuickSort.h
        BasicQuickSort.cpp)
