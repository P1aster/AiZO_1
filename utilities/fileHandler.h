//
// Created by mikis on 4/5/2024.
//

#ifndef AIZO_1_FILEHANDLER_H
#define AIZO_1_FILEHANDLER_H


/*
 * FileHandler class
 * This class is used to read and write vectors of any type to and from files.
 * The class is templated so that it can be used with any type.
 * FileHandler<int> fileHandler;
    // Read vector from file
    std::vector<int> vec = fileHandler.readVectorFromFile("input.txt");

    // Write vector to file
    fileHandler.writeVectorToFile("output.txt", vec);
 */

#include <vector>
#include <string>

class FileOpenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Unable to open file";
    }
};

class FileReadException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Not enough lines in file";
    }
};

class FileParseException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Failed to parse line";
    }
};

template <typename T>
class FileHandler {
public:
    std::vector<T> readVectorFromFile();
    void writeVectorToFile(const std::vector<T>& vec);
    void writeVectorToFile(const std::vector<T>& vec, std::string filename);
};



#endif //AIZO_1_FILEHANDLER_H
