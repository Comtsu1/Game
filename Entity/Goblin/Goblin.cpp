#include "Goblin.hpp"
#include "../../ItemList.h"

Goblin::Goblin()
    : Entity(10), m_slot(NULL_ITEM, 0)
{

}

Goblin::Goblin(Slot slot)
    : Entity(10), m_slot(slot.getItem(), slot.getQty())
{

}
