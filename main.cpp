#include <iostream>

#include "utilities/vectorGenerator.h"
#include "utilities/fileHandler.h"
#include "tests/testSorting.h"
#include "sort_algorithms/bubbleSort.h"
#include "sort_algorithms/quickSort.h"
#include "sort_algorithms/heapSort.h"
#include "sort_algorithms/InsertionSort.h"
#include "sort_algorithms/shellSort.h"
#include "sort_algorithms/mergeSort.h"
#include "utilities/printArray.h"
#include "sort_method/sortHandler.h"
#include "utilities/inputHandler.h"
#include "menu/menu.h"


int main() {

    //setup variables
    MenuMode menuMode;
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
    FileHandler<double> fileHandlerDouble;
    TestSorting testSorting;
    PrintArray printVector;
    InputHandler inputHandler;

    // Main menu
    do {

        std::cout << "Select:\n1. Run Tests\n2. Play around\n";
        menuMode = inputHandler.getEnumInput<MenuMode>(1,2);

        std::cout << "Select data type:\n1. Int\n2. Float\n3. Char\n";
        dataType = inputHandler.getEnumInput<DataType>(1,3);

        // Select operation
        std::cout << "Select operation:\n1. Generate\n2. Read from file\n";
        operation = inputHandler.getEnumInput<Operation>(1,2);

        if (operation == GENERATE) {
            //Select vector size
            std::cout << "Pass generated vector size: ";
            size = inputHandler.getEnumInput<int>(1,10000000);
        }

        switch (dataType) {
            case INT:
                if (operation == GENERATE) {
                    vecInt = generatorInt.generateRandomVector(size);
                } else if(operation == READ) {
                    vecInt = fileHandlerInt.readVectorFromFile();
                }
                break;
            case FLOAT:
                if (operation == GENERATE) {
                    vecFloat = generatorFloat.generateRandomVector(size);
                } else if(operation == READ) {
                    vecFloat = fileHandlerFloat.readVectorFromFile();
                }
                break;
            case CHAR:
                if (operation == GENERATE) {
                    vecChar = generatorChar.generateRandomVector(size);
                } else if(operation == READ) {
                    vecChar = fileHandlerChar.readVectorFromFile();
                }
                break;
        }

        // Select sort method
        std::cout << "Select sort method:\n1. BubbleSort\n2. QuickSort\n3. MergeSort\n4. HeapSort\n5. InsertionSort\n6. ShellSort\n";
        sortMethod = inputHandler.getEnumInput<SortMethod>(1,6);

        if(menuMode == RUNTESTS) {
            goto runTestsJMP;
        }

        // Select write option
        std::cout << "Write to file?\n1. Yes\n2. No\n";
        writeOption = inputHandler.getEnumInput<WriteOption>(1,2);

    

        // Perform operations based on user's choices
        switch (dataType) {
            case INT:
                std::cout << "\nVector before sorting:\n";
                printVector.print(vecInt);
                // Sort vecInt using chosen method
                switch (sortMethod) {
                    case BUBBLESORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<int, BubbleSort<int>> sortHandler(vecInt);
                        // Sort the data
                        sortHandler.sort();
                        vecInt = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case QUICKSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<int, QuickSort<int>> sortHandler(vecInt);
                        // Sort the data
                        sortHandler.sort(PivotChoice::RIGHT);
                        vecInt = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case MERGESORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<int, MergeSort<int>> sortHandler(vecInt);
                        // Sort the data
                        sortHandler.sort();
                        vecInt = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case HEAPSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<int, HeapSort<int>> sortHandler(vecInt);
                        // Sort the data
                        sortHandler.sort();
                        vecInt = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case INSERTIONSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<int, InsertionSort<int>> sortHandler(vecInt);
                        // Sort the data
                        sortHandler.sort();
                        vecInt = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case SHELLSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<int, ShellSort<int>> sortHandler(vecInt);
                        // Sort the data
                        sortHandler.sort();
                        vecInt = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                }
                std::cout << "\nVector after sorting:\n";
                printVector.print(vecInt);

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

                std::cout << "\nVector before sorting:\n";
                printVector.print(vecFloat);

                // Sort vecInt using chosen method
                switch (sortMethod) {
                    case BUBBLESORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<float, BubbleSort<float>> sortHandler(vecFloat);
                        // Sort the data
                        sortHandler.sort();
                        vecFloat = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case QUICKSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<float, QuickSort<float>> sortHandler(vecFloat);
                        // Sort the data
                        sortHandler.sort(PivotChoice::RIGHT);
                        vecFloat = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case MERGESORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<float, MergeSort<float>> sortHandler(vecFloat);
                        // Sort the data
                        sortHandler.sort();
                        vecFloat = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case HEAPSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<float, HeapSort<float>> sortHandler(vecFloat);
                        // Sort the data
                        sortHandler.sort();
                        vecFloat = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case INSERTIONSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<float, InsertionSort<float>> sortHandler(vecFloat);
                        // Sort the data
                        sortHandler.sort();
                        vecFloat = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case SHELLSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<float, ShellSort<float>> sortHandler(vecFloat);
                        // Sort the data
                        sortHandler.sort();
                        vecFloat = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                }

                std::cout << "\nVector after sorting:\n";
                printVector.print(vecFloat);

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

                std::cout << "\nVector before sorting:\n";
                printVector.print(vecChar);
                // Sort vecInt using chosen method
                switch (sortMethod) {
                    case BUBBLESORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<char, BubbleSort<char>> sortHandler(vecChar);
                        // Sort the data
                        sortHandler.sort();
                        vecChar = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case QUICKSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<char, QuickSort<char>> sortHandler(vecChar);
                        // Sort the data
                        sortHandler.sort(PivotChoice::RIGHT);
                        vecChar = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case MERGESORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<char, MergeSort<char>> sortHandler(vecChar);
                        // Sort the data
                        sortHandler.sort();
                        vecChar = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case HEAPSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<char, HeapSort<char>> sortHandler(vecChar);
                        // Sort the data
                        sortHandler.sort();
                        vecChar = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case INSERTIONSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<char, InsertionSort<char>> sortHandler(vecChar);
                        // Sort the data
                        sortHandler.sort();
                        vecChar = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                    case SHELLSORT: {
                        // Create an instance of SortHandler with QuickSort as the sorting algorithm
                        SortHandler<char, ShellSort<char>> sortHandler(vecChar);
                        // Sort the data
                        sortHandler.sort();
                        vecChar = sortHandler.getData();
                        // Print the execution time
                        std::cout << "\nExecution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                    }
                        break;
                }

                std::cout << "\nVector after sorting:\n";
                printVector.print(vecChar);

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
        continue;

    runTestsJMP:

            // Perform operations based on user's choices
            std::cout << "Enter the number of times to run the test: ";
            int n = inputHandler.getEnumInput<int>(1,10000000);
            switch (dataType) {
                case INT:
                    testSorting.runTests(vecInt, sortMethod, n, fileHandlerDouble);
                    break;
                case FLOAT:
                    testSorting.runTests(vecFloat, sortMethod, n, fileHandlerDouble);
                    break;
                case CHAR:
                    testSorting.runTests(vecChar, sortMethod, n, fileHandlerDouble);
                    break;
            }

        // Ask user if they want to continue or exit
        std::cout << "\nSelect option:\n1. Continue\n2. Exit\n";
        menuOption = inputHandler.getEnumInput<MenuOption>(1,2);

    } while (menuOption != EXIT);

    return 0;
}