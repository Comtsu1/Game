#pragma once

#include "Entity/Entity.hpp"
#include "Entity/Player/Player.hpp"

class Stats
{
    public:
        static void showStats(Entity* entity);
        static void showStats(Player* player);
};
