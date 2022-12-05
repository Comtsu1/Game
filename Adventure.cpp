#include <thread>

#include "Adventure.h"

#include "Battle.h"
#include "Entity/Entity.hpp"
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

    std::cout << "You encountered a goblin, he looks quite angry..."
            << "\n\n";

    std::unique_ptr<Goblin> goblin = std::make_unique<Goblin>();

    Battle battle(player, goblin.get());
    battle.startBattle();

    if(goblin->isDead())
    {
        // implement reward function TODO
        int reward = rand() % 4 + 1;
        std::cout<<"\n\nYou successfully defeated the goblin and got "<<reward<<" copper coins, they amount to shit!\n\n";
        player->getInvetory().add(COPPER_COIN, reward);
        sleep(2);
    }
}
