#include "Player.hpp"
#include "Entity.hpp"
#include "Inventory.hpp"

Player::Player(int h, int wl, int fl)
    :Entity(h), m_waterlevel(wl), m_foodlevel(fl)
{
}

Player::Player()
    :Entity(100), m_waterlevel(100), m_foodlevel(100)
{

}

void Player::damage(int h)
{
    m_health -= h;
}

int Player::getHealth() const
{
    return m_health;
}

void Player::adventure()
{
    // Adventure
}

Invetory& Player::getInvetory() 
{
    return m_inv;
}


