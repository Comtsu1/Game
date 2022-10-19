#pragma once

#include "../Entity.hpp"
#include "../../Inventory.hpp"
#include "../../Item/Item.h"


class Player : public Entity
{
    int m_waterlevel;
    int m_foodlevel;
    
    Invetory m_inv;

    public:
        Player();
        Player(double h, int wl, int fl);
        
        void adventure();

        Invetory& getInvetory();
};

