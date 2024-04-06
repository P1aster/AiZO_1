//
// Created by mikis on 4/5/2024.
//

#ifndef AIZO_1_HEAPSORT_H
#define AIZO_1_HEAPSORT_H

template <typename T>
class HeapSort {
public:
    void sort(T* arr, int n);

private:
    void heapify(T* arr, int n, int i);
};


#endif //AIZO_1_HEAPSORT_H
