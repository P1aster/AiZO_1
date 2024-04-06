//
// Created by mikis on 4/5/2024.
//

#ifndef AIZO_1_HEAPSORT_H
#define AIZO_1_HEAPSORT_H

#include <vector>

template <typename T>
class HeapSort {
public:
    void sort(std::vector<T>& arr);

private:
    void heapify(std::vector<T>& arr, int i);
};


#endif //AIZO_1_HEAPSORT_H
