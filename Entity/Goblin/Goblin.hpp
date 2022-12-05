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

    ArmorSet m_armorSet;

    public:
        Goblin();

        bool isDead();

        std::string status();

        void update();

        ArmorSet getArmor() const;
        void setArmor(ArmorSet set);

        void attack(Entity* entity, Item* item);

        BodyPart* getPart(Parts which, Type type = Type::NONE);

        void showBodyStatus();

        void selectBodyPart(Item* item);

        void damagePart(BodyPart* part, int amount);

        std::string getVisualAttributes() const;
};

