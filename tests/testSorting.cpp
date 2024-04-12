#include <chrono>
#include <iostream>
#include "testSorting.h"
#include "../sort_algorithms/bubbleSort.h"
#include "../sort_method/sortHandler.h"
#include "../sort_algorithms/quickSort.h"
#include "../sort_algorithms/insertionSort.h"
#include "../sort_algorithms/mergeSort.h"
#include "../sort_algorithms/heapSort.h"
#include "../sort_algorithms/shellSort.h"
#include "../utilities/printArray.h"
#include "../utilities/vectorGenerator.h"
#include <chrono>
template <typename T>
bool TestSorting::isSorted(const std::vector<T>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}


template <typename T>

std::chrono::duration<double, std::milli> TestSorting::runTests(SortMethod sortMethod, std::vector<T> vector, long repetitions) {
//    FileHandler<double> fileHandler;
    std::chrono::duration<double, std::milli> totalTime = std::chrono::duration<double, std::milli>::zero();
    VectorGenerator<T> vectorGenerator;

    for (long i = 0; i < repetitions; ++i) {
        // Sort vec using chosen method
        switch (sortMethod) {
            case BUBBLESORT: {
                SortHandler<T, BubbleSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime();
//                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case QUICKSORT: {
                SortHandler<T, QuickSort<T>> sortHandler(vector);
                sortHandler.sort(PivotChoice::PIVOT_MIDDLE);
                totalTime += sortHandler.getExecutionTime();
//                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case INSERTIONSORT: {
                SortHandler<T, InsertionSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime();
//                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case MERGESORT: {
                SortHandler<T, MergeSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime();
//                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case HEAPSORT: {
                SortHandler<T, HeapSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime();
//                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case SHELLSORT: {
                SortHandler<T, ShellSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime();
//                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
        }
    }
    return totalTime / repetitions;
}

template bool TestSorting::isSorted<int>(const std::vector<int>&);
template bool TestSorting::isSorted<float>(const std::vector<float>&);
template bool TestSorting::isSorted<char>(const std::vector<char>&);

template std::chrono::duration<double, std::milli> TestSorting::runTests<int>(SortMethod, std::vector<int>, long);
template std::chrono::duration<double, std::milli> TestSorting::runTests<float>(SortMethod, std::vector<float>, long);
template std::chrono::duration<double, std::milli> TestSorting::runTests<char>(SortMethod, std::vector<char>, long);