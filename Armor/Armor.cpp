#include "Armor.hpp"
#include "../Item/Item.h"

#include "../ItemList.h"
#include <cstddef>
#include <memory>

Armor::Armor()
    :Item(NULL_ITEM), m_protection(0)
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
