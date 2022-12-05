#include <algorithm>
#include <cstdlib>
#include <memory>
#include <thread>

#include "Adventure.h"

#include "Battle.h"
#include "Entity/Entity.hpp"
#include "Entity/Player/Player.hpp"
#include "defines.h"

#include "Entity/Goblin/Goblin.hpp"
#include "ItemList.h"
#include "Slot.hpp"

void clearScreen(); // getchr

void Adventure::generageAdventure(Player *player)
{


    int chance = rand() % 2;

    if(chance == 0)
        Herb_Gathering(player);
    else if(chance == 1)
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

void Adventure::Herb_Gathering(Player *player)
{
    std::cout << "You find yourself in a wild garden full with herbs."
            << "\nWould you like to reserve some time for collecting?"
            <<"\n\tYes(y)"
            <<"\n\tNo(n)"
            <<"\n>";

    int option = getchr();

    int randomGoblinAttack = rand() % 100; // nobody expects those no?

    if(randomGoblinAttack == 69) // 1/100 chance
    {
        clearScreen();
        std::cout<<"\n\nIt seems that some goblin noticed you, no luck today!";
        Goblin_Attack(player);
        return;
    }



    if(option == 'y' || option == 'Y')
    { // yes
        auto herbs = HERB;
        int herbsQty = rand() % 5 + 2; // min 2 max 7
        player->getInvetory().add(std::move(herbs), herbsQty);

        std::cout<<"\n\nYou take your time picking " << herbsQty << " herbs from the wild garden and the you went back to folow the road ahead...";
        option = getchr();
        return;
    }
    else if(option == 'n' || option == 'N')
    { // no
        std::cout<<"\n\nYou ignore the garden and find yourself out of the forest you entered.";
    }
    else
    {
        std::cout << "I dont think that is an option";
        option = getchr();
        clearScreen();
        return;
    }
}

