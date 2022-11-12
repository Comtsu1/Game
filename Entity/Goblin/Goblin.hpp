#pragma once

#include <string>

#include "../Entity.hpp"
#include "../../Item/Item.h"
#include "../../Slot.hpp"

#include "../BodyParts/Head.h"
#include "../BodyParts/Chest.h"
#include "../BodyParts/Arm.h"
#include "../BodyParts/Leg.h"

class Goblin : public Entity
{ 
    std::unique_ptr<Head>  m_head;
    std::unique_ptr<Chest> m_chest;
    std::unique_ptr<Arm>   m_leftArm, m_rigthArm;
    std::unique_ptr<Leg>   m_leftLeg, m_rigthLeg;

    Slot m_slot;
    public:
        Goblin();
        Goblin(Slot slot);

        bool isDead();

        std::string status();

        Head* getHead();
        Chest* getChest();
        Arm* getArm(Parts which);
        Leg* getLeg(Parts which);

        void selectBodyPart(Item* item);

        void virtual damagePart(BodyPart* part, int amount);
};

