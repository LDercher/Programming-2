#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H
#include"chicken.h"

class CyberChicken : public Chicken
{
public:

    /**
    * @pre none
    * @post Initializes a new Cow with m_name set to CyberChicken and m_sound set to "resistance is futile"
    * @return initialized Cow
    */
    CyberChicken();

    /**
    * @pre none
    * @post none
    * @return m_eggs
    */
    int getCyberEggs() const;

    /**
    * @pre none
    * @post none
    * @return Sets m_eggs for CybeChicken
    */
    void setCyberEggs(const int eggs);
};

#endif // CYBERCHICKEN_H
