#include <cstdlib>
#include <iostream>
#include <memory>
#include <tuple>

#include "Goblin.hpp"
#include "../../ItemList.h"

int getchr(); // getch.cpp

Goblin::Goblin()
    : Entity(10), m_slot(NULL_ITEM, 0)
{
    m_head     = std::make_unique<Head>(20);
    m_chest    = std::make_unique<Chest>(75);
    
    m_leftArm  = std::make_unique<Arm>(30);
    m_rigthArm = std::make_unique<Arm>(30);

    m_leftLeg  = std::make_unique<Leg>(35);
    m_rigthLeg = std::make_unique<Leg>(35);
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

#define DEBUG

#ifdef DEBUG
    std::cout<<head_damage_perc;
#endif

    return head_damage_perc > 70.0 ? "Good" :
          (head_damage_perc >= 50.0 ? "Hurt" :
          (head_damage_perc >= 30.0 ? "Beaten" : "Badly Beaten" ) );
}

void Goblin::attack(Entity *entity, Item *item)
{
    // goblin randomly attack the player
    
    int option = rand() % 6 + 1;

    // give some bias towards the head
    option = rand() % 10 + 1 >= 4 ? (1) // true 6/10
                    : (option); // false 4/5

    BodyPart* selectedBodyPart = nullptr;

    switch (option)
    {
        case 1:
            selectedBodyPart = entity->getPart(Parts::Head);
            break;
        case 2:
            selectedBodyPart = entity->getPart(Parts::Chest);
            break;
        case 3:
            selectedBodyPart = entity->getPart(Parts::Arm, Type::left);
            break;
        case 4:
            selectedBodyPart = entity->getPart(Parts::Arm, Type::right);
            break;
        case 5:
            selectedBodyPart = entity->getPart(Parts::Leg, Type::left);
            break;
        case 6:
            selectedBodyPart = entity->getPart(Parts::Leg, Type::right);
            break;
    }

    if(selectedBodyPart == nullptr)
        return; // something went very wrong

    auto sword = WOODEN_SWORD;

    int damage = sword.get()->getDamage();

    entity->damagePart(selectedBodyPart, damage);

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

}

std::string Goblin::getVisualAttributes() const
{
    return "not yet";
}
