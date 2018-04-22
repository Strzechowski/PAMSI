#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <math.h>

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
        /**
        Funkcja wywolujaca sortowanie przez wstawianie
        */
        void insertionSort(int arr[], int arrSize);
        /**
        Funkcja wywolujaca sortowanie przez kopcowanie
        */
        void heapSort(int arr[], int arrSize);
        /**
        Funkcja do wywolania sortowania introspektywnego
        */
        void introspectiveSort(int arr[], int arrSize);
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
        /**
        Funkcja sluzy do tworzenia kopca
        */
        void heapify(int arr[], int rootIndex, int heapSize);

        /**
        Funkcja zamienia miejscami wartosci tablicy o podanych indeksach
        */
        void swapValues(int arr[], int i, int j);
        /**
        Funkcja decyduje jakiego sortowanie uzyc w sortowaniu hybrydowym
        */
        void introSort(int arr[], int arrSize, int depth);
};

#endif // SORTS_H
