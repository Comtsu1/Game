#include "Adventure.h"

#include <cstdlib>
#include <iostream>

#include "Entity/Goblin/Goblin.hpp"
#include "ItemList.h"
#include "Slot.hpp"



void Adventure::generageAdventure(Player *p)
{
    Goblin_Attack(p);
}

void Adventure::Goblin_Attack(Player *p)
{
    std::cout<<"You have encountered a goblin, would you like to attack it(y/n)?\n>";
    int op;
    op = getch();

    if(op == 'y' || op == 'Y')
    {
        Goblin g;
        while(g.getHealth() > 0)
        {
            std::cout<<"\n\nThe goblin has " << g.getHealth() << " health, would you like to attack(y/n)?\n>";
            op = getch();
            if(op == 'y' || op == 'Y') p->attack(&g, 1);
            else 
            {
                std::cout<<"You fucked off, and the golbin surprisingly let you go.";
                break;
            }
        }
        if(g.getHealth() <= 0)
        {
            // implement reward TODO
            int reward = rand() % 4 + 1;
            std::cout<<"\n\nYou successfully defeated the goblin and got "<<reward<<" copper coins, they amount to shit!\n\n";
            p->getInvetory().add(Slot(COPPER_COIN, reward));
        }

        

    }
    else
    {
        std::cout<<"You left the goblin alone, sparing his life.\n";
    }

}
