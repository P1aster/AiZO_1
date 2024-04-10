#include "fileHandler.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cstring>

template <typename T>
std::vector<T> FileHandler<T>::readVectorFromFile() {
    std::string filename;
    std::ifstream file;

    while (true) {
        std::cout << "To exit type 'exit': \n";
        std::cout << "Enter filename: ";
        std::cin >> filename;
        file.open(filename);

        // Check if the file exists
        if (file || filename == "exit") {
            break;
        } else {
            std::cout << "File not found. Please try again.\n";
        }
    }

    if (filename == "exit") {
        return std::vector<T>();
    }

    // Read the size of the vector
    int size;
    if (!(file >> size)) {
        throw FileReadException();
    }
    // Read the values of the vector
    std::vector<T> vec(size);
    for (int i = 0; i < size; ++i) {
        if (!(file >> vec[i])) {
            vec.clear();
            std::cout << "Failed to parse line " << i + 1 << ".\n";
            break;
        }
    }

    file.close();

    return vec;

}

template <typename T>
void FileHandler<T>::writeVectorToFile(const std::vector<T>& vec, std::string filename) {
    std::fstream file;

    while (true) {
        file.open(filename, std::ios::out | std::ios::trunc);

        // Check if the file was opened successfully
        if (file) {
            break;
        } else {
            std::cout << "\nFailed to open file: " << filename << ". Please try again.\n";
            std::cout << "Error: " << strerror(errno) << "\n";
        }
    }

    // Write the size of the vector
    file << vec.size() << "\n";
    for (const T& value : vec) {
        file << value << "\n";
    }
    file.close();
}

template <typename T>
void FileHandler<T>::writeVectorToFile(const std::vector<T>& vec) {
    std::string filename;
    std::fstream file;

    while (true) {
        // Ask the user for the filename
        std::cout << "Enter filename: ";
        std::cin >> filename;
        file.open(filename, std::ios::out | std::ios::trunc);

        // Check if the file was opened successfully
        if (file) {
            break;
        } else {
            std::cout << "\nFailed to open file: " << filename << ". Please try again.\n";
            std::cout << "Error: " << strerror(errno) << "\n";
        }
    }

    // Write the size of the vector
    file << vec.size() << "\n";
    for (const T& value : vec) {
        file << value << "\n";
    }
    file.close();
}

template class FileHandler<int>;
template class FileHandler<float>;
template class FileHandler<char>;
template class FileHandler<double>;