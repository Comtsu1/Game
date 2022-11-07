#include <iostream>

#include "Stats.h"


void Stats::showStats(Entity* entity)
{}

void Stats::showStats(Player* player)
{

    // food level
    std::cout<<"Food level: ";
    for(int food = 0; food <= 100; food += 10)
    {
        if(food <= player->getFood()) std::cout<<"O";
        else std::cout<<".";
    }

    std::cout<<"Water level: ";
    for(int food = 0; food <= 100; food += 10)
    {
        if(food <= player->getWater()) std::cout<<"O";
        else std::cout<<".";
    }

    std::cout<<"\n\n";
}
