#include "inputHandler.h"
#include "../menu/menu.h"
#include "../sort_algorithms/quickSort.h"
#include <iostream>
#include <limits>
#include <sstream>

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
template <typename T>
std::vector<T> InputHandler::getEnumsInput(int min, int max) {
    std::vector<T> enumValues;
    std::string line;
    int number;

    // Add a prompt for the user
    std::cout << "Enter the numbers separated by commas: ";


    // discards the input buffer
    std::cin.sync();

    std::getline(std::cin, line);

    std::stringstream ss(line);

    while (ss >> number) {
        if (number < min || number > max) {
            std::cout << "Invalid value. Please try again.\n";
            return getEnumsInput<T>(min, max);
        }

        enumValues.push_back(static_cast<T>(number));

        // Ignore the comma and any white spaces
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> std::ws;
    }

    return enumValues;
}


template ExitOption InputHandler::getEnumInput<ExitOption>(int, int);
template DataType InputHandler::getEnumInput<DataType>(int, int);
template SortMethod InputHandler::getEnumInput<SortMethod>(int, int);
template MenuOption InputHandler::getEnumInput<MenuOption>(int, int);
template MainMenuOption InputHandler::getEnumInput<MainMenuOption>(int, int);

template PivotChoice InputHandler::getEnumInput<PivotChoice>(int, int);
template int InputHandler::getEnumInput<int>(int, int);
template long InputHandler::getEnumInput<long>(int, int);

template std::vector<int> InputHandler::getEnumsInput<int>(int, int);
template std::vector<DataType> InputHandler::getEnumsInput<DataType>(int, int);
template std::vector<SortMethod> InputHandler::getEnumsInput<SortMethod>(int, int);
template std::vector<VectorTypes> InputHandler::getEnumsInput<VectorTypes>(int, int);

