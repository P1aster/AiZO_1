#ifndef AIZO_1_QUICKSORT_H
#define AIZO_1_QUICKSORT_H


enum PivotChoice {
    LEFT,
    RIGHT,
    MIDDLE,
    RANDOM
};

template <typename T>
class QuickSort {
public:
    void sort(T* arr, int size, PivotChoice pivotChoice);

private:
    void quickSort(T* arr, int low, int high, PivotChoice pivotChoice);
    int partition(T* arr, int low, int high, int pivot);
    int choosePivot(T* arr, int low, int high, PivotChoice pivotChoice);
};

#endif //AIZO_1_QUICKSORT_H
