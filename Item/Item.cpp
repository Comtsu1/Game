#include "Item.h"
#include <string>

Item::Item()
    :m_name("You shouldn't have this, but ok..."), m_id(-1), m_damage(-69420)
{

}

Item::Item(std::string name, int id, int damage)
    :m_name(name), m_id(id), m_damage(damage)
{

}

Item::Item(Item* item)
    :m_name(item->getName()),
    m_id(item->getID()),
    m_damage(item->getDamage())
{
    delete item;
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

std::string Item::show() const
{
    return "\tDamage: " + std::to_string(m_damage)
        + "\n\tID: " + std::to_string(m_id)
        + "\n";
}
