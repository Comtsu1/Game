#pragma once

#include <chrono>
#include <memory>

#include "Entity/Entity.hpp"
#include "Entity/Goblin/Goblin.hpp"
#include "Entity/Player/Player.hpp"

class Battle
{
    bool finish = 0;
    bool pause = 0;

    Player* __Attacker;
// TODO change to entity
    Goblin* __Attacked;

    public:
        Battle(Player* attacker, Goblin* attacked);

        void startBattle();
        void finishBattle();
        void updateBattle();
        void checkFinish();

        void reactBattle(int option); // TODO choose better name

        void pauseBattle(std::chrono::milliseconds milliseconds);

        // static void newBattle(const Entity& player, const Group& group);
        // for when the player is having a battle with multiple enemies
};
