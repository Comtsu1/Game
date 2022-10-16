#include "Goblin.hpp"
#include "../../Item.h"
#include "../../ItemList.h"

Goblin::Goblin()
    : Entity(10), m_item(NULL_ITEM)
{

}

Goblin::Goblin(Item i)
    : Entity(10), m_item(i)
{

}
