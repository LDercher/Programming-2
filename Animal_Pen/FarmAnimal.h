/**
*	@file : FarmAnimal.h
*	@author: Luke Dercher
*	@date: 2015.03.22
*	@purpose: FarmAnimal class. Will be used as a generic class which other specific types of farm animals will be derived from.
*/

#ifndef FARMANIMAL_H
#define FARMANIMAL_H
#include<string>


class FarmAnimal
{
protected:

    std::string m_name;

    std::string m_sound;

public:

    /**
    *  @pre None
    *  @post Creates and initializes a FarmAnimal object with the strings m_name and m_sound initialized to the string "unset"
    *  @return Initialzed FarmAnimal
    */
    FarmAnimal();

    /**
    *  @pre A FarmAnimal object has been initialized
    *  @post none
    *  @return The string value for m_name for the FarmAnimal object
    */
    std::string getName() const;

    /**
    *  @pre A FarmAnimal object has been initialized
    *  @post sets the m_name value for the FarmAnimal
    *  @return none
    */
    void setName(std::string name);

    /**
    *  @pre A FarmAnimal object has been initialized
    *  @post none
    *  @return The string value for m_sound for the FarmAnimal object
    */
    std::string getSound() const;

    /**
    *  @pre A FarmAnimal object has been initialized
    *  @post sets the m_sound value for the FarmAnimal
    *  @return none
    */
    void setSound(std::string sound);



};

#endif // FARMANIMAL_H
