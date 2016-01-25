/**
*	@file : numberfilegenerator.cpp
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: Number file generator header implementation. Number file generator creates a new file and fills it with integers in random, aescedning, descending order or filled with a single int.
*/

#include "numberfilegenerator.h"



void NumberFileGenerator::ascending(std::string fileName, int amount)
{
    std::ofstream outfile(fileName);

    outfile<<amount<"\n\n";

    outfile<<"\n";

    for (int i = 1; i<=amount; i++)
    {
        outfile<<i<<"\n";
    }

    outfile.close();
}

void NumberFileGenerator::descending(std::string fileName, int amount)
{
    std::ofstream outfile(fileName);

    outfile<<amount<"\n\n";

    outfile<<"\n";

    for (int i = amount; i>=1; i--)
    {
        outfile<<i<<"\n";
    }

    outfile.close();
}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
    std::ofstream outfile(fileName);

    outfile<<amount<"\n\n";

    outfile<<"\n";

    std::default_random_engine generator(time(nullptr));

    std::uniform_int_distribution<int> distribution(min,max);

    int randNum = distribution(generator);

    for (int i=0; i<=amount; i++)
    {
        randNum = distribution(generator);

        outfile<<randNum<<"\n";
    }

    outfile.close();
}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{
    std::ofstream outfile(fileName);

    outfile<<amount<"\n\n";

    outfile<<"\n";

    for (int i = 1; i>amount; i--)
    {
        outfile<<value<<"\n";
    }

    outfile.close();

}
