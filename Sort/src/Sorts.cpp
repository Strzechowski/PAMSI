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
    quickSort(arr, 0, arrSize-1);
}


void Sorts::quickSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int pivot = partitioning(arr, first, last);
        quickSort(arr, first, pivot);
        quickSort(arr, pivot + 1, last);
    }
}


int Sorts::partitioning(int arr[], int first, int last)
{
    //Przyjmujemy pierwwszy element jako os
    //wzgledem niego bedziemy dzielic tablice na mniejsze i wieksze elementy
    int pivot = arr[first];
    //Bedziemy iterowac po tablicy od dwoch stron
    int i = first;
    int j = last;
    while (true)
    {
        while (arr[j] > pivot)
            j--;
        while (arr[i] < pivot)
            i++;

        if (i >= j)
            return j;

        swapValues(arr,i,j);
        i++;
        j--;
    }
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
        //cout << "HALOO" << endl;
    }
}


void Sorts::merging(int arr[], int first, int middle, int last)
{
    int mergedIndex, leftIndex, rightIndex;

    //deklaracja tymczasowej tablicy i jej wypelnienie
    int* tempArray=new int[last+1];

    for (leftIndex = first; leftIndex <= last; leftIndex++)
    {
        tempArray[leftIndex] = arr[leftIndex];
    }

    leftIndex = first;
    rightIndex = middle + 1;
    mergedIndex = first;
    while(leftIndex <= middle && rightIndex <= last)
    {
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
    delete[] tempArray;
}


void Sorts::insertionSort(int arr[], int arrSize)
{
    int i,j;
    int temp;
    for (i=1; i<arrSize; ++i)
    {
        temp=arr[i];
        for(j=i; j > 0 && temp < arr[j-1]; --j)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
}
void insertionSort(int arr[], int arrSize);void insertionSort(int arr[], int arrSize);


void Sorts::heapSort(int arr[], int arrSize)
{
    int i;
    //Najpierw tworzymy kopiec
    for(i=arrSize/2; i>0; --i)
        heapify(arr-1, i, arrSize);
    for(i=arrSize-1; i>0; --i)
    {
        //przestawiawmy korzen z 0 na ostatnia pozycje
        swapValues(arr,0,i);
        //znajdujemy nowy korzen na zmniejszonej tablicy
        heapify(arr-1, 1, i);
    }
}


void Sorts::heapify(int arr[], int rootIndex, int heapSize)
{
    int i,j;
    i = rootIndex;
    while(i<=heapSize/2)
    {
        j=2*i;
        if(j+1<=heapSize && arr[j+1]>arr[j])
            j=j+1;
        if(arr[i]<arr[j])
        {
            swapValues(arr,i,j);
        }
        else break;
        i=j;
    }
}


void Sorts::swapValues(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void Sorts::introspectiveSort(int arr[], int arrSize)
{
    introSort(arr,arrSize,(int)floor(2*log(arrSize)/log(2)));
    insertionSort(arr,arrSize);
}


void Sorts::introSort(int arr[], int arrSize, int depth)
{
    int i;
    if (depth<=0)
    {
        heapSort(arr,arrSize);
        return;
    }
    i=partitioning(arr,0,arrSize-1);
    if (i>9)
        introSort(arr,i,depth-1);
    if (arrSize-1-i>9)
        introSort(arr+i+1,arrSize-1-i,depth-1);
}
