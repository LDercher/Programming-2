/**
*	@file : Colosseum.h
*	@author :  Luke Dercher
*	@date : 2015.02.01
*	Purpose:  Class designed to handle the building, attack, and gameplay of Pokemon type.
*/

#ifndef COLOSSEUM_H
#define COLOSSEUM_H
#include "pokemon.h"
#include "dice.h"

class colosseum
{
private:
    dice D6;

    dice D20;

    dice D2;

public:

    /**
    *  @pre two dice d6 and d20 have been created
    *  @post none
    *  @return Initialzes dice to appropriate sizes
    */
    colosseum();

    /**
    *  @pre There exists a type pokemon
    *  @post none
    *  @return sets values for name, hp, attacklevel, and defenselevel
    */
    void userBuild(pokemon& p);

    /**
    *  @pre there exists two pokemon
    *  @post none
    *  @return calculates attack and defense bonus. Determines if attack lands and how much damage it does. Displays info about the attack. Determines if a player has died.
    */
    bool attack (const pokemon& attacker, pokemon& defender);

    /**
    *  @pre None
    *  @post Creates and initializes a Pokemon
    *  @return Handles the 10 round fight between pokemon. uses a 2 sided die to determine who goes first/ displays round info and calls attack() to display attack info. Determines when the game is over.
    */
    void play (pokemon& p1, pokemon& p2);


};

#endif // COLOSSEUM_H
