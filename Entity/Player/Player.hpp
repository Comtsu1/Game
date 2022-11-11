#pragma once

#include <memory>

#include "../Entity.hpp"
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

    Invetory m_inv;

    public:
        Player();
        Player(double h, int wl, int fl);
        
        void adventure();

        Invetory& getInvetory();
};

