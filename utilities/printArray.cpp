#include "printArray.h"
#include <iostream>

template <typename T>
void PrintArray::print(const std::vector<T>& arr) {
    for(const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template void PrintArray::print<int>(const std::vector<int>&);
template void PrintArray::print<float>(const std::vector<float>&);
template void PrintArray::print<char>(const std::vector<char>&);