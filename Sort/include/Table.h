#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
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
        void makeTestOnArray();

    private:
        int sizeOfArray;

        /**
        Wypisuje elementy tablicy
        */
        void printArray(int arr[]);
        /**
        Wypelnia tablice elementami
        */
        int * createArray(int arr[]);
};

#endif // TABLE_H
