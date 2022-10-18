#include "Player.hpp"
#include "../../Adventure.h"
#include "../Entity.hpp"
#include "../../Inventory.hpp"

Player::Player(int h, int wl, int fl)
    :Entity(h), m_waterlevel(wl), m_foodlevel(fl)
{
}

Player::Player()
    :Entity(100), m_waterlevel(100), m_foodlevel(100)
{
}

Invetory& Player::getInvetory() 
{
    return m_inv;
}

void Player::adventure()
{
    Adventure::generageAdventure(this);
}
