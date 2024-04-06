#include <algorithm>
#include "QuickSort.h"

template <typename T>
int QuickSort<T>::choosePivot(T* arr, int low, int high, PivotChoice pivotChoice) {
    switch(pivotChoice) {
        case LEFT:
            return low;
        case RIGHT:
            return high;
        case MIDDLE:
            return low + (high - low) / 2;
        case RANDOM:
            return low + rand() % (high - low + 1);
    }
}

template <typename T>
int QuickSort<T>::partition(T* arr, int low, int high, int pivot) {
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
void QuickSort<T>::sort(T* arr, int size, PivotChoice pivotChoice) {
    quickSort(arr, 0, size - 1, pivotChoice);
}

template <typename T>
void QuickSort<T>::quickSort(T* arr, int low, int high, PivotChoice pivotChoice) {
    if (low < high) {
        int pivot = choosePivot(arr, low, high, pivotChoice);
        int pi = partition(arr, low, high, pivot);

        quickSort(arr, low, pi - 1, pivotChoice);
        quickSort(arr, pi + 1, high, pivotChoice);
    }
}

template class QuickSort<int>;
template class QuickSort<float>;
template class QuickSort<char>;