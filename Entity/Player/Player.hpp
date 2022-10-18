#pragma once

#include "../Entity.hpp"
#include "../../Inventory.hpp"



class Player : public Entity
{
    int m_waterlevel;
    int m_foodlevel;
    
    Invetory m_inv;

    public:
        Player();
        Player(int h, int wl, int fl);
        
        void adventure();

	void attack(Entity *player, int hp);

        Invetory& getInvetory();
};

