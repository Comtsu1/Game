#pragma once

#include "../Entity.hpp"
#include "../../Item.h"

class Goblin : public Entity
{ 
    Item m_item;
    public:
        Goblin();
        Goblin(Item i);
};

