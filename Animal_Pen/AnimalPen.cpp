/**
*	@file : animalpen.cpp
*	@author: Luke Dercher
*	@date: 2015.03.22
*	@purpose: Implementation of animalpen class
*/


#include "animalpen.h"


AnimalPen::AnimalPen()
{
}

AnimalPen::~AnimalPen()
{

    while (m_size!=0)
    {
        pop();
    }
}

void AnimalPen::addAnimal(FarmAnimal* animal)
{

    push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal()
{

    return(peek());


}

void AnimalPen::releaseAnimal()
{
   pop();
}


bool AnimalPen::isPenEmpty()
{
    return isEmpty();
}
