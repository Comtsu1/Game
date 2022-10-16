#include "Goblin.hpp"
#include "../../Item.h"
#include "../../ItemList.h"

Goblin::Goblin()
    : Entity(10), m_item(Item(WOODEN_SWORD, WOODEN_SWORD_ID))
{

}

Goblin::Goblin(Item i)
    : Entity(10), m_item(i)
{

}
