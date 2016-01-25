/**
*	@file : numberfiledriver.cpp
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: Implementation of numberfiledriver.
*/

#include "numberfiledriver.h"

void NumberFileDriver::run(int argc, char** argv)
{
    std::string option= argv[2];

    int amount = std::stoi(argv[4]);

    if (NumberFileDriver::isValidOption(option))
    {
        if (option == "-a")
        {
            std::string fileName = argv[3];

            NumberFileGenerator::ascending(fileName, amount);
        }
        else if (option == "-d")
        {
            std::string fileName = argv[3];

            NumberFileGenerator::descending(fileName, amount);
        }
        else if (option == "-s")
        {
            std::string fileName = argv[3];

            int value = std::stoi(argv[5]);

            NumberFileGenerator::singleValue(fileName, amount, value);
        }
        else if (option == "-r")
        {
            std::string fileName = argv[3];

            int min = std::stoi(argv[5]);

            int max = std::stoi(argv[6]);

            NumberFileGenerator::random(fileName, amount, min, max);
        }

    }
    else
    {
        printHelpMenu();
    }

}


bool NumberFileDriver::isValidOption(std::string option)
{
    if (option == "-a" || option == "-d" || option == "-s" || option == "-r" )
    {
        return true;
    }
    else
    {
        return false;
    }

}

void NumberFileDriver::printHelpMenu()
{
    std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
            << "./prog -create -a filename amount\n"
            << "./prog -create -d filename amount\n"
            << "./prog -create -s filename amount value\n"
            << "./prog -create -r filename amount min max\n"
            << "Option explainations:\n"
            << "\t-a for ascending\n"
            << "\t-d for descending\n"
            << "\t-s for a single value\n"
            << "\t-r for random values\n"
            << "\tfilename is the ouput file name\n"
            << "\tamount is the amount of random numbers to place in the file\n"
            << "\tvalue is the single number that will be written to file in -s mode\n"
            << "\tmin is the low end of the range of random numbers\n"
            << "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}
