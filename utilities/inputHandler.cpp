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
            // discard the invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Print error message
            std::cout << "Invalid input. Please try again.\n";
        }
    }
}
template ExitOption InputHandler::getEnumInput<ExitOption>(int, int);
template DataType InputHandler::getEnumInput<DataType>(int, int);
template SortMethod InputHandler::getEnumInput<SortMethod>(int, int);
template MenuOption InputHandler::getEnumInput<MenuOption>(int, int);
template int InputHandler::getEnumInput<int>(int, int);
