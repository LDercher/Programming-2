/**
*	@file : sorts.hpp
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: Implementation of sorts class
*/

#include "sorts.h"


template <typename T>
double Sorts<T>::sortTimer(std::function<void (T[], int)> sort, T arr[], int size)
{
    std::chrono::system_clock::time_point start;

    std::chrono::system_clock::time_point end;

    std::chrono::duration<double> elapsed;

   start = std::chrono::system_clock::now();

   sort(arr,size);

   end = std::chrono::system_clock::now();

   elapsed = end-start;

   return elapsed.count();
}


template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
    int mid;

    mid = size/2;

    T* left= arr;

    T* right= arr + mid;

    if(size==0 || size==1)
    {
        return;
    }
    else
    {
        mergeSort(left,mid);

        mergeSort(right, size-mid);

        merge(left,right, mid, size-mid);

    }

    assert( Sorts<T>::isSorted(arr, size) );

}

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
    T* buffer = new T[size1+size2];

    int p = 0;

    int p1 = 0;

    int p2 = 0;

    while( p1<size1 && p2<size2)
    {
        if ( a1[p1] < a2[p2])
        {
            buffer[p] = a1[p1];

            p1++;
        }
        else
        {
            buffer[p] = a2[p2];

            p2++;
        }

         p++;

    }

    //copy remaining in a1

    while(p1<size1)
    {
        buffer[p]= a1[p1];

        p1++;

        p++;
    }

    while(p2<size2)
    {
        buffer[p]= a2[p2];

        p2++;

        p++;
    }



    //copy remaining in a2


    for(int i = 0; i<size1+size2; i++)
    {
            a1[i]= buffer[i];
    }
    delete[] buffer;
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
    bool median = false;

    quickSortRec(arr,0,size-1,median);

    assert( Sorts<T>::isSorted(arr, size) );

}

template <typename T>
void Sorts<T>::quickSortMedian(T arr[], int size)
{
    bool median = true;

    quickSortRec(arr,0,size-1,median);

    assert( Sorts<T>::isSorted(arr, size) );
}


template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{

    if (first<last)
    {
        int pivotIndex = partition(arr,first,last,median);
        quickSortRec(arr,first,pivotIndex-1,median);
        quickSortRec(arr,pivotIndex+1,last,median);
    }

}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
    if (median)
    {
        if ((last+1)>3)
        {
            setMedianPivot(arr, first, last);
        }

    }
        int pivot = arr[last];

        while (first<last)
        {
            while (arr[first]<pivot)
                first++;
            while (arr[last]>pivot)
                last--;
            if(arr[first]== arr[last])
            {
                first++;
            }
            else if (first<last)
            {
                int temp = arr[first];

                arr[first] = arr[last];

                arr[last] = temp;
            }

        }


    return last;
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
    T tempval;

    int mid = (last+first)/2;

    T temp [] = {arr[first], arr[mid], arr[last]};

    selectionSort(temp, 3);

    if(temp[1]==arr[first])
    {
        tempval = arr[last];

        arr[last] = arr[first]; //first at the end

        arr[first] = tempval;
    }
    else if (temp[1]==arr[mid])
    {
        tempval = arr[last];

        arr[last] = arr[mid];  //middle at the end

        arr[last] = tempval;

    }
}


template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    T temp;

        for (int j=0; j<size; j++)
        {
            for (int i=0; i< size-1; i++)
            {
                if (arr[i] > arr[i+1])
                {
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;

                }
            }

        }

    assert( Sorts<T>::isSorted(arr, size) );

}


template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
    int i, j ,tmp;

    for (i = 1; i < size; i++)
    {
     j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
     }
   assert( Sorts<T>::isSorted(arr, size) );

}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{

    int i, j, minIndex;

    T temp, min;

    for (i=0; i<size; i++)
    {
        minIndex = i;

        min = arr[i];

        for (j=i; j<size; j++)
        {
            if (min>arr[j])
            {
                minIndex = j;

                min = arr[j];

            }
        }

        temp = arr[i];

        arr[i] = arr[minIndex];

        arr[minIndex] = temp;
    }

    assert( Sorts<T>::isSorted(arr, size) );
}


template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        if (arr[i]>arr[i+1])
        {
            return false;
        }
    }
    return true;

}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
    std::uniform_int_distribution<int> distribution(0,size);

    int randNum;

    T temp;

    for (int i=0; i<size; i++)
    {
        randNum = distribution(generator);

        temp = arr[i];

        arr[i] = arr[randNum];

        arr[randNum] = temp;


    }

}
