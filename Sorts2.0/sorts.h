/**
*	@file : sorts.h
*	@author: Luke Dercher
*	@date: 2015.04.02
*	@purpose: Header file for class containing various methods of sorting arrays
*/

#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <random>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>

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
    * @post sorts the values in the array in ascending order. note: uses an additional setMedianPivot method to make quickSort more efficient
    */
    static void quickSortMedian(T arr[], int size);

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

    /**
    * @pre Array is a valid array of T values with size # of elements, and the < operator is overloaded fo T. Sort must be capable of sorting the values in ascending order.
    * @return The time it took to perform the sort.
    */
    static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);

private:

    /**
    * @pre An array is instantiated and filled with values.
    * @post For each index in the array, swap it the value at another random index
    */
    static void shuffle (T arr[], int size, std::default_random_engine& generator);

    /**
    * @pre Two sorted arrays are passed in
    * @post The two sorted arrays are combined into one single sorted array
    */
    static void merge(T* a1, T* a2, int size1, int size2);

    /**
    * @pre An array and the first and last index are passed in. Median is passed in as true or false to determine which value will be used all the pivot value
    * @post Sorts an array by partitioning everything in the array on the left and right side of a pivot value and then quicksorting eveything to the left of the pivot value
    */
    static void quickSortRec(T arr[], int first, int last, bool median);

    /**
    * @pre used by quickSort to parition the array
    * @post performs swaps so that everything less than the pivot value is moved to the right side of the array and vice versaa
    * @return the new pivot value after the partition business is carried out
    */
    static int partition(T arr[], int first, int last, bool median);

    /**
    * @pre finds the first, middle, and last values in the array. Finds the median of the three values
    * @post swaps the median value into the last index in the array if neccessary
    */
    static void setMedianPivot(T arr[], int first, int last);



};

#include "sorts.hpp"

#endif // SORTS_H
