/**
*	@file : sortdriver.h
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: sortdriver header file. Sortdriver checks whether a valid file passed in to sort and creates an array filled with those values in that file.
*/


#ifndef SORTDRIVER_H
#define SORTDRIVER_H

#include "sorts.h"
#include <iostream>
#include <fstream>


class SortDriver
{
public:

    /**
    * @pre arguments is a valid 2-d array and the arguments conatined within are valid
    * @post If the arguments are valid, a file is createdx containing the timing information of the chosen sort(s) on the supplied file. Otherwise the help menu is created and no files are created.
    */
    static void run(int argc, char** argv);

    /**
    * @post prints a help menu with directions on how to use the sort driver
    */
    static void printHelpMenu();

//private:

    /**
    * @pre The input file was created by the numberfilegenerator.
    * @return true if the file exists, false otherwise
    */
    static bool isFileAccessible(std::string fileName);

    /**
    * @return True if the sort parameter matches a valid one
    */
    static bool isSortValid(std::string sortParameter);

    /**
    * @return true is the file specifsied by filename exists and the sort parameter is valid, false otherwise.
    */
    static bool areParametersValid(std::string sortName, std::string inputFileName);

    /**
    * @pre The input file was  created with the number file generator.
    * @post The first line of the file was read in, containing the count.
    * @return How many numbers are in the file.
    */
    static int getFileCount(std::ifstream& inputFile);

    /**
    * @pre The input file was created with the number file generator, the (correct) size size was read in.
    * @post The remainder of the input file numbers are read in. The file is NOT closed.
    * @return A pointer to the first value in the array.
    */
    static int* createArray(std::ifstream& inputFile, int size);

    /**
    * @pre original and copy are valid arrays of the correct size.
    * @post All values from the original arraqy are copied into the copy array.
    */
    static void copyArray(int original[], int copy[], int size);

};

#endif // SORTDRIVER_H
