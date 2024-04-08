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
    DataType dataType;
    ExitOption exitOption;
    int size;
    SortMethod sortMethod;
    MenuOption menuOption;

    std::vector<int> vecInt;
    std::vector<float> vecFloat;
    std::vector<char> vecChar;
    std::vector<int> vecIntSorted;
    std::vector<float> vecFloatSorted;
    std::vector<char> vecCharSorted;

    VectorGenerator<int> generatorInt;
    VectorGenerator<float> generatorFloat;
    VectorGenerator<char> generatorChar;
    FileHandler<int> fileHandlerInt;
    FileHandler<float> fileHandlerFloat;
    FileHandler<char> fileHandlerChar;
    TestSorting testSorting;
    PrintArray printVector;
    InputHandler inputHandler;

    // Main menu
    while (true) {
        // Select data type
        std::cout << "Select data type:\n1. Int\n2. Float\n3. Char\n";
        dataType = inputHandler.getEnumInput<DataType>(1,3);

        while(menuOption != EXIT) {
            std::cout << "Select:\n1. Read from file\n2. Generate random array\n3. Save Generate random array to file\n4. Display array\n5. Sort array\n6. Display sorted array\n7. Run tests\n8. Back to main manu\n";
            menuOption = inputHandler.getEnumInput<MenuOption>(1,8);

            switch (menuOption) {
                case READFROMFILE: // Read from file
                    switch (dataType) {
                        case INT:
                            vecInt = fileHandlerInt.readVectorFromFile();
                            if(vecInt.empty()) {
                                break;
                            }
                            break;
                        case FLOAT:
                            vecFloat = fileHandlerFloat.readVectorFromFile();
                            if(vecFloat.empty()) {
                                break;
                            }
                            break;
                        case CHAR:
                            vecChar = fileHandlerChar.readVectorFromFile();
                            if(vecChar.empty()) {
                                break;
                            }
                            break;
                    }
                    break;
                case GENERATERANDOM: // Generate random array
                    //Select vector size
                    std::cout << "Pass generated vector size: ";
                    size = inputHandler.getEnumInput<int>(1,10000000);
                    switch (dataType) {
                        case INT:
                            vecInt = generatorInt.generateRandomVector(size);
                            break;
                        case FLOAT:
                            vecFloat = generatorFloat.generateRandomVector(size);
                            break;
                        case CHAR:
                            vecChar = generatorChar.generateRandomVector(size);
                            break;
                    }
                    break;
                case SAVEGENERATEDARRAYTOFILE: // Save generated array to file
                    switch (dataType) {
                        case INT:
                            fileHandlerInt.writeVectorToFile(vecInt);
                            break;
                        case FLOAT:
                            fileHandlerFloat.writeVectorToFile(vecFloat);
                            break;
                        case CHAR:
                            fileHandlerChar.writeVectorToFile(vecChar);
                            break;
                    }
                    break;
                case DISPLAYARRAY: // Display array
                    switch (dataType) {
                        case INT:
                            printVector.print(vecInt);
                            break;
                        case FLOAT:
                            printVector.print(vecFloat);
                            break;
                        case CHAR:
                            printVector.print(vecChar);
                            break;
                    }
                    break;
                case SORTARRAY: { // Sort array
                    // Select sort method
                    std::cout << "Select sort method:\n1. BubbleSort\n2. QuickSort\n3. MergeSort\n4. HeapSort\n5. InsertionSort\n6. ShellSort\n";
                    sortMethod = inputHandler.getEnumInput<SortMethod>(1,6);

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
                                    vecIntSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;

                                }
                                    break;
                                case QUICKSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<int, QuickSort<int>> sortHandler(vecInt);
                                    // Sort the data
                                    sortHandler.sort(PivotChoice::RIGHT);
                                    vecIntSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case MERGESORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<int, MergeSort<int>> sortHandler(vecInt);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecIntSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case HEAPSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<int, HeapSort<int>> sortHandler(vecInt);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecIntSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case INSERTIONSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<int, InsertionSort<int>> sortHandler(vecInt);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecIntSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case SHELLSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<int, ShellSort<int>> sortHandler(vecInt);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecIntSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                            }
                            std::cout << "Vector after sorting:\n";
                            printVector.print(vecIntSorted);

                            // Check if sorted
                            if (testSorting.isSorted(vecIntSorted)) {
                                std::cout << "!!!Vector is sorted.!!!\n";
                            } else {
                                std::cout << "!!!Vector is not sorted.!!!\n";
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
                                    vecFloatSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case QUICKSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<float, QuickSort<float>> sortHandler(vecFloat);
                                    // Sort the data
                                    sortHandler.sort(PivotChoice::RIGHT);
                                    vecFloatSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case MERGESORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<float, MergeSort<float>> sortHandler(vecFloat);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecFloatSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case HEAPSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<float, HeapSort<float>> sortHandler(vecFloat);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecFloatSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case INSERTIONSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<float, InsertionSort<float>> sortHandler(vecFloat);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecFloatSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case SHELLSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<float, ShellSort<float>> sortHandler(vecFloat);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecFloatSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                            }

                            std::cout << "Vector after sorting:\n";
                            printVector.print(vecFloatSorted);

                            // Check if sorted
                            if (testSorting.isSorted(vecFloat)) {
                                std::cout << "!!!Vector is sorted.!!!\n";
                            } else {
                                std::cout << "!!!Vector is not sorted.!!!\n";
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
                                    vecCharSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case QUICKSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<char, QuickSort<char>> sortHandler(vecChar);
                                    // Sort the data
                                    sortHandler.sort(PivotChoice::RIGHT);
                                    vecCharSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case MERGESORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<char, MergeSort<char>> sortHandler(vecChar);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecCharSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case HEAPSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<char, HeapSort<char>> sortHandler(vecChar);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecCharSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case INSERTIONSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<char, InsertionSort<char>> sortHandler(vecChar);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecCharSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                                case SHELLSORT: {
                                    // Create an instance of SortHandler with QuickSort as the sorting algorithm
                                    SortHandler<char, ShellSort<char>> sortHandler(vecChar);
                                    // Sort the data
                                    sortHandler.sort();
                                    vecCharSorted = sortHandler.getData();
                                    // Print the execution time
                                    std::cout << "------------------------------" << std::endl;
                                    std::cout << "Execution time: " << sortHandler.getExecutionTime().count() << " milliseconds\n";
                                    std::cout << "------------------------------" << std::endl;                                }
                                    break;
                            }

                            std::cout << "Vector after sorting:\n";
                            printVector.print(vecCharSorted);

                            // Check if sorted
                            if (testSorting.isSorted(vecChar)) {
                                std::cout << "!!!Vector is sorted.!!!\n";
                            } else {
                                std::cout << "!!!Vector is not sorted.!!!\n";
                            }
                            break;
                    }
                }
                case DISPAYSORTEDARRAY: // Display sorted array
                    switch (dataType) {
                        case INT:
                            printVector.print(vecIntSorted);
                            break;
                        case FLOAT:
                            printVector.print(vecFloatSorted);
                            break;
                        case CHAR:
                            printVector.print(vecCharSorted);
                            break;
                    }
                    break;
                case RUNTESTS: // Run tests

                    std::cout << "Pass testing array size: ";
                    size = inputHandler.getEnumInput<int>(1,10000000);

                    std::cout << "Enter the number of times to test algorithm: ";
                    int n = inputHandler.getEnumInput<int>(1,10000000);

                    std::cout << "Select sort method:\n1. BubbleSort\n2. QuickSort\n3. MergeSort\n4. HeapSort\n5. InsertionSort\n6. ShellSort\n";
                    sortMethod = inputHandler.getEnumInput<SortMethod>(1,6);
                    switch (dataType) {
                        case INT:
                            testSorting.runTests<int>(sortMethod, size, n);
                            break;
                        case FLOAT:
                            testSorting.runTests<float>(sortMethod, size, n);
                            break;
                        case CHAR:
                            testSorting.runTests<char>(sortMethod, size, n);
                            break;
                    }
            }
        }

        std::cout << "Do you want to exit the program?\n1. Yes\n2. No\n";
        exitOption = inputHandler.getEnumInput<ExitOption>(1, 2);
        if(exitOption == YES) {
            break;
        }
    }
    return 0;
};