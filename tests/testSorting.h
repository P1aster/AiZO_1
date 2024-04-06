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
    void runTests(std::vector<T>& vec, SortMethod sortMethod, int n, FileHandler<double>& fileHandler);
};

#endif //AIZO_1_TESTSORTING_H
