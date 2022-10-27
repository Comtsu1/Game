#include "Tool.h"
#include <ios>
#include <string>

Tool::Tool()
{}

Tool::Tool(Item* item, int durability)
    :Item(item),
    m_durability(durability)
{}

int Tool::getDurability() const
{
    return m_durability;
}

void Tool::addDurability(int amount)
{
    m_durability += amount;
}

void Tool::reduceDurability(int amount)
{
    m_durability -= amount;
}

std::string Tool::show() const
{
    return "\tDamage: " + std::to_string(this->getDamage())
        + "\n\tDurability: " + std::to_string(m_durability)
        + "\n\tID: " + std::to_string(this->getID())
        + "\n";
}
