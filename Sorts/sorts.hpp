/**
*	@file : sorts.hpp
*	@author: Luke Dercher
*	@date: 2015.03.27
*	@purpose: Implementation for class containing various methods of sorting arrays
*/

#include "sorts.h"



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
void Sorts<T>::bogoSort(T arr[], int size)
{
    std::default_random_engine generator(time(nullptr));

    while (!isSorted(arr,size))
    {
        shuffle(arr,size,generator);
    }

    assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
   T temp;

    for (int i=1; i<size; i++)
   {
       for (int j=i; j>=0; j--)
       {
           if (arr[j] < arr[j-1])
           {
               temp = arr[j];
               arr[j] = arr[j-1];
               arr[j-1] = temp;
           }
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
