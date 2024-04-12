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
    ExitOption exitOption = NO;
    int size;
    SortMethod sortMethod;
    MenuOption menuOption;
    MainMenuOption mainMenuOption;

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

    PivotChoice pivotChoice;

    // Main menu
    while (true) {
        // Select data type
        std::cout << "Select mode:\n1. Normal\n2. Run tests\n3 Exit\n";
        mainMenuOption = inputHandler.getEnumInput<MainMenuOption>(1,3);

        switch (mainMenuOption) {
            case NORMAL_MENU:
                std::cout << "Select data type:\n1. Int\n2. Float\n3. Char\n";
                dataType = inputHandler.getEnumInput<DataType>(1,3);
                while(menuOption != EXIT) {
                    std::cout << "Select:\n1. Read from file\n2. Generate random array\n3. Save Generate random array to file\n4. Display array\n5. Sort array\n6. Display sorted array\n7. Back to main manu\n";
                    menuOption = inputHandler.getEnumInput<MenuOption>(1,7);

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
                                            std::cout << "Select pivot point:\n1. Left\n2. Right\n3. Middle\n4. Random\n";
                                            pivotChoice = inputHandler.getEnumInput<PivotChoice>(1,4);
                                            sortHandler.sort(pivotChoice);
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
                                            // Sort the data
                                            std::cout << "Select pivot point:\n1. Left\n2. Right\n3. Middle\n4. Random\n";
                                            pivotChoice = inputHandler.getEnumInput<PivotChoice>(1,4);
                                            sortHandler.sort(pivotChoice);
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
                                    if (testSorting.isSorted(vecFloatSorted)) {
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

                                            // Sort the data
                                            std::cout << "Select pivot point:\n1. Left\n2. Right\n3. Middle\n4. Random\n";
                                            pivotChoice = inputHandler.getEnumInput<PivotChoice>(1,4);
                                            sortHandler.sort(pivotChoice);
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
                                    if (testSorting.isSorted(vecCharSorted)) {
                                        std::cout << "!!!Vector is sorted.!!!\n";
                                    } else {
                                        std::cout << "!!!Vector is not sorted.!!!\n";
                                    }
                                    break;
                            }
                            break;
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
                        case EXIT:
                            break;
                    }
                }
                break;
            case RUNTESTS_MENU:
            {

                std::cout << "Select dta types separated by comma (1-6) where:\n1. Int\n2. Float\n3. Char\n";
                std::vector<DataType> dataTypes = inputHandler.getEnumsInput<DataType>(1, 3);

                std::cout << "Select sort methods separated by comma (1-6) where:\n1. BubbleSort\n2. QuickSort\n3. MergeSort\n4. HeapSort\n5. InsertionSort\n6. ShellSort:\n";
                std::vector<SortMethod> sortMethods = inputHandler.getEnumsInput<SortMethod>(1, 6);

                std::cout << "Select vector types separated by comma (1-5) where:\n1. Random\n2. Ascending\n3. Descending\n4. Sorted33\n5. Sorted66\n";
                std::vector<VectorTypes> vectorTypes = inputHandler.getEnumsInput<VectorTypes>(1, 5);

                std::cout << "Enter the size of array to test algorithm (1-10000000)\n";
                std::vector<int> sizes = inputHandler.getEnumsInput<int>(1, 10000000);

                std::cout << "Enter the number of times to test algorithm: ";
                int repetitions = inputHandler.getEnumInput<int>(1,200);

                std::cout << "------------------------------START" << std::endl;
                for (DataType dataType: dataTypes) {
                    for (int size : sizes) {
                        for (VectorTypes vectorType: vectorTypes) {
                            switch (dataType) {
                                case INT: {
                                    vecInt = generatorInt.generateVector(vectorType, size);
                                    break;
                                }
                                case FLOAT: {
                                    vecFloat = generatorFloat.generateVector(vectorType, size);
                                    break;
                                }
                                case CHAR: {
                                    vecChar = generatorChar.generateVector(vectorType, size);
                                    break;
                                }
                            }
                            for (SortMethod sortMethod: sortMethods) {
                                auto start = std::chrono::high_resolution_clock::now();
                                switch (dataType) {
                                    case INT:
                                        testSorting.runTests<int>(sortMethod, vectorType, vecInt, size, repetitions);
                                        break;
                                    case FLOAT:
                                        testSorting.runTests<float>(sortMethod, vectorType, vecFloat, size, repetitions);
                                        break;
                                    case CHAR:
                                        testSorting.runTests<char>(sortMethod, vectorType, vecChar, size, repetitions);
                                        break;
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                std::chrono::duration<float, std::milli> duration = end - start;
                                std::cout << "------------------------------" << duration << std::endl;
                            }
                        }
                    }
                }
                std::cout << "------------------------------END" << std::endl;
            }
                break;
            case EXIT_MENU:
                return 0;
        }
    }
}