#ifndef SORTS_H
#define SORTS_H
#include <iostream>

using namespace std;

class Sorts
{
    public:
        Sorts();
        virtual ~Sorts();
        /**
        Publiczna funkcja do wywolania sortowania przez scalanie
        */
        void mergeSort(int arr[], int arrSize);
        /**
        Publiczna funkcja do wywolania sortowania szybkiego
        */
        void quickSort(int arr[], int arrSize);
    protected:

    private:
        /**
        Prywatna funkcja wykorzystujaca rekurencje do sortowania przez scalanie
        */
        void mergeSort(int arr[], int first, int last);
        /**
        Funkcja scala juz posorowane tablice
        */
        void merging(int arr[], int first, int middle, int last);
        /**
        Prywatna funkcja rekurencyjna do sortowania szybkiego
        */
        void quickSort(int arr[], int first, int last);
        /**
        Funkcja dzieli tablice na mniejsze i wieksze liczby wzgledem ostatniego elementu.
        (Potrzebne do quick-sorta)
        */
        int partitioning(int arr[], int first, int last);

};

#endif // SORTS_H
