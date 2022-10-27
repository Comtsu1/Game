#pragma once

#include <cstdlib>

#include "../Item/Item.h"
#include "../Armor/ArmorSet/ArmorSet.hpp"

class Entity
{
    private:
        double m_health;
        ArmorSet m_armorset;
    public:
        Entity(int h): m_health(h) {};

        inline virtual void damage(double amount) {m_health-=amount;}
        inline virtual void heal(double amount) { m_health+=amount;}

        inline virtual ArmorSet getArmor() const {return m_armorset;}
        inline virtual void setArmor(ArmorSet set) {m_armorset = set;}

        virtual void attack(Entity *entity, Item* item)
        {
            entity->damage(item->getDamage() - entity->getArmor().calculateProtection());
        }

        inline virtual std::string getVisualAttributes() const
        {
            return m_armorset.getString();
        }

        double virtual getHealth() const {return m_health;}


};
