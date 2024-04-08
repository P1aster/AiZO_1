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
void TestSorting::runTests(SortMethod sortMethod, int size, int n) {
    FileHandler<double> fileHandler;
    double totalTime = 0;
    std::vector<double> times(n);
    std::vector<T> pomVector;
    VectorGenerator<T> generator;

    for (int i = 0; i < n; ++i) {
        pomVector = generator.generateRandomVector(size);
        // Sort vec using chosen method
        switch (sortMethod) {
            case BUBBLESORT: {
                SortHandler<T, BubbleSort<T>> sortHandler(pomVector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case QUICKSORT: {
                SortHandler<T, QuickSort<T>> sortHandler(pomVector);
                sortHandler.sort(PivotChoice::RIGHT);
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case INSERTIONSORT: {
                SortHandler<T, InsertionSort<T>> sortHandler(pomVector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case MERGESORT: {
                SortHandler<T, MergeSort<T>> sortHandler(pomVector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case HEAPSORT: {
                SortHandler<T, HeapSort<T>> sortHandler(pomVector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case SHELLSORT: {
                SortHandler<T, ShellSort<T>> sortHandler(pomVector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
        }
    }

    double averageTime = totalTime / n;
    times.push_back(averageTime);
    std::cout << "Average time: " << averageTime << " ms\n";
    std::cout << "Write test result to file.\n";
    fileHandler.writeVectorToFile(times);
}

template bool TestSorting::isSorted<int>(const std::vector<int>&);
template bool TestSorting::isSorted<float>(const std::vector<float>&);
template bool TestSorting::isSorted<char>(const std::vector<char>&);

template void TestSorting::runTests<int>(SortMethod, int, int);
template void TestSorting::runTests<float>(SortMethod, int, int);
template void TestSorting::runTests<char>(SortMethod, int, int);