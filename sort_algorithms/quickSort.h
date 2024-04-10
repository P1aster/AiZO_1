#ifndef AIZO_1_QUICKSORT_H
#define AIZO_1_QUICKSORT_H

#include <vector>

enum PivotChoice {
    PIVOT_LEFT = 1,
    PIVOT_RIGHT = 2,
    PIVOT_MIDDLE = 3,
    PIVOT_RANDOM = 4
};

template <typename T>
class QuickSort {
public:
    void sort(std::vector<T>& arr, PivotChoice pivotChoice);

private:
    void quickSort(std::vector<T>& arr, int low, int high, PivotChoice pivotChoice);
    int partition(std::vector<T>& arr, int low, int high, int pivot);
    int choosePivot(int low, int high, PivotChoice pivotChoice);
};


#endif //AIZO_1_QUICKSORT_H
