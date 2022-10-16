#include "Adventure.h"

#include <iostream>

#include "Entity/Goblin/Goblin.hpp"



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
            std::cout<<"\nThe goblin has " << g.getHealth() << "health, would you like to attack(y/n)?";
            op = getch();
            if(op == 'y' || op == 'Y') p->attack(&g, 1);
            else std::cout<<"\nYou did shit, and so did the goblin that didn't see you.";
        }
    }
    else
    {
        std::cout<<"You left the goblin alone, sparing his life.\n";
    }

}
