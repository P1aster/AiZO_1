#include "vectorGenerator.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

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
        // Generate random values for the vector
        if constexpr (std::is_same<T, float>::value) {
            // Generate random float values between 0 and VALUE_MAX
            vec[i] = static_cast<T>(static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * static_cast<float>(VALUE_MAX);
        } else {
            // Generate random integer or char values
            vec[i] = static_cast<T>(std::rand());
        }
    }
    return vec;
}


template <typename T>
std::vector<T> VectorGenerator<T>::generateVector(VectorTypes vectorType, int size) {
    switch (vectorType) {
        case RANDOM:
            return generateRandomVector(size);
        case ASCENDING:
            return generateAscendingVector(size);
        case DESCENDING:
            return generateDescendingVector(size);
        case SORTED33:
            return generatePartiallySortedVector(size, 0.33);
        case SORTED66:
            return generatePartiallySortedVector(size, 0.66);
        default:
            return std::vector<T>();
    }
}

template <typename T>
std::vector<T> VectorGenerator<T>::generateAscendingVector(int size) {
    std::vector<T> vec = generateRandomVector(size);
    std::sort(vec.begin(), vec.end());
    return vec;
}

template <typename T>
std::vector<T> VectorGenerator<T>::generateDescendingVector(int size) {
    std::vector<T> vec = generateRandomVector(size);
    std::sort(vec.rbegin(), vec.rend());
    return vec;
}

template <typename T>
std::vector<T> VectorGenerator<T>::generatePartiallySortedVector(int size, double sortedFraction) {
    int sortedSize = static_cast<int>(size * sortedFraction);
    std::vector<T> vec = generateRandomVector(size);
    std::sort(vec.begin(), vec.begin() + sortedSize);
    return vec;
}


template class VectorGenerator<int>;
template class VectorGenerator<float>;
template class VectorGenerator<char>;