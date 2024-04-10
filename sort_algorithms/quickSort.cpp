#include <algorithm>
#include <iostream>
#include "quickSort.h"
#include "../utilities/inputHandler.h"




template <typename T>
int QuickSort<T>::choosePivot(int low, int high, PivotChoice pivotChoice) {
    switch(pivotChoice) {
        case PIVOT_LEFT:
            return low;
        case PIVOT_RIGHT:
            return high;
        case PIVOT_MIDDLE:
            return low + (high - low) / 2;
        case PIVOT_RANDOM:
            std::cout <<  low + rand() % (high - low + 1);
            return low + rand() % (high - low + 1);
        default:
            throw std::invalid_argument("Invalid pivot choice");
    }
}

template <typename T>
int QuickSort<T>::partition(std::vector<T>& arr, int low, int high, int pivot) {
    T pivotValue = arr[pivot];
    std::swap(arr[pivot], arr[high]);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivotValue) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void QuickSort<T>::sort(std::vector<T>& arr, PivotChoice pivotChoice) {
    quickSort(arr, 0, arr.size() - 1, pivotChoice);
}

template <typename T>
void QuickSort<T>::quickSort(std::vector<T>& arr, int low, int high, PivotChoice pivotChoice) {
    if (low < high) {
        int pivot = choosePivot(low, high, pivotChoice);
        int pi = partition(arr, low, high, pivot);

        quickSort(arr, low, pi - 1, pivotChoice);
        quickSort(arr, pi + 1, high, pivotChoice);
    }
}

template class QuickSort<int>;
template class QuickSort<float>;
template class QuickSort<char>;