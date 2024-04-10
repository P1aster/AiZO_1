#ifndef AIZO_1_SORTHANDLERTEMPLATE_H
#define AIZO_1_SORTHANDLERTEMPLATE_H

#include <vector>
#include <chrono>
#include "../sort_algorithms/quickSort.h"

template <typename T, typename SortAlgorithm>
class SortHandler {
private:
    SortAlgorithm sortAlgorithm;
    std::vector<T> data;
    std::chrono::duration<float> executionTime;
public:
    SortHandler(std::vector<T> data);
//    void sort();
    void sort(PivotChoice pivotChoice = PivotChoice::PIVOT_RIGHT);
    std::vector<T> getData();
    std::chrono::duration<float> getExecutionTime();
};

#endif //AIZO_1_SORTHANDLERTEMPLATE_H