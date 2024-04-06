#ifndef AIZO_1_SORTHANDLERTEMPLATE_H
#define AIZO_1_SORTHANDLERTEMPLATE_H

#include <vector>
#include "../sort_algorithms/quickSort.h"

template <typename T, typename SortAlgorithm>
class SortHandler {
private:
    SortAlgorithm sortAlgorithm;
    std::vector<T> data;

public:
    SortHandler(std::vector<T> data);
    void sort(PivotChoice pivotPoint = PivotChoice::RIGHT);
    bool isSorted();
    std::vector<T> getData();
};

#endif //AIZO_1_SORTHANDLERTEMPLATE_H