#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <math.h>

using namespace std;


template <class T>
class Sorts
{
    public:
        Sorts();
        virtual ~Sorts();
        /**
        Publiczna funkcja do wywolania sortowania przez scalanie
        */
        void mergeSort(T arr[], int arrSize);
        /**
        Publiczna funkcja do wywolania sortowania szybkiego
        */
        void quickSort(T arr[], int arrSize);
        /**
        Funkcja do wywolania sortowania introspektywnego
        */
        void introspectiveSort(T arr[], int arrSize);
    protected:

    private:
        /**
        Funkcja wywolujaca sortowanie przez wstawianie
        */
        void insertionSort(T arr[], int arrSize);
        /**
        Funkcja wywolujaca sortowanie przez kopcowanie
        */
        void heapSort(T arr[], int arrSize);
        /**
        Prywatna funkcja wykorzystujaca rekurencje do sortowania przez scalanie
        */
        void mergeSort(T arr[], int first, int last);
        /**
        Funkcja scala juz posorowane tablice
        */
        void merging(T arr[], int first, int middle, int last);
        /**
        Prywatna funkcja rekurencyjna do sortowania szybkiego
        */
        void quickSort(T arr[], int first, int last);
        /**
        Funkcja dzieli tablice na mniejsze i wieksze liczby wzgledem pierwszego elementu.
        (Potrzebne do quick-sorta)
        */
        T partitioning(T arr[], int first, int last);
        /**
        Funkcja sluzy do tworzenia kopca
        */
        void heapify(T arr[], int rootIndex, int heapSize);
        /**
        Funkcja zamienia miejscami wartosci tablicy o podanych indeksach
        */
        void swapValues(T arr[], int i, int j);
        /**
        Funkcja decyduje jakiego sortowanie uzyc w sortowaniu hybrydowym
        */
        void introSort(T arr[], int arrSize, int depth);

};

#endif // SORTS_H
