#include <iostream>
#include <memory>

#include "Inventory.hpp"
#include "Player.hpp"
#include "Slot.hpp"

int main()
{
    std::unique_ptr<Player> player;

    player->getInvetory().add(Slot("Apple", 1, 1));
    player->getInvetory().add(Slot("Sword", 2, 1));

    player->getInvetory().remove(0);

    player->getInvetory().show();

}
