#pragma once

#include <cstdlib>

class Entity
{
    protected:
        int m_health;
    public:
        Entity(int h): m_health(h) {};

        inline virtual void damage(int d) {m_health-=d;}
        inline virtual void heal(int d) { m_health+=d;}

        inline virtual void attack(Entity *p, int hp)
        {
            if(rand() % 10 == 0)
                p->damage(2*hp);
            else
                p->damage(hp);
        }

        int virtual getHealth() const {return m_health;}


};
