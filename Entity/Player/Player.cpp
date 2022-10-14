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

void Player::damage(int h)
{
    this->m_health -= h;
}

int Player::getHealth() const
{
    return m_health;
}

Invetory& Player::getInvetory() 
{
    return m_inv;
}

void Player::heal(int h)
{
    this->m_health += h;
}

void Player::adventure()
{
    Adventure::generageAdventure(this);
}

