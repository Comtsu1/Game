#include "Adventure.h"

#include <cstdlib>
#include <iostream>

#include "Entity/Goblin/Goblin.hpp"
#include "ItemList.h"
#include "Slot.hpp"



void Adventure::generageAdventure(Player *player)
{
    Goblin_Attack(player);
}

void Adventure::Goblin_Attack(Player *player)
{
    std::cout<<"You have encountered a goblin, would you like to attack it(y/n)?\n>";
    int op;
    op = getch();

    if(op == 'y' || op == 'Y')
    {
        Goblin goblin;
        goblin.setArmor(LEATHER_ARMOR_FULL_SET);
        while(goblin.getHealth() > 0)
        {
            std::cout<<"\n\nThe goblin has " << goblin.getHealth() << " health, would you like to attack(y/n)?\n>";
            op = getch();
            if(op == 'y' || op == 'Y')
                player->attack(&goblin, player->getInvetory()[0].getItem());
            else 
            {
                std::cout<<"\nYou fucked off, and the golbin surprisingly let you go.";
                break;
            }
        }
        if(goblin.getHealth() <= 0)
        {
            // implement reward function TODO
            int reward = rand() % 4 + 1;
            std::cout<<"\n\nYou successfully defeated the goblin and got "<<reward<<" copper coins, they amount to shit!\n\n";
            player->getInvetory().add(Slot(COPPER_COIN, reward));
        }

        

    }
    else
    {
        std::cout<<"\nYou left the goblin alone, sparing his life.\n";
    }

}
