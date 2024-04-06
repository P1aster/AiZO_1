#include <algorithm>
#include "bubbleSort.h"


template <typename T>
void BubbleSort<T>::sort(T* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<char>;
