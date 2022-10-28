#include "Armor.hpp"

#include "../../ItemList.h"

Armor::Armor()
    :Item(NULL_ITEM->getName(),
            NULL_ITEM->getID(),
            NULL_ITEM->getDamage()),
    m_protection(0)
{

}

Armor::Armor(Item item, int protection)
    :Item(item), m_protection(protection)
{

}

int Armor::getProtection() const
{
    return m_protection;
}

void Armor::setProtection(int protection)
{
    m_protection = protection;
}
