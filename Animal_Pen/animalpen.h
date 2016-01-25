/**
*	@file : animalpen.h
*	@author: Luke Dercher
*	@date: 2015.03.22
*	@purpose: Specialized version of stack class made to store Farmanimal pointers
*/


#ifndef ANIMALPEN_H
#define ANIMALPEN_H
#include "stack.h"
#include "node.h"
#include "FarmAnimal.h"


class AnimalPen : public Stack<FarmAnimal*>
{
public:

    /**
    * @pre none
    * @post Initializes a new AnimalPen with m_size set to 0 and m_top set to nullptr
    * @return initialized stack
    */
    AnimalPen();

    /**
    * @pre An AnimalPen has been initialized and populated with FarmAnimals
    * @post Sends all of the FarmAnimals to be slaughetered
    * @return n/a
    */
    ~AnimalPen();

    /**
    * @pre none
    * @post pushes the animal pointer onto the stack or animal pen
    * @return n/a
    */
    void addAnimal (FarmAnimal* animal);

    /**
    * @pre none
    * @post none
    * @return A pointer to the next animal
    */
    FarmAnimal* peekAtNextAnimal ();

    /**
    * @pre Assumes the AnimalPen is not empty
    * @post Removes the animal at the top of the stack (AnimalPen)
    * @return none
    */
    void releaseAnimal();

    /**
    * @pre none
    * @post none
    * @return true if the animalpen has animals in it, false if not
    */
    bool isPenEmpty();
};

#endif // ANIMALPEN_H
