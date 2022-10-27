#pragma once

#include "../Entity.hpp"
#include "../../Item/Item.h"
#include "../../Slot.hpp"


class Goblin : public Entity
{ 
    Slot m_slot;
    public:
        Goblin();
        Goblin(Slot slot);
};

