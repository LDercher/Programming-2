#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"

class Cow : public FarmAnimal
{
protected:

    double m_milkProduced;

public:

    /**
    * @pre none
    * @post Initializes a new Cow with m_name set to Cow and m_sound set to moo
    * @return initialized Cow
    */
    Cow();

    /**
    * @pre none
    * @post none
    * @return The amount of m_milkProduced
    */
    double getMilkProduced() const;

    /**
    * @pre none
    * @post if gallons is greater than 0 set m_milkProduced to gallons, otherwise set to zero.
    * @return none
    */
    void setMilkProduced(double gallons);

};

#endif // COW_H
