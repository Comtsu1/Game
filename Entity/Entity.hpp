#pragma once

#include <cstdlib>

#include "../Item.h"

class Entity
{
    protected:
        int m_health;
    public:
        Entity(int h): m_health(h) {};

        inline virtual void damage(int d) {m_health-=d;}
        inline virtual void heal(int d) { m_health+=d;}

        inline virtual void attack(Entity *entity, Item item)
        {
            entity->damage(item.getDamage());
        }

        int virtual getHealth() const {return m_health;}


};
