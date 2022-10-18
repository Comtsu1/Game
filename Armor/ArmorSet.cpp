#include "ArmorSet.hpp"

ArmorSet::ArmorSet()
{

}

ArmorSet::ArmorSet(Slot helmet, Slot chest, Slot leggings, Slot boots)
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

void ArmorSet::setHelmet(Slot helmet)
{
    m_helmet = helmet;
}

void ArmorSet::setChestPlate(Slot chest)
{
    m_chestplate = chest;
}

void ArmorSet::setLeggings(Slot leggings)
{
    m_leggings = leggings;
}

void ArmorSet::setBoots(Slot boots)
{
    m_boots = boots;
}

Slot ArmorSet::getHelmet() const
{
    return m_helmet;
}

Slot ArmorSet::getChestPlate() const
{
    return m_chestplate;
}

Slot ArmorSet::getLeggings() const
{
    return m_leggings;
}

Slot ArmorSet::getBoots() const
{
    return m_boots;
}

