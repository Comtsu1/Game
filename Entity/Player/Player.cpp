#include "../Entity.hpp"
#include "Player.hpp"

#include "../../Adventure.h"
#include <iostream>
#include <string>

Player::Player(double h, int wl, int fl)
    :Entity(h),
    m_foodlevel(wl),
    m_waterlevel(fl)
{
    m_head     = std::make_unique<Head>();
    m_chest    = std::make_unique<Chest>();
    
    m_leftArm  = std::make_unique<Arm>();
    m_rigthArm = std::make_unique<Arm>();

    m_leftLeg  = std::make_unique<Leg>();
    m_rigthLeg = std::make_unique<Leg>();
}
Player::Player()
    :Entity(100),
    m_foodlevel(100),
    m_waterlevel(100)
{
    m_head     = std::make_unique<Head>();
    m_chest    = std::make_unique<Chest>();
    
    m_leftArm  = std::make_unique<Arm>();
    m_rigthArm = std::make_unique<Arm>();

    m_leftLeg  = std::make_unique<Leg>();
    m_rigthLeg = std::make_unique<Leg>();
}

void Player::update()
{

}

std::string Player::status()
{
    int hp = this->getHealth();
    return hp > 70 ? "Good" :
        (hp >= 50 ? "Hurt" :
         (hp >= 30 ? "Beaten" : "Badly Beaten" ));
}

Invetory& Player::getInvetory() 
{
    return m_inv;
}

void Player::adventure()
{
    Adventure::generageAdventure(this);
}

Head* Player::getHead()
{
    return m_head.get();
}

Chest* Player::getChest()
{
    return m_chest.get();
}

Arm* Player::getArm(Parts which)
{ // if number is 1 returns left arm
  // if number is greater than 1 return right arm
  // else return nullptr
  // default 1
    if(which == Parts::left) return m_leftArm.get();
    else if(which == Parts::right) return m_rigthArm.get();

    return nullptr;
}

Leg* Player::getLeg(Parts which)
{ // if number is 1 returns left leg
  // if number is greater than 1 return right leg
  // else return nullptr
  // default 1
    if(which == Parts::left) return m_leftLeg.get();
    else if(which == Parts::right) return m_rigthLeg.get();

    return nullptr;
}

void Player::damagePart(BodyPart *part, int amount)
{
    part->damage(amount);
}

bool Player::isDead()
{
    // TODO implement body Parts
    
    if(this->getHealth() <= 0) handleDeath();
    return this->getHealth() <= 0;
}

int Player::getFood() const
{
    return m_foodlevel;
}

int Player::getWater() const
{
    return m_waterlevel;
}

void Player::handleDeath()
{
    std::cout << "You died, very sad thing...";
}
