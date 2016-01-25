/**
*	@file : main.cpp
*	@author: Luke Dercher
*	@date: 2015.03.27
*	@purpose: Main, used to create arrays filled with "randomly" generated ints and then sort them using the sort methods in the sort class.
*/

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include "sorts.h"


void printMenu()
{
    std::cout 	<< "\n\nSelect a sort:\n"
            << "1) Bubble Sort\n"
            << "2) Insertion Sort\n"
            << "3) Selection Sort\n"
            << "4) Bogo Sort (use only with very small arrays!)\n"
            << "Enter choice: ";
}

int* createRandomArray(int size, int min, int max)
{
    std::default_random_engine generator(time(nullptr));

    std::uniform_int_distribution<int> distribution(min,max);

    int* intArr = new int[size];

    int randNum = distribution(generator);

    for (int i=0; i<size; i++)
    {
        intArr[i] = randNum;

        randNum = distribution(generator);
    }

    return intArr;
}



int main()
{
   char quit = 'n';

   char print;

   int size, lowerBound, upperBound;

   int choice = 0;

   std::chrono::system_clock::time_point start;

   std::chrono::system_clock::time_point end;

   std::chrono::duration<double> elapsed;

   while (quit != 'y')
   {

       printMenu();

       std::cin>>choice;

       std::cout<<"Input a size for the random array \n";

       std::cin>>size;

       std::cout<<"Input a lower bound on the range of numbers:\n";

       std::cin>>lowerBound;

       std::cout<<"Input an upper bound on the range of random numbers: \n";

       std::cin>>upperBound;

       int* arr = createRandomArray(size, lowerBound, upperBound);

       std::cout<<"Do you want to print the unsorted array? (y/n) \n";

       std::cin>>print;

       if(print == 'y')
       {
           std::cout<<"Here is the unsorted array \n";

           std::cout<<"[";

           for (int i=0; i<size; i++)
           {
               std::cout<<arr[i];

               if (i<size-1)
               {
                   std::cout<<",";
               }
           }

           std::cout<<"]\n\n";

       }

       switch (choice)
       {
            case 1:

               std::cout<<"Sorting with bubble sort... \n";

               start = std::chrono::system_clock::now();

               Sorts<int>::bubbleSort(arr,size);

               end = std::chrono::system_clock::now();

               break;

            case 2:

               std::cout<<"Sorting with insertion sort... \n";

               start = std::chrono::system_clock::now();

               Sorts<int>::insertionSort(arr,size);

               end = std::chrono::system_clock::now();

               break;

            case 3:

               std::cout<<"Sorting with selection sort... \n";

               start = std::chrono::system_clock::now();

               Sorts<int>::selectionSort(arr,size);

               end = std::chrono::system_clock::now();

               break;

            default:

               std::cout<<"Sorting with bogo sort... \n";

               start = std::chrono::system_clock::now();

               Sorts<int>::bogoSort(arr,size);

               end = std::chrono::system_clock::now();

       }

       elapsed = (end - start);

       std::cout<<"Do you want to print the sorted array?\n";

       std::cin>>print;

       if (print == 'y')
       {
           std::cout<<"Here is the sorted array \n";

           std::cout<<"[";

           for (int i=0; i<size; i++)
           {
               std::cout<<arr[i];

               if (i<size-1)
               {
                   std::cout<<",";
               }
           }

           std::cout<<"] \n\n";
       }

       std::cout<<size<<" numbers where sorted in " << elapsed.count() <<" seconds \n\n";

       std::cout<<"Do you want to quit? (y/n):";

       std::cin>>quit;

       delete arr;

   }


    return 0;
}
