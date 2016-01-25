/**
*	@file : CyberChicken.cpp
*	@author: Luke Dercher
*	@date: 2015.03.22
*	@purpose: Implementation of cyberchicken class
*/


#include "cyberchicken.h"



CyberChicken::CyberChicken()
{
    m_name = "Cyber Chicken";

    m_sound = "Resistance is futile";
}

int CyberChicken::getCyberEggs() const
{
    return m_eggs;
}

void CyberChicken::setCyberEggs(const int eggs)
{
    m_eggs = eggs;
}
