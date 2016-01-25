/**
*	@file : main.cpp
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: Main used to run number driver or sortdriver
*/


#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include "sorts.h"
#include "numberfiledriver.h"
#include "numberfilegenerator.h"
#include "sortdriver.h"





int main(int argc, char** argv)
{


if (argc > 4)
{
    std::string mode = argv[1];

    if(mode == "-create")
    {
        NumberFileDriver::run(argc, argv);
    }
    else if (mode == "-sort")
    {
      SortDriver::run(argc, argv);
    }

}
else
{
    NumberFileDriver::printHelpMenu();

    SortDriver::printHelpMenu();

}

return 0;
}
