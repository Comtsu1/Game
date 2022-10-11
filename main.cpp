#include <iostream>

#include "Inventory.hpp"
#include "Player.hpp"
#include "Slot.hpp"

int main()
{
    Player* player = new Player();

    player->getInvetory().add(Slot(1, 1));
    player->getInvetory().add(Slot(2, 1));

    player->getInvetory().remove(0);

    player->getInvetory().show();

}
