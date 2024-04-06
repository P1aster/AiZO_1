cmake_minimum_required(VERSION 3.27)
project(AiZO_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(AiZO_1 main.cpp
        sort_algorithms/InsertionSort.cpp
        sort_algorithms/InsertionSort.h
        sort_algorithms/bubbleSort.cpp
        sort_algorithms/bubbleSort.h
        sort_algorithms/quickSort.cpp
        sort_algorithms/quickSort.h
        sort_algorithms/heapSort.cpp
        sort_algorithms/heapSort.h
        sort_algorithms/shellSort.cpp
        sort_algorithms/shellSort.h
        tests/testSorting.cpp
        tests/testSorting.h
        utilities/printArray.cpp
        utilities/printArray.h
        utilities/fileHandler.cpp
        utilities/fileHandler.h
        utilities/vectorGenerator.cpp
        utilities/vectorGenerator.h
        sort_algorithms/mergeSort.cpp
        sort_algorithms/mergeSort.h
        menu/menu.h
        sort_method/sortHandler.cpp
        sort_method/sortHandler.h
        utilities/inputHandler.cpp
        utilities/inputHandler.h

)
