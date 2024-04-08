#include "vectorGenerator.h"
#include <cstdlib>
#include <ctime>

const float VALUE_MAX = 10000.0f; // Maximum value for float

template <typename T>
std::vector<T> VectorGenerator<T>::createVector(int size) {
    std::vector<T> vec(size);
    return vec;
}


template <typename T>
std::vector<T> VectorGenerator<T>::generateRandomVector(int size) {
    std::srand(std::time(nullptr));
    std::vector<T> vec(size);
    for (int i = 0; i < size; ++i) {
        if constexpr (std::is_same<T, float>::value) {
            vec[i] = static_cast<T>(static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * static_cast<float>(VALUE_MAX);
        } else {
            vec[i] = static_cast<T>(std::rand());
        }
    }
    return vec;
}


template class VectorGenerator<int>;
template class VectorGenerator<float>;
template class VectorGenerator<char>;