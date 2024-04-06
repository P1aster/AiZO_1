#include "InsertionSort.h"

template <typename T>
void InsertionSort<T>::sort(T* arr, int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template class InsertionSort<int>;
template class InsertionSort<float>;
template class InsertionSort<char>;