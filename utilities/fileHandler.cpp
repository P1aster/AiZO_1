#include "fileHandler.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstring>

template <typename T>
std::vector<T> FileHandler<T>::readVectorFromFile() {
    std::string filename;
    std::ifstream file;

    while (true) {
        std::cout << "Enter filename: ";
        std::cin >> filename;
        file.open(filename);

        if (file) {
            break;
        } else {
            std::cout << "File not found. Please try again.\n";
        }
    }

    int size;
    file >> size;

    std::vector<T> vec(size);
    for (int i = 0; i < size; ++i) {
        std::string line;
        if (!std::getline(file, line)) {
            throw FileReadException();
        }

        std::istringstream iss(line);
        T value;
        if (!(iss >> value)) {
            throw FileParseException();
        }

        vec[i] = value;
    }

    return vec;
}

template <typename T>
void FileHandler<T>::writeVectorToFile(const std::vector<T>& vec) {
    std::string filename;
    std::fstream file;

    while (true) {
        std::cout << "\nEnter filename: ";
        std::cin >> filename;
        file.open(filename, std::ios::out | std::ios::trunc);

        if (file) {
            break;
        } else {
            std::cout << "\nFailed to open file: " << filename << ". Please try again.\n";
            std::cout << "Error: " << strerror(errno) << "\n";
        }
    }

    file << vec.size() << "\n";
    for (const T& value : vec) {
        file << value << "\n";
    }
    file.close();
}

template class FileHandler<int>;
template class FileHandler<float>;
template class FileHandler<char>;