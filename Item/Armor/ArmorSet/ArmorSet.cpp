#include "ArmorSet.hpp"

ArmorSet::ArmorSet()
{

}

ArmorSet::ArmorSet(Armor helmet, Armor chest, Armor leggings, Armor boots)
    :m_helmet(helmet), m_chestplate(chest), m_leggings(leggings), m_boots(boots)
{

}

void ArmorSet::setArmor(ArmorSet set)
{
    m_helmet = set.getHelmet();
    m_chestplate = set.getChestPlate();
    m_leggings = set.getLeggings();
    m_boots = set.getBoots();
}

void ArmorSet::setHelmet(Armor helmet)
{
    m_helmet = helmet;
}

void ArmorSet::setChestPlate(Armor chest)
{
    m_chestplate = chest;
}

void ArmorSet::setLeggings(Armor leggings)
{
    m_leggings = leggings;
}

void ArmorSet::setBoots(Armor boots)
{
    m_boots = boots;
}

Armor ArmorSet::getHelmet() const
{
    return m_helmet;
}

Armor ArmorSet::getChestPlate() const
{
    return m_chestplate;
}

Armor ArmorSet::getLeggings() const
{
    return m_leggings;
}

Armor ArmorSet::getBoots() const
{
    return m_boots;
}

int ArmorSet::getTotalProtection() const
{
    return m_helmet.getProtection() + m_chestplate.getProtection() + m_leggings.getProtection() + m_boots.getProtection();
}

bool ArmorSet::isFree() const
{
    return m_helmet.isFree()
        && m_chestplate.isFree()
        && m_leggings.isFree()
        && m_boots.isFree();
}

std::string ArmorSet::getString() const 
{
    return m_helmet.getName()
        + ", "
        + m_chestplate.getName()
        + ", "
        + m_leggings.getName()
        + " and "
        + m_boots.getName();
}
