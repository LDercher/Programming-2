/**
*	@file : numberfiledriver.h
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: Number file driver header file. Number file driver checks whether the user is entering valid input in the command line to run the number file generator and then runs the numberfilegenerator method specified by the user.
*/

#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H

#include "numberfilegenerator.h"

class NumberFileDriver
{
public:


    /**
    * @pre arguments is a valid 2-d array and the arguments conatined within are valid
    * @post If the arguments are valid, a number file is created following those specifications. Otherwise the help menu is created and no files are created.
    */
    static void run(int argc, char** argv);


    /**
    * @post Prints a help menu with instructions on how to use the number file generator
    */
    static void printHelpMenu();

private:

    /**
    * @post prints a help menu showing the valid options that can be passed into it if a valid option isn't passed in.
    * @return true is a valid option is passed in.
    */
    static bool isValidOption(std::string option);
};

#endif // NUMBERFILEDRIVER_H
