#include <iostream>
#include <memory>

#include "Inventory.hpp"
#include "Player.hpp"
#include "Slot.hpp"

int main()
{

    Player player; // works
    std::unique_ptr<Player> p; // doesnt work core dumped

    //player->getInvetory().add(Slot("Apple", 1, 1));
    player.getInvetory().add(Slot("Sword", 2, 1));

    p->getInvetory().add(Slot("Sword", 2, 1));

    //player->getInvetory().remove(0);

    player.getInvetory().show();

}
