#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
#include "Sorts.h"

using namespace std;

template <class T>
class Table
{
    public:

        Table();
        virtual ~Table();
        /**
        Publiczna funkcja do przeprowadzania testów algorytmów
        */
        void testSort();

    private:
        /**
        Sprawdza czy tablica jest dobrze posortowana
        */
        void checkIfSortedGood(T arr[], int sizeOfArray);
        /**
        Wypisuje elementy tablicy
        */
        void printArray(T arr[], int sizeOfArray);
        /**
        Wypelnia tablice elementami
        */
        T * createArray(T arr[], int sizeOfArray, double percentOfSort);
        /**
        Wykonuje pojedynczy test
        */
        void makeTestOnArray(T arr[], int sizeOfArray, int whichSort);
};

#endif // TABLE_H
