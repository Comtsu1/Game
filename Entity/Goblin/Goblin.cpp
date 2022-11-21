#include <iostream>
#include <memory>
#include <tuple>

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

ArmorSet Goblin::getArmor() const
{
    return m_armorSet;
}

void Goblin::setArmor(ArmorSet set)
{
    m_armorSet = set;
}

std::string Goblin::status() // TODO show status in an intuitive way
{
    double head_damage_perc = (double(getPart(Parts::Head)->getHealth()) / getPart(Parts::Head)->getInitHealth() * 100);

    std::cout<<head_damage_perc;

    return head_damage_perc > 70.0 ? "Good" :
          (head_damage_perc >= 50.0 ? "Hurt" :
          (head_damage_perc >= 30.0 ? "Beaten" : "Badly Beaten" ) );
}

BodyPart* Goblin::getPart(Parts which, Type type)
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

void Goblin::showBodyStatus()
{
    std::cout << "\n\tHead: " << m_head->status()
                <<"\n\tChest: " << m_chest->status()
                <<"\n\tArm (left and right): \n\t\t"
                << m_leftArm->status() << " and " << m_rigthArm->status()
                <<"\n\tLeg (left and right): \n\t\t"
                << m_leftLeg->status() << " and " << m_rigthLeg->status();
}

void Goblin::damagePart(BodyPart *part, int amount) // TODO goblin cant parry shit
{
    part->damage(amount);
}

bool Goblin::isDead()
{
    return this->getPart(Parts::Head)->getHealth() < 0;
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
    
    BodyPart* selected;

    selected =
        option == '1' ? getPart(Parts::Head) :
            option == '2' ? getPart(Parts::Chest) :
                option == '3' ? getPart(Parts::Arm, Type::left) :
                    option == '4' ? getPart(Parts::Arm, Type::right) :
                        option == '5' ? getPart(Parts::Leg, Type::left) :
                            option == '6' ? getPart(Parts::Leg, Type::right) :
                                nullptr;
    if(selected == nullptr)
    { // if no part of the body was choosen
        std::cout << "No good, the number is not correct! ";
        return;
    }

    damagePart(selected, item->getDamage());
}

std::string Goblin::getVisualAttributes() const
{
    return "not yet";
}
