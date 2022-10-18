#pragma once

#include <cstdlib>

#include "../Item/Item.h"
#include "../Armor/ArmorSet/ArmorSet.hpp"

class Entity
{
    protected:
        int m_health;
        ArmorSet m_armorset;
    public:
        Entity(int h): m_health(h) {};

        inline virtual void damage(int amount) {m_health-=amount;}
        inline virtual void heal(int amount) { m_health+=amount;}

        inline virtual ArmorSet getArmor() const {return m_armorset;}
        inline virtual void setArmor(ArmorSet set) {m_armorset = set;}

        inline virtual void attack(Entity *entity, Item item)
        {
            entity->damage(item.getDamage() - entity->getArmor().calculateProtection());
        }

        int virtual getHealth() const {return m_health;}


};
