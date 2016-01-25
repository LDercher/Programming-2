/**
*	@file : Dice.h
*	@author :  John Gibbons
*	@date : 2014.01.29
*	Purpose: Header file of Dice Class. Used to emulate a dice with the number of sides given at construction time.
*/

#ifndef DICE_H
#define DICE_H


#include <cstdio> /** NULL */
#include <cstdlib> /** srand(), rand() */
#include <ctime> /** time() */
class dice
{
public:
/**
*  @pre None
*  @post Creates and initializes a Dice instance
*  @return Initialzed Dice with 6 sides
*/
dice();

/**
*  @pre numSides is 2 or greater
*  @post Creates and initializes a Dice instance
*  @return Initialzed Dice with m_numSides initialzed to numSides.
*/
dice(int numSides);

/**
*  @pre None
*  @post Creates and initializes a Dice instance
*  @return a pseudo-random number from 1 up and including and m_numSides
*/
int roll();

/**
*  @pre None
*  @post None
*  @return the value of m_numSides
*/
int getNumSides();

private:
int m_numSides;
};

#endif // DICE_H
