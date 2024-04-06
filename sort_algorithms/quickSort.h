#ifndef AIZO_1_QUICKSORT_H
#define AIZO_1_QUICKSORT_H

#include <vector>

enum PivotChoice {
    LEFT,
    RIGHT,
    MIDDLE,
    RANDOM,
};

template <typename T>
class QuickSort {
public:
    void sort(std::vector<T>& arr, PivotChoice pivotChoice = PivotChoice::RIGHT);

private:
    void quickSort(std::vector<T>& arr, int low, int high, PivotChoice pivotChoice);
    int partition(std::vector<T>& arr, int low, int high, int pivot);
    int choosePivot(int low, int high, PivotChoice pivotChoice);
};


#endif //AIZO_1_QUICKSORT_H
