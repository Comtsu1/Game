#include "Entity/Player/Player.hpp"

#include <iostream>
#include <sys/types.h>
#include <vector>
#include <functional>

#pragma once

class Adventure
{
    private:
        unsigned int nrAdventures = 0;

        // adventures
        static void Goblin_Attack(Player *p)
        {
            std::cout<<"You have encountered a goblin";
        }
    public:
        static void generageAdventure(Player *p)
        {
            Goblin_Attack(p);
        }
};
