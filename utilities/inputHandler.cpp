#include "inputHandler.h"
#include "../menu/menu.h"
#include <iostream>
#include <limits>

template <typename T>
T InputHandler::getEnumInput(int min, int max) {
    int input;
    while (true) {
        std::cin >> input;
        if (!std::cin.fail() && input >= min && input <= max) {
            return static_cast<T>(input);
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
        }
    }
}

template DataType InputHandler::getEnumInput<DataType>(int, int);
template Operation InputHandler::getEnumInput<Operation>(int, int);
template SortMethod InputHandler::getEnumInput<SortMethod>(int, int);
template WriteOption InputHandler::getEnumInput<WriteOption>(int, int);
template MenuOption InputHandler::getEnumInput<MenuOption>(int, int);
template MenuMode InputHandler::getEnumInput<MenuMode>(int, int);
template int InputHandler::getEnumInput<int>(int, int);
