#pragma once

#include <memory>
#include <string>

#include "../Entity.hpp"
#include "../Goblin/Goblin.hpp"

#include "../../Inventory.hpp"
#include "../../Item/Item.h"

#include "../BodyParts/Head.h"
#include "../BodyParts/Chest.h"
#include "../BodyParts/Arm.h"
#include "../BodyParts/Leg.h"

class Player : public Entity
{
    std::unique_ptr<Head>  m_head;
    std::unique_ptr<Chest> m_chest;
    std::unique_ptr<Arm>   m_leftArm, m_rigthArm;
    std::unique_ptr<Leg>   m_leftLeg, m_rigthLeg;

    int m_foodlevel;
    int m_waterlevel;
    

    Invetory m_inv;

    public:
        Player();
        Player(double h, int wl, int fl);
        
        bool isDead();

        void update();

        std::string status();

        void adventure();

        Head* getHead();
        Chest* getChest();
        Arm* getArm(Parts which);
        Leg* getLeg(Parts which);

        void virtual damagePart(BodyPart* part, int amount);

        int getFood() const;
        int getWater() const;

        Invetory& getInvetory();
};

