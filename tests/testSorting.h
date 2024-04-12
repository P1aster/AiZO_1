#ifndef AIZO_1_TESTSORTING_H
#define AIZO_1_TESTSORTING_H

#include "../utilities/fileHandler.h"
#include "../menu/menu.h"
#include <vector>
#include <chrono>

class TestSorting {
public:
    template <typename T>
    bool isSorted(const std::vector<T>& arr);

    template <typename T>
    std::chrono::duration<double, std::milli> runTests(SortMethod sortMethod, std::vector<T> vector, long repetitions); // Change this
};

#endif //AIZO_1_TESTSORTING_H
