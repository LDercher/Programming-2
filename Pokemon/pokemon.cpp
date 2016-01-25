/**
*	@file : Pokemon.cpp
*	@author :  Luke Dercher
*	@date : 2015.02.01
*	Purpose:  implementation of Pokemon Class.
*/

#include "pokemon.h"
#include <string>


pokemon::pokemon()
{
 m_hp = 0;

 m_attacklevel = 0;

 m_defenselevel = 0;

 std::string m_name = "";
}



void pokemon::ReduceHP(int amount)
{
   m_hp = m_hp - amount;
}


int pokemon::getHP() const
{
  return m_hp;
}

int pokemon::getAttackLevel() const
{
  return m_attacklevel;
}


int pokemon::getDefenseLevel() const
{
 return m_defenselevel;
}


std::string pokemon::getName() const
{
 return m_name;
}


void pokemon::SetHP (int HPAmnt)
{
 m_hp = HPAmnt;
}


void pokemon::setAttackLevel (int AttckAmt)
{
 m_attacklevel = AttckAmt;
}

void pokemon::setDefenseLevel (int Dfnslvl)
{
 m_defenselevel = Dfnslvl;
}


 void pokemon::SetName (std::string pokename)
{
 m_name = pokename;
}




