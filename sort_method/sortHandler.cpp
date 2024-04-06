#include "sortHandler.h"
#include "../tests/testSorting.h"
#include "../sort_algorithms/bubbleSort.h"
#include "../sort_algorithms/InsertionSort.h"
#include "../sort_algorithms/quickSort.h"
#include "../sort_algorithms/heapSort.h"
#include "../sort_algorithms/shellSort.h"
#include "../sort_algorithms/mergeSort.h"

template <typename T, typename SortAlgorithm>
SortHandler<T, SortAlgorithm>::SortHandler(std::vector<T> data) : data(data) {}

template <typename T, typename SortAlgorithm>
void SortHandler<T, SortAlgorithm>::sort(PivotChoice pivotChoice) {
    if constexpr (std::is_same_v<SortAlgorithm, QuickSort<T>>) {
        sortAlgorithm.sort(data, pivotChoice);
    }
    else {
        sortAlgorithm.sort(data);
    }
}

template <typename T, typename SortAlgorithm>
bool SortHandler<T, SortAlgorithm>::isSorted() {
    TestSorting testSorting;
    return testSorting.isSorted(data);
}

template <typename T, typename SortAlgorithm>
std::vector<T> SortHandler<T, SortAlgorithm>::getData() {
    return data;
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