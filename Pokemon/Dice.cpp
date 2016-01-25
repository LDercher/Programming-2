/**
*	@file : Dice.cpp
*	@author :  John Gibbons
*	@date : 2014.01.29
*	Purpose: Implementation of Dice Class
*/
#include "dice.h"

dice::dice()
{
    m_numSides = 6;
    /** initialize random seed: */
    srand (time(NULL));//Old C style NULL
}


dice::dice(int numSides)
{
    m_numSides = numSides;
    /** initialize random seed: */
    srand (time(NULL));//Old C style NULL
}


int dice::getNumSides()
{
    return(m_numSides);
}

int dice::roll()
{

    /** Get back a pseudo-random number */
    return(rand()%m_numSides + 1);
}
