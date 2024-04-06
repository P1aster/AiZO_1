#ifndef AIZO_1_VECTORGENERATOR_H
#define AIZO_1_VECTORGENERATOR_H
#include <vector>


/*
 * Function to create a vector of a given size
 * @param size: size of the vector
 * @return: vector of given size
 *
 * VectorGenerator<int> vectorGenerator;

    // Create vector of a specific size
    std::vector<int> vec = vectorGenerator.createVector(10);

    // Generate vector of random values
    std::vector<int> randomVector = vectorGenerator.generateRandomVector(10);

 *
 */

template <typename T>
class VectorGenerator {
public:
    std::vector<T> createVector(int size);
    std::vector<T> generateRandomVector(int size);

};

#endif //AIZO_1_VECTORGENERATOR_H
