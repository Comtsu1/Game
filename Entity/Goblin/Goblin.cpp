#include "Goblin.hpp"
#include "../../Item.h"
#include "../../ItemList.h"

Goblin::Goblin()
    : Entity(10), sword(Item(WOODEN_SWORD, WOODEN_SWORD_ID))
{

}

void Goblin::attack(Entity *e, int hp)
{
    e->damage(hp);
}
