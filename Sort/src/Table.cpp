#include "Table.h"

Table::Table()
{
    sizeOfArray = 10;
}

Table::~Table()
{
    //dtor
}

int * Table::createArray(int arr[])
{
    srand(time(0));
    for (int i=0; i<sizeOfArray; i++)
    {
        arr[i] = i;
    }

    random_shuffle(&arr[0], &arr[9]);
    return arr;
}


void Table::printArray(int arr[])
{
    for (int i=0; i<sizeOfArray; i++)
    {
        cout << arr[i] << endl;
    }
}

void Table::makeTestOnArray()
{
    Sorts sorts;
    int arr[sizeOfArray];

    createArray(arr);
    printArray(arr);
    sorts.mergeSort(arr, sizeOfArray);
    cout << "Po sortowaniu: " << endl;
    printArray(arr);
}
