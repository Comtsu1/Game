#include "Tool.h"

Tool::Tool()
{}

Tool::Tool(Item item, int durability)
    :Item(item), m_durability(durability)
{}

int Tool::getDurability() const
{
    return m_durability;
}

void Tool::reduceDurability(int amount)
{
    // based on enchantments
    m_durability -= amount;
}

void Tool::addDurability(int amount)
{
    m_durability += amount;
}

std::string Tool::show() const 
{
    return "Damage: " + std::to_string(this->getDamage())
        + "\nDurability: " + std::to_string(this->getDurability())
        + "\nID: " + std::to_string(this->getID())
        + "\n";
}