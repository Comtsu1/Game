#pragma once

#include "../Entity.hpp"

class Goblin : public Entity
{ 
    public:
        void damage(int d);
        void heal(int h);

        inline int getHealth() const {return this->m_health;}
};

