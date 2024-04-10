#ifndef AIZO_1_INPUTHANDLER_H
#define AIZO_1_INPUTHANDLER_H

#include <vector>
#include "../menu/menu.h"

class InputHandler {
public:
    template <typename T>
    T getEnumInput(int min, int max);

    template <typename T>
    std::vector<T> getEnumsInput(int min, int max);

};


#endif //AIZO_1_INPUTHANDLER_H
