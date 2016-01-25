/**
*	@file : numberfilegenerator.h
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: Number file generator header file. Number file generator creates a new file and fills it with integers in random, aescedning, descending order or filled with a single int.
*/


#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <chrono>

class NumberFileGenerator
{
public:


    /**
    * @pre filename is a valid path/filename. Amount is greater than zero
    * @post A file is created with the specified amount of numbers placed in ascending order. The amount of numbers in the file is the first entry in the file.
    */
    static void ascending(std::string fileName, int amount);

    /**
    * @pre filename is a valid path/filename. Amount is greater than zero
    * @post A file is created with the specified amount of numbers placed in descending order. The amount of numbers in the file is the first entry in the file.
    */
    static void descending(std::string fileName, int amount);

    /**
    * @pre filename is a valid path/filename. Amount is greater than zero
    * @post A file is created with the specified amount of numbers placed in random order. The amount of numbers in the file is the first entry in the file.
    */
    static void random(std::string fileName, int amount, int min, int max);


    /**
    * @pre filename is a valid path/filename. Amount is greater than zero
    * @post A file is created with a single number, specified by value, amount of times . The amount of numbers in the file is the first entry in the file.
    */
    static void singleValue(std::string fileName, int amount, int value);
};

#endif // NUMBERFILEGENERATOR_H
