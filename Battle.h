#pragma once

#include <memory>

#include "Entity/Entity.hpp"
#include "Entity/Goblin/Goblin.hpp"
#include "Entity/Player/Player.hpp"



class Battle
{
    public:

        static void newBattle(Player* player,
                                Goblin* enemy);

        // static void newBattle(const Entity& player, const Group& group);
        // for when the player is having a battle with multiple enemies
};
