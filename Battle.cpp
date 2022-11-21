#include <iostream>
#include <unistd.h>
#include <thread>
#include <functional>

#include "Battle.h"

#include "Entity/Entity.hpp"
#include "Entity/Goblin/Goblin.hpp"
#include "Entity/Player/Player.hpp"

#include "Stats.h"
#include "defines.h"


void clearScreen(); // from getch.cpp
int getchr(); // from getch.cpp
int _kbhit();

Battle::Battle(Player* attacker, Goblin* attacked)
    :__Attacker(attacker), __Attacked(attacked) {}

void Battle::pauseBattle(std::chrono::milliseconds milliseconds)
{
    pause = 1;
    auto sleep_function = [=](){
        while (pause) {
            if(_kbhit()) { getchr(); clearScreen(); }
        }
    };

    std::thread sleep_thread(sleep_function);
    std::this_thread::sleep_for(milliseconds);
    pause = 0;
    sleep_thread.detach();
}


void Battle::finishBattle()
{
    finish = 1;
}

void Battle::startBattle()
{
    // TODO make it so you can attack an entity too 
    int op;

    while(__Attacked->getHealth() > 0)
    {
        // new round
        std::cout<<"You and the goblin are ready to exchange blows. "
            << " What will you do?"
            <<"\n\tGolbin's status: " << __Attacked->status()
            <<"\n\tYou(hp): " << __Attacker->getHealth()
            <<"\nWhat would you like to do?\n"
            <<"\tAttack(a/A)\n"
            <<"\tInspect visually(i/I)\n"
            <<"\tRun(r/R)\n"
            <<"\tShow Stats(s/S)\n"
            <<"\tNothing(anything else)\n"
            <<"> ";

        op = getchr();
        reactBattle(op);


        if(__Attacked->isDead() || __Attacker->isDead())
        {
            finishBattle();
            return;
        }
        __Attacker->update();
        __Attacked->update();

        clearScreen();
    }
}

void Battle::reactBattle(int option)
{
    // clears the screen so the new information can be
    // displayed
    clearScreen();

    if(option == 'a' || option == 'A')
    {
        __Attacked->selectBodyPart(__Attacker->getInvetory()[0].getItem());
        //__Attacker->attack(__Attacked, __Attacker->getInvetory()[0].getItem());
        __Attacked->attack(__Attacker, WOODEN_SWORD);
        clearScreen();
    }
    else if(option == 'i' || option == 'I')
    {
        //std::cout<<"\nThe goblin has: "<<__Attacked->getArmor().getString();

        std::cout<<"State of Goblin: "; __Attacked->showBodyStatus();
        std::cout<<"\n\n";
    }
    else if(option == 'r' || option == 'R')
    {
        if(rand() % 10)
        { // gets caught
            std::cout<<"\n\nYou are stupid and the goblin hit you!\n";
            __Attacked->attack(__Attacker, WOODEN_SWORD);
        }
        else
        { // leaves
            std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
            sleep(1);
            finishBattle();
            return;
        }
    } 
    else if(option == 's' || option == 'S')
    {
        Stats::showStats(__Attacker);

        std::cout<< "\n"
            << CONTINUE_MESSAGE;

        getchr(); // user input
        clearScreen();
        return;
    }
    else
    {
        std::cout<<"Because you are stupid, and did nothing "
            <<"the goblin hit you with his sword he had.\n";
        __Attacked->attack(__Attacker, WOODEN_SWORD);
    }

    pauseBattle(std::chrono::milliseconds(2500));
}
