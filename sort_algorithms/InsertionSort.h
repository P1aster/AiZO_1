#ifndef AIZO_1_INSERTIONSORT_H
#define AIZO_1_INSERTIONSORT_H


#include <vector>

template <typename T>
class InsertionSort {
public:
    void sort(std::vector<T> &arr, std::less<> less);
};



#endif //AIZO_1_INSERTIONSORT_H
