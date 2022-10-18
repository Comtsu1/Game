#include "Item.h"
#include <string>

Item::Item(std::string name, int id, int damage)
    :m_name(name), m_id(id), m_damage(damage)
{

}

int Item::getID() const
{
    return m_id;
}

std::string Item::getName() const
{
    return m_name;
}

int Item::getDamage() const
{
    return m_damage;
}

bool Item::isFree() const
{
    return m_id == -1;
}

bool Item::operator==(const Item& item) const
{
    return this->getID() == item.getID();
}