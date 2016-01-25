/**
*	@file : sorts.h
*	@author: Luke Dercher
*	@date: 2015.03.27
*	@purpose: Header file for class containing various methods of sorting arrays
*/

#include <iostream>
#include <random>
#include <ctime>
#include <cassert>

#ifndef SORTS_H
#define SORTS_H

template <typename T>

class Sorts
{
public:

    /**
    * @pre An array is instantiated and filled with values that can be placed in ascending order i.e not chars or strings
    * @post sorts the values in the array in ascending order.
    */
    static void mergeSort(T arr[], int size);

    /**
    * @pre An array is instantiated and filled with values that can be placed in ascending order i.e not chars or strings
    * @post sorts the values in the array in ascending order.
    */
    static void quickSort(T arr[], int size);

    /**
    * @pre An array is instantiated and filled with values that can be placed in ascending order i.e not chars or strings
    * @post sorts the values in the array in ascending order.
    */
    static void bubbleSort (T arr[], int size);

    /**
    * @pre An array is instantiated and filled with values that can be placed in ascending order i.e not chars or strings
    * @post sorts the values in the array in ascending order.
    */
    static void bogoSort (T arr[], int size);

    /**
    * @pre An array is instantiated and filled with values that can be placed in ascending order i.e not chars or strings
    * @post sorts the values in the array in ascending order.
    */
    static void insertionSort (T arr[], int size);

    /**
    * @pre An array is instantiated and filled with values that can be placed in ascending order i.e not chars or strings
    * @post sorts the values in the array in ascending order.
    */
    static void selectionSort (T arr[], int size);

    /**
    * @pre An array is instantiated and filled with values that can be placed in ascending order i.e not chars or strings
    * @post sorts the values in the array in ascending order.
    * @return true if te array is sorted in asending order, otherwise false
    */
    static bool isSorted (T arr[], int size);

private:

    /**
    * @pre An array is instantiated and filled with values.
    * @post For each index in the array, swap it the value at another random index
    */
    static void shuffle (T arr[], int size, std::default_random_engine& generator);


    /**
    * @pre Two sorted arrays are passed in (actually just two halves of a single array)
    * @post merges the two sorted arrays into into one single sorted array..
    */
    static void merge(T* a1, T* a2, int size1, int size2);

};

#include "sorts.hpp"

#endif // SORTS_H
