//
// Created by mikis on 4/5/2024.
//

#ifndef AIZO_1_MERGESORT_H
#define AIZO_1_MERGESORT_H


#include <vector>

template <typename T>
class MergeSort {
public:
    void sort(std::vector<T>& arr);
private:
    void mergeSort(std::vector<T>& arr, int left, int right);
    void merge(std::vector<T>& arr, int left, int mid, int right);
};


#endif //AIZO_1_MERGESORT_H
