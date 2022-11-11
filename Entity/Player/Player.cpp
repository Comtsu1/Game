#include "Player.hpp"
#include "../../Adventure.h"
#include "../Entity.hpp"
#include "../../Inventory.hpp"

Player::Player(double h, int wl, int fl)
    :Entity(h, wl, fl)
{
}

Player::Player()
    :Entity(100)
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
