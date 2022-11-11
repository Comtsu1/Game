#pragma once

#include <cstdlib>
#include <memory>

#include "../Item/Item.h"
#include "../Item/Armor/ArmorSet/ArmorSet.hpp"

class Entity
{
    private:
        double m_health;

        int m_foodlevel;
        int m_waterlevel;

        ArmorSet m_armorset;
    public:
        Entity(int h) :m_health(h), 
                        m_foodlevel(100),
                        m_waterlevel(100){};
        Entity(int h, int food, int water): m_health(h),
                                            m_foodlevel(food),
                                            m_waterlevel(water){};

        int getFood() const
        {
            return this->m_foodlevel;
        }

        int getWater() const
        {
            return this->m_waterlevel;
        }

        inline virtual void damage(double amount) {m_health-=amount;}
        inline virtual void heal(double amount) { m_health+=amount;}

        inline virtual ArmorSet getArmor() const {return m_armorset;}
        inline virtual void setArmor(ArmorSet set) {m_armorset = set;}

        virtual void attack(Entity *entity, std::unique_ptr<Item> item)
        {
            entity->damage(item->getDamage() - entity->getArmor().calculateProtection());
        }
        
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
