#include <iostream>
#include <chrono>

#include "utilities/vectorGenerator.h"
#include "utilities/fileHandler.h"
#include "tests/testSorting.h"
#include "sort_algorithms/bubbleSort.h"
#include "sort_algorithms/quickSort.h"
#include "sort_algorithms/heapSort.h"
#include "sort_algorithms/InsertionSort.h"
#include "sort_algorithms/shellSort.h"
#include "sort_algorithms/mergeSort.h"

enum DataType { INT = 1, FLOAT = 2, CHAR = 3 };
enum Operation { GENERATE = 1, READ = 2 };
enum SortMethod { BUBBLESORT = 1, QUICKSORT = 2, MERGESORT = 3, HEAPSORT = 4, INSERTIONSORT = 5, SHELLSORT = 6};
enum WriteOption { YES = 1, NO = 2 };
enum MenuOption { CONTINUE = 1, EXIT = 2 };


int main() {

    //setup variables
    DataType dataType;
    Operation operation;
    int size;
    SortMethod sortMethod;
    WriteOption writeOption;
    MenuOption menuOption;
    std::string inputfilename;
    std::string outputfilename;

    std::vector<int> vecInt;
    std::vector<float> vecFloat;
    std::vector<char> vecChar;
    VectorGenerator<int> generatorInt;
    VectorGenerator<float> generatorFloat;
    VectorGenerator<char> generatorChar;
    FileHandler<int> fileHandlerInt;
    FileHandler<float> fileHandlerFloat;
    FileHandler<char> fileHandlerChar;
    TestSorting testSorting;

    // User input
    int input;

    // Main menu
    do {
        // Select data type
        std::cout << "Select data type:\n1. Int\n2. Float\n3. Char\n";
        std::cin >> input;
        dataType = static_cast<DataType>(input);
        // Select operation
        std::cout << "Select operation:\n1. Generate\n2. Read from file\n";
        std::cin >> input;
        operation = static_cast<Operation>(input);
        if (operation == GENERATE) {
            //Select vector size
            std::cout << "Pass generated vector size: ";
            std::cin >> input;
            size = static_cast<int>(input);
        }

        // Select sort method
        std::cout << "Select sort method:\n1. BubbleSort\n2. QuickSort\n3. MergeSort\n4. HeapSort\n5. InsertionSort\n6. ShellSort\n";
        std::cin >> input;
        sortMethod = static_cast<SortMethod>(input);

        // Select write option
        std::cout << "Write to file?\n1. Yes\n2. No\n";
        std::cin >> input;
        writeOption = static_cast<WriteOption>(input);

        auto start = std::chrono::high_resolution_clock::now();

        // Perform operations based on user's choices
        switch (dataType) {
            case INT:
                if (operation == GENERATE) {
                    vecInt = generatorInt.generateRandomVector(size);
                } else {
                    std::cout << "Pass input file path: ";
                    std::cin >> inputfilename;
                    vecInt = fileHandlerInt.readVectorFromFile();
                }
                // Sort vecInt using chosen method
                switch (sortMethod) {
                    case BUBBLESORT: {
                        BubbleSort<int> bubbleSort;
                        bubbleSort.sort(vecInt.data(), vecInt.size());
                    }
                        break;
                    case QUICKSORT: {
                        PivotChoice pivotChoice = RANDOM; // or any other choice based on your logic
                        QuickSort<int> quickSort;
                        quickSort.sort(vecInt.data(), vecInt.size(), pivotChoice);
                    }
                        break;
                    case MERGESORT: {
                        MergeSort<int> mergeSort;
                        mergeSort.sort(vecInt);
                    }
                        break;
                    case HEAPSORT: {
                        HeapSort<int> heapSort;
                        heapSort.sort(vecInt.data(), vecInt.size());
                    }
                        break;
                    case INSERTIONSORT: {
                        InsertionSort<int> insertionSort;
                        insertionSort.sort(vecInt.data(), vecInt.size());
                    }
                        break;
                    case SHELLSORT: {
                        ShellSort<int> shellSort;
                        shellSort.sort(vecInt.data(), vecInt.size());
                    }
                        break;
                }
                // Check if sorted
                if (testSorting.isSorted(vecInt)) {
                    std::cout << "Vector is sorted.\n";
                } else {
                    std::cout << "Vector is not sorted.\n";
                }
                if (writeOption == YES) {
                    fileHandlerInt.writeVectorToFile(vecInt);
                }
                break;
            case FLOAT:
                if (operation == GENERATE) {
                    vecFloat = generatorFloat.generateRandomVector(100);
                } else {
                    vecFloat = fileHandlerFloat.readVectorFromFile();
                }
                // Sort vecFloat using chosen method
                // Check if sorted
                if (testSorting.isSorted(vecFloat)) {
                    std::cout << "Vector is sorted.\n";
                } else {
                    std::cout << "Vector is not sorted.\n";
                }
                if (writeOption == YES) {
                    fileHandlerFloat.writeVectorToFile(vecFloat);
                }
                break;
            case CHAR:
                if (operation == GENERATE) {
                    vecChar = generatorChar.generateRandomVector(100);
                } else {
                    vecChar = fileHandlerChar.readVectorFromFile();
                }
                // Sort vecChar using chosen method
                // Check if sorted
                if (testSorting.isSorted(vecChar)) {
                    std::cout << "Vector is sorted.\n";
                } else {
                    std::cout << "Vector is not sorted.\n";
                }
                if (writeOption == YES) {
                    fileHandlerChar.writeVectorToFile(vecChar);
                }
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;

        // Ask user if they want to continue or exit
        std::cout << "Select option:\n1. Continue\n2. Exit\n";
        std::cin >> input;
        menuOption = static_cast<MenuOption>(input);
    } while (menuOption != EXIT);

    return 0;
}