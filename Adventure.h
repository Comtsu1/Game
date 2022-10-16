#pragma once

#include "getch.h"
#include "Entity/Player/Player.hpp"

class Adventure
{
    private:
        // adventures
        static void Goblin_Attack(Player *p);
    public:
        static void generageAdventure(Player *p);
};
