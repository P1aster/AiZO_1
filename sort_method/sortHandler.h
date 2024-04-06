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
    std::chrono::duration<double> executionTime;
public:
    SortHandler(std::vector<T> data);
    void sort(PivotChoice pivotPoint);
    void sort();
    std::vector<T> getData();
    std::chrono::duration<double> getExecutionTime();
};

#endif //AIZO_1_SORTHANDLERTEMPLATE_H