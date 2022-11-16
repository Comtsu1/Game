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

void Goblin::update()
{

}

std::string Goblin::status() // TODO show status in an intuitive way
{
    double head_damage_perc = (double(getHead()->getHealth()) / getHead()->getInitHealth() * 100);

    std::cout<<head_damage_perc;

    return head_damage_perc > 70.0 ? "Good" :
          (head_damage_perc >= 50.0 ? "Hurt" :
          (head_damage_perc >= 30.0 ? "Beaten" : "Badly Beaten" ) );
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
{ 
    if(which == Parts::left) return m_leftArm.get();
    else if(which == Parts::right) return m_rigthArm.get();

    return nullptr;
}

Leg* Goblin::getLeg(Parts which)
{ 
    if(which == Parts::left) return m_leftLeg.get();
    else if(which == Parts::right) return m_rigthLeg.get();

    return nullptr;
}

void Goblin::showBodyStatus()
{
    std::cout << "\n\tHead: " << m_head->status()
                <<"\n\tChest: " << m_chest->status()
                <<"\n\tArm (left and right): \n\t\t"
                << m_leftArm->status() << " and " << m_rigthArm->status()
                <<"\n\tLeg (left and right): \n\t\t"
                << m_leftLeg->status() << " and " << m_rigthLeg->status();
}

void Goblin::damagePart(BodyPart *part, int amount)
{
    part->damage(amount);
}

bool Goblin::isDead()
{
    return this->getHead()->getHealth() < 0;
}

void Goblin::selectBodyPart(Item* item)
{
    std::cout<<"\n\nPlease select a "
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
    // TODO implement enum for easier recognition
    
    int amount = item->getDamage();

    switch (option) {
        case '1':
            this->getHead()->damage(amount);
            break;
        case '2':
            this->getChest()->damage(amount);
            break;
        case '3':
            this->getArm(Parts::left)->damage(amount);
            break;
        case '4':
            this->getArm(Parts::right)->damage(amount);
            break;
        case '5':
            this->getLeg(Parts::left)->damage(amount);
            break;
        case '6':
            this->getLeg(Parts::right)->damage(amount);
            break;
        default:
            std::cout<<"\n\tWhat you have choosen is not betweem 1 and 6!\n\n";
            break;
    }
}
