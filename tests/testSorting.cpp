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

template <typename T>
bool TestSorting::isSorted(const std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void TestSorting::runTests(std::vector<T>& vec, SortMethod sortMethod, int n, FileHandler<double>& fileHandler) {
    double totalTime = 0;
    std::vector<double> times(n);

    for (int i = 0; i < n; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        // Sort vec using chosen method
        switch (sortMethod) {
            case BUBBLESORT: {
                SortHandler<T, BubbleSort<T>> sortHandler(vec);
                sortHandler.sort();
            }
                break;
            case QUICKSORT: {
                SortHandler<T, QuickSort<T>> sortHandler(vec);
                sortHandler.sort(PivotChoice::RIGHT);
            }
                break;
            case INSERTIONSORT: {
                SortHandler<T, InsertionSort<T>> sortHandler(vec);
                sortHandler.sort();
            }
                break;
            case MERGESORT: {
                SortHandler<T, MergeSort<T>> sortHandler(vec);
                sortHandler.sort();
            }
                break;
            case HEAPSORT: {
                SortHandler<T, HeapSort<T>> sortHandler(vec);
                sortHandler.sort();
            }
                break;
            case SHELLSORT: {
                SortHandler<T, ShellSort<T>> sortHandler(vec);
                sortHandler.sort();
            }
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> executionTime = end - start;
        totalTime += executionTime.count();
        times[i] = executionTime.count();
    }

    double averageTime = totalTime / n;
    times.push_back(averageTime);
    std::cout << "Average time: " << averageTime << " ms\n";
//    fileHandler.writeVectorToFile(times);
}

template bool TestSorting::isSorted<int>(const std::vector<int>&);
template bool TestSorting::isSorted<float>(const std::vector<float>&);
template bool TestSorting::isSorted<char>(const std::vector<char>&);

template void TestSorting::runTests<int>(std::vector<int>&, SortMethod, int, FileHandler<double>&);
template void TestSorting::runTests<float>(std::vector<float>&, SortMethod, int, FileHandler<double>&);
template void TestSorting::runTests<char>(std::vector<char>&, SortMethod, int, FileHandler<double>&);