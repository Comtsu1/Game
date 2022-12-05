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

void Player::attack(Entity *entity, Item *item)
{
    std::cout<<"Please select a "
            <<"body part you would like to hit:"
            <<"\n\t1.Head"
            <<"\n\t2.Chest"
            <<"\n\t3.Left Arm"
            <<"\n\t4.Right Arm"
            <<"\n\t5.Left eg"
            <<"\n\t6.Right Leg"
            <<"\n> ";
    
    int option = getchr();

    // TODO add weapon support
    
    BodyPart* selected = nullptr;

    switch (option)
    {
        case '1':
            selected = entity->getPart(Parts::Head);
            break;
        case '2':
            selected = entity->getPart(Parts::Chest);
            break;
        case '3':
            selected = entity->getPart(Parts::Arm, Type::left);
            break;
        case '4':
            selected = entity->getPart(Parts::Arm, Type::right);
            break;
        case '5':
            selected = entity->getPart(Parts::Leg, Type::left);
            break;
        case '6':
            selected = entity->getPart(Parts::Leg, Type::right);
            break;
    }

    if(selected == nullptr)
    { // if no part of the body was choosen
        std::cout << "No good, the number is not correct! ";
        return;
    }


    // TODO change damage to a more appropriate ecuation
    int damage = item->getDamage();
    damagePart(selected, damage);
}

BodyPart* Player::getPart(Parts which, Type type)
{
    switch (which) {
        case Parts::Head:
            return m_head.get();
            break;
        case Parts::Chest:
            return m_chest.get();
            break;
        case Parts::Arm:
            if(type == Type::NONE) return m_leftArm.get();
            return type == Type::left ? m_leftArm.get() : m_rigthArm.get();
            break;
        case Parts::Leg:
            if(type == Type::NONE) return m_leftLeg.get();
            return type == Type::left ? m_leftLeg.get() : m_rigthLeg.get();
            break;
        default:
            return nullptr;
    }
}

void Player::damagePart(BodyPart *part, int amount)
{
    part->damage(amount);
}

bool Player::isDead()
{
    // TODO implement body Parts
    if(this->m_head->getHealth() > 0) return 0;
    
    handleDeath();
    return 1;
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

std::string Player::getVisualAttributes() const
{
    return "not yet";
}


void Player::showBodyStatus()
{
    std::cout << "\nHead: " << m_head->getPercentage()
                <<"\nChest: " << m_chest->getPercentage()
                <<"\nArm (left and right): \n\t"
                << m_leftArm->getPercentage() << " and " << m_rigthArm->getPercentage()
                <<"\nLeg (left and right): \n\t"
                << m_leftLeg->getPercentage() << " and " << m_rigthLeg->getPercentage();
}
