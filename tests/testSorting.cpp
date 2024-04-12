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
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}


template <typename T>
void TestSorting::runTests(SortMethod sortMethod, VectorTypes vectorType, std::vector<T> vector, int size, int repetitions) {
    FileHandler<double> fileHandler;
    double totalTime = 0;
    std::vector<double> times(repetitions);
    VectorGenerator<T> vectorGenerator;

    for (int i = 0; i < repetitions; ++i) {
        // Sort vec using chosen method
        switch (sortMethod) {
            case BUBBLESORT: {
                SortHandler<T, BubbleSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case QUICKSORT: {
                SortHandler<T, QuickSort<T>> sortHandler(vector);
                sortHandler.sort(PivotChoice::PIVOT_MIDDLE);
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case INSERTIONSORT: {
                SortHandler<T, InsertionSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case MERGESORT: {
                SortHandler<T, MergeSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case HEAPSORT: {
                SortHandler<T, HeapSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
            case SHELLSORT: {
                SortHandler<T, ShellSort<T>> sortHandler(vector);
                sortHandler.sort();
                totalTime += sortHandler.getExecutionTime().count();
                times[i] = sortHandler.getExecutionTime().count();
            }
                break;
        }
    }

    double averageTime = totalTime / repetitions;
    times.push_back(averageTime);


    fileHandler.writeVectorToFile(times, "size-" + std::to_string(size) + "_sort-" + std::to_string(sortMethod) + "_type-" + std::to_string(vectorType) + "_test.txt");
}

template bool TestSorting::isSorted<int>(const std::vector<int>&);
template bool TestSorting::isSorted<float>(const std::vector<float>&);
template bool TestSorting::isSorted<char>(const std::vector<char>&);

template void TestSorting::runTests<int>(SortMethod, VectorTypes, std::vector<int>, int, int);
template void TestSorting::runTests<float>(SortMethod, VectorTypes, std::vector<float>, int, int);
template void TestSorting::runTests<char>(SortMethod, VectorTypes, std::vector<char>, int, int);