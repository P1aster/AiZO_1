#ifndef AIZO_1_TESTSORTING_H
#define AIZO_1_TESTSORTING_H

#include "../utilities/fileHandler.h"
#include "../menu/menu.h"
#include <vector>


class TestSorting {
public:
    template <typename T>
    bool isSorted(const std::vector<T>& arr);

    template <typename T>
    void runTests(SortMethod sortMethod, VectorTypes vectorType, int size, int n);
};

#endif //AIZO_1_TESTSORTING_H
