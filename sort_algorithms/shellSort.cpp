#include "shellSort.h"

template <typename T>
void ShellSort<T>::sort(T* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

template class ShellSort<int>;
template class ShellSort<float>;
template class ShellSort<char>;
