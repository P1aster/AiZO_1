#include "mergeSort.h"

template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr) {
    if (arr.size() <= 1) return;
    mergeSort(arr, 0, arr.size() - 1);
}

template <typename T>
void MergeSort<T>::mergeSort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename T>
void MergeSort<T>::merge(std::vector<T>& arr, int left, int mid, int right) {
    std::vector<T> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

template class MergeSort<int>;
template class MergeSort<float>;
template class MergeSort<char>;