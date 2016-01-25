/**
*	@file : Chicken.cpp
*	@author: Luke Dercher
*	@date: 2015.03.22
*	@purpose: Implementation of chicken class.
*/

#include "chicken.h"

Chicken::Chicken()
{
    m_name = "Chicken";

    m_sound = "Cluck";

}

int Chicken::getEggs() const
{
    return m_eggs;
}

void Chicken::setEggs(int eggs)
{
    m_eggs = eggs;
}
