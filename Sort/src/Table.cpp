#include "Table.h"


Table::Table()
{
    testAmount = 1;
}

Table::~Table()
{
    //dtor
}

int * Table::createArray(int arr[], int sizeOfArray, double percentOfSort)
{
    srand(time(0));
    for (int i=0; i < sizeOfArray; i++)
    {
        arr[i] = i;
    }

    if(percentOfSort == -1 )
    {
        //Odwrocona tablica
        reverse(arr, arr + sizeOfArray);
        cout << "Tablica posortowana w odwrotnej  kolejnosci " << endl;
    }
    else
    {
        int whereToStartShuffle = (percentOfSort * sizeOfArray) / 100;
        random_shuffle(&arr[whereToStartShuffle], &arr[sizeOfArray]);
        cout << percentOfSort << "% poczatkowych elementow posortowanych" << endl;
    }
    return arr;
}


void Table::printArray(int arr[], int sizeOfArray)
{
    for (int i=0; i<sizeOfArray; i++)
    {
        cout << arr[i] << endl;
    }
}

void Table::testSort()
{
    int sizeOfArray[] = {1000};
    double percentOfSort[] = {-1};

    for (int i = 0; i < testAmount; i++)
    {
        for (const auto j : percentOfSort)
        {
            //Tworzymy 3 tablice dla 3 sortowan
            int * mergeArray = new int[sizeOfArray[i]];
            int * quickArray = new int[sizeOfArray[i]];
            int * introArray = new int[sizeOfArray[i]];

            //Wypelniamy jedna i kopiujemy zawartosc do pozostalych
            createArray(mergeArray, sizeOfArray[i], j);
            copy(mergeArray, mergeArray + sizeOfArray[i], quickArray);
            copy(mergeArray, mergeArray + sizeOfArray[i], introArray);

            //Wykonujemy testy
            makeTestOnArray(mergeArray, sizeOfArray[i], 1);
            makeTestOnArray(quickArray, sizeOfArray[i], 2);
            makeTestOnArray(introArray, sizeOfArray[i], 3);
        }
    }
}


void Table::makeTestOnArray(int arr[], int sizeOfArray, int whichSort)
{
    Sorts sorts;

    //Zaczynamy pomiar czasu
    auto start = chrono::high_resolution_clock::now();

    //Wybieramy algorytm sortowania
    if (whichSort == 1)
    {
        cout << "dzialaaaa" << endl;
        sorts.mergeSort(arr, sizeOfArray);
        cout << "SORTOWANIE PRZEZ SCALANIE" << endl;
    }
    else if (whichSort == 2)
    {
        sorts.quickSort(arr, sizeOfArray);
        cout << "SORTOWANIE SZYBKIE" << endl;
    }
    else if (whichSort == 3)
    {
        sorts.introspectiveSort(arr, sizeOfArray);
        cout << "SORTOWANIE INTROSPEKTYWNE" << endl;
    }

    //Konczymy pomiar czasu
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = stop - start;


    cout << "Czas sortowania: " << elapsed.count() << " s\n";
    cout << " " << endl;
}
