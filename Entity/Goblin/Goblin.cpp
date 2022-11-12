#include <memory>

#include "Goblin.hpp"
#include "../../ItemList.h"

int getchr(); // getch.cpp

Goblin::Goblin()
    : Entity(10), m_slot(NULL_ITEM, 0)
{
    m_head     = std::make_unique<Head>();
    m_chest    = std::make_unique<Chest>();
    
    m_leftArm  = std::make_unique<Arm>();
    m_rigthArm = std::make_unique<Arm>();

    m_leftLeg  = std::make_unique<Leg>();
    m_rigthLeg = std::make_unique<Leg>();
}

Goblin::Goblin(Slot slot)
    : Entity(10), m_slot(slot.getItem(), slot.getQty())
{
    m_head     = std::make_unique<Head>();
    m_chest    = std::make_unique<Chest>();
    
    m_leftArm  = std::make_unique<Arm>();
    m_rigthArm = std::make_unique<Arm>();

    m_leftLeg  = std::make_unique<Leg>();
    m_rigthLeg = std::make_unique<Leg>();
}

std::string Goblin::status()
{
    int hp = getChest()->getHealth();

    return hp > 7 ? "Good" :
        (hp >= 5 ? "Beaten" :
         (hp >= 3 ? "Badly Beaten" : "Near Death" ) );
}

Head* Goblin::getHead()
{
    return m_head.get();
}

Chest* Goblin::getChest()
{
    return m_chest.get();
}

Arm* Goblin::getArm(Parts which)
{ // if number is 1 returns left arm
  // if number is greater than 1 return right arm
  // else return nullptr
  // default 1
    if(which == Parts::left) return m_leftArm.get();
    else if(which == Parts::right) return m_rigthArm.get();

    return nullptr;
}

Leg* Goblin::getLeg(Parts which)
{ // if number is 1 returns left leg
  // if number is greater than 1 return right leg
  // else return nullptr
  // default 1
    if(which == Parts::left) return m_leftLeg.get();
    else if(which == Parts::right) return m_rigthLeg.get();

    return nullptr;
}

void Goblin::damagePart(BodyPart *part, int amount)
{
    part->damage(amount);
}

bool Goblin::isDead()
{
    return this->getChest()->getHealth() <= 0;
    return false;
}

void Goblin::selectBodyPart(Item* item)
{
    std::cout<<"\n\nPlease select a "
            <<"body part you would like to hit:"
            <<"\n\t1.Head"
            <<"\n\t2.Chest"
            <<"\n\t3.Left Arm"
            <<"\n\t4.Right Arm"
            <<"\n\t5.Left Leg"
            <<"\n\t6.Right Leg"
            <<"\n> ";
    
    int option = getchr();

    // TODO add weapon support
    // TODO implement enum for easier recognition
    switch (option) {
        case '1':
            this->getHead()->damage(1);
            break;
        case '2':
            this->getChest()->damage(1);
            break;
        case '3':
            this->getArm(Parts::left)->damage(1);
            break;
        case '4':
            this->getArm(Parts::right)->damage(1);
            break;
        case '5':
            this->getLeg(Parts::left)->damage(1);
            break;
        case '6':
            this->getLeg(Parts::right)->damage(1);
            break;
    }
}


