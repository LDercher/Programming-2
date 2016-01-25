#ifndef CHICKEN_H
#define CHICKEN_H
#include"FarmAnimal.h"

class Chicken : public FarmAnimal
{
protected:

    int m_eggs;


    /**
    * @pre A Chicken has been initialized
    * @post none
    * @return int number of eggs
    */
    int getEggs() const;

    /**
    * @pre The value of int eggs is a positive number
    * @post sets m_eggs to eggs
    * @return none
    */
    void setEggs(int eggs);

public:

    /**
    * @pre none
    * @post Initializes a new Cow with m_name set to Chicken and m_sound set to Cluck
    * @return initialized Cow
    */
    Chicken();
};

#endif // CHICKEN_H
