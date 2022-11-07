#pragma once

#include "Entity/Entity.hpp"
#include "Entity/Player/Player.hpp"
#include <memory>



class Battle
{
    public:
        static void newBattle(Player* player,
                                Entity* enemy);

        // static void newBattle(const Entity& player, const Group& group);
        // for when the player is having a battle with multiple enemies
};
