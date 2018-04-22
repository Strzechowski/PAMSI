#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
#include "Sorts.h"

using namespace std;

class Table
{
    public:
        /**
        Konstruktor inicjalizuje rozmiar tablicy
        */
        Table();
        virtual ~Table();

        /**
        Publiczna funkcja do przeprowadzania testów na tablicy
        */
        void testSort();

    private:
        int testAmount;

        /**
        Wypisuje elementy tablicy
        */
        void printArray(int arr[], int sizeOfArray);
        /**
        Wypelnia tablice elementami
        */
        int * createArray(int arr[], int sizeOfArray, double percentOfSort);
        /**
        Wykonuje pojedynczy test
        */
        void makeTestOnArray(int arr[], int sizeOfArray, int whichSort);
};

#endif // TABLE_H
