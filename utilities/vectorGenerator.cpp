#include "vectorGenerator.h"
#include <cstdlib>
#include <ctime>



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
        vec[i] = static_cast<T>(std::rand());
    }
    return vec;
}

template class VectorGenerator<int>;
template class VectorGenerator<float>;
template class VectorGenerator<char>;