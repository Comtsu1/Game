#pragma once

#include "Entity/Player/Player.hpp"

int getch();

class Adventure
{
    private:
        // adventures
        static void Goblin_Attack(Player *p);
    public:
        static void generageAdventure(Player *p);
};
