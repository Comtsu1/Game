#include "Armor.hpp"

Armor::Armor()
{

}

Armor::Armor(Item item)
    :m_name(item.getName()), m_id(item.getID()), m_damage(item.getDamage())
{

}

void Armor::getProtection() const
{
    return m_protection;
}

int Armor::setProtection(int protection)
{
    m_protection = protection;
}