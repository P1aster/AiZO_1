#include <algorithm>
#include "bubbleSort.h"


template <typename T>
void BubbleSort<T>::sort(std::vector<T> &arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = 0; j < arr.size()-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<char>;
