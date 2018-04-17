#include "Sorts.h"

Sorts::Sorts()
{
    //ctor
}

Sorts::~Sorts()
{
    //dtor
}


void Sorts::quickSort(int arr[], int arrSize)
{

}

void Sorts::quickSort(int arr[], int first, int last)
{

}

int Sorts::partitioning(int arr[], int first, int last)
{

}

void Sorts::mergeSort(int arr[], int arrSize)
{
    mergeSort(arr, 0, arrSize-1);
}


void Sorts::mergeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int middle = ( first + last )/2;

        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merging(arr, first, middle, last);
    }
}

void Sorts::merging(int arr[], int first, int middle, int last)
{
    int mergedIndex, leftIndex, rightIndex;

    //deklaracja tymczasowej tablicy i jej wypelnienie
    int tempArray[last + 1];

    for (leftIndex = first; leftIndex <= last; leftIndex++)
    {
        tempArray[leftIndex] = arr[leftIndex];
    }

    leftIndex = first;
    rightIndex = middle + 1;
    mergedIndex = first;
    while(leftIndex <= middle && rightIndex <= last)
    {
        //  cout << "bylem" << endl;
        /*
        if (rightIndex == rightSize)
        {
            while(leftIndex < leftSize)
            {
                arr[mergedIndex]=leftArray[leftIndex];
                leftIndex++;
                mergedIndex++;
            }
            break;
        }
        if (leftIndex == leftSize)
        {
            while(rightIndex < rightSize)
            {
                arr[mergedIndex]=rightArray[rightIndex];
                rightIndex++;
                mergedIndex++;
        break;
        }*/

        if (tempArray[leftIndex] < tempArray[rightIndex])
        {
            arr[mergedIndex++] = tempArray[leftIndex++];
        }
        else
        {
            arr[mergedIndex++] = tempArray[rightIndex++];
        }
    }
    while(leftIndex <= middle)
    {
        arr[mergedIndex++] = tempArray[leftIndex++];
    }
}
