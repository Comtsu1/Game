#pragma once

#include <cstdlib>
#include <memory>
#include <string>

#include "../Item/Item.h"
#include "../Item/Armor/ArmorSet/ArmorSet.hpp"

#include "BodyParts/BodyPart.h"

class Entity
{
    private:
        // TODO improve m_health 
        double m_health;

        ArmorSet m_armorset;
    public:
        Entity();
        Entity(int h);

        virtual bool isDead() = 0;

        std::string virtual status() = 0;

        void virtual damagePart(BodyPart* part, int amount) = 0;

        virtual void damage(double amount);
        virtual void heal(double amount);

        virtual ArmorSet getArmor() const;
        virtual void setArmor(ArmorSet set);

        virtual void attack(Entity *entity, std::unique_ptr<Item> item);
        virtual void attack(Entity *entity, Item* item);

        virtual std::string getVisualAttributes() const;

        double virtual getHealth() const;


};
