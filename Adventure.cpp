#include "Adventure.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <type_traits>
#include <unistd.h>

#include "Battle.h"
#include "defines.h"

#include "Entity/Goblin/Goblin.hpp"
#include "ItemList.h"
#include "Slot.hpp"



void Adventure::generageAdventure(Player *player)
{
    Goblin_Attack(player);
}

void Adventure::Goblin_Attack(Player *player)
{
    std::unique_ptr<Goblin> goblin = std::make_unique<Goblin>();

    goblin->setArmor(LEATHER_ARMOR_FULL_SET);
    
    Battle::newBattle(player, goblin.get());

    if(goblin->isDead())
    {
        // implement reward function TODO
        int reward = rand() % 4 + 1;
        std::cout<<"\n\nYou successfully defeated the goblin and got "<<reward<<" copper coins, they amount to shit!\n\n";
        player->getInvetory().add(COPPER_COIN, reward);
        sleep(2);
    }
}
