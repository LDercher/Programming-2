#include "cow.h"


Cow::Cow()
{
    m_name = "Cow";

    m_sound = "moo";

}

double Cow::getMilkProduced() const
{
    return m_milkProduced;
}

void Cow::setMilkProduced(double gallons)
{
    if (gallons > 0)
    {
        m_milkProduced = gallons;
    }
    else
    {
        m_milkProduced = 0;
    }
}
