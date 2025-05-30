#include <iostream>
#include "sortHandler.h"
#include "../tests/testSorting.h"
#include "../sort_algorithms/bubbleSort.h"
#include "../sort_algorithms/InsertionSort.h"
#include "../sort_algorithms/heapSort.h"
#include "../sort_algorithms/shellSort.h"
#include "../sort_algorithms/mergeSort.h"

template <typename T, typename SortAlgorithm>
SortHandler<T, SortAlgorithm>::SortHandler(std::vector<T> data) : data(data) {}

template <typename T, typename SortAlgorithm>
void SortHandler<T, SortAlgorithm>::sort(PivotChoice pivotChoice) {

    auto start = std::chrono::high_resolution_clock ::now();
    if constexpr (std::is_same_v<SortAlgorithm, QuickSort<T>>) {
        sortAlgorithm.sort(data, pivotChoice);
    } else {
        sortAlgorithm.sort(data);
    }
    auto end = std::chrono::high_resolution_clock ::now();
    //duration_cast to get time in milliseconds with 6 digits after comma
    executionTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start);

    executionTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start);
}

template <typename T, typename SortAlgorithm>
std::vector<T> SortHandler<T, SortAlgorithm>::getData() {
    return data;
}

template <typename T, typename SortAlgorithm>
std::chrono::duration<double, std::milli> SortHandler<T, SortAlgorithm>::getExecutionTime() {
    return executionTime;
}

template class SortHandler<int, BubbleSort<int>>;
template class SortHandler<char, BubbleSort<char>>;
template class SortHandler<float, BubbleSort<float>>;
template class SortHandler<int, InsertionSort<int>>;
template class SortHandler<char, InsertionSort<char>>;
template class SortHandler<float, InsertionSort<float>>;
template class SortHandler<int, QuickSort<int>>;
template class SortHandler<char, QuickSort<char>>;
template class SortHandler<float, QuickSort<float>>;
template class SortHandler<int, HeapSort<int>>;
template class SortHandler<char, HeapSort<char>>;
template class SortHandler<float, HeapSort<float>>;
template class SortHandler<int, ShellSort<int>>;
template class SortHandler<char, ShellSort<char>>;
template class SortHandler<float, ShellSort<float>>;
template class SortHandler<int, MergeSort<int>>;
template class SortHandler<char, MergeSort<char>>;
template class SortHandler<float, MergeSort<float>>;