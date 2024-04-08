#ifndef AIZO_1_MENU_H
#define AIZO_1_MENU_H


//menu enums for the user to choose from
enum DataType { INT = 1, FLOAT = 2, CHAR = 3 };
enum SortMethod { BUBBLESORT = 1, QUICKSORT = 2, MERGESORT = 3, HEAPSORT = 4, INSERTIONSORT = 5, SHELLSORT = 6};
enum MenuOption { READFROMFILE = 1, GENERATERANDOM = 2, SAVEGENERATEDARRAYTOFILE = 3,  DISPLAYARRAY = 4, SORTARRAY = 5, DISPAYSORTEDARRAY = 6, RUNTESTS = 7, EXIT = 8};
enum ExitOption { YES = 1, NO = 2};
#endif //AIZO_1_MENU_H
