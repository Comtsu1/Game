#include "Entity.hpp"
#include "Inventory.hpp"
#pragma once



class Player : public Entity
{
    int m_waterlevel;
    int m_foodlevel;
    
    Invetory m_inv;

    public:
        Player();
        Player(int h, int wl, int fl);
        void virtual damage(int h);
        int virtual getHealth() const;
        Invetory& getInvetory();
};

