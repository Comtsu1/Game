#include <unistd.h>
#include <thread>
#include <chrono>

#include "Battle.h"

#include "Entity/Entity.hpp"
#include "Entity/Goblin/Goblin.hpp"
#include "Entity/Player/Player.hpp"

#include "Stats.h"


void clearScreen(); // from getch.cpp
int getchr(); // from getch.cpp

void test()
{
    while(true)
    {
        getchr();
    }
}

Battle::Battle(Player* attacker, Goblin* attacked)
    :__Attacker(attacker), __Attacked(attacked) {}

void Battle::finishBattle()
{
    finish = 1;
}

void Battle::startBattle()
{
    // TODO make it so you can attack an entity too 

    std::cout << "You have encountered an aggressive Goblin:"
        <<"\n\tEntity's status: " << __Attacked->status()
        <<"\n\tYou(hp): "<< __Attacker->getHealth()
        <<"\nWhat would you like to do?\n"
        <<"\tAttack(a/A)\n"
        <<"\tInspect visually(i/I)\n"
        <<"\tLeave(l/L)\n"
        <<"\tShow Stats(s/S)\n"
        <<"\tNothing(anything else)\n"
        <<"> ";

    int op;
    op = getchr();

    if(op == 'l' || op == 'L')
    {
        if(rand() % 10)
        { // escapes
            this->finishBattle();
            std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
            sleep(2);
            return;
        }
        else
        { // gets caught
            std::cout<<"\n\nYou got caught by the goblin from making to much noise. Prepare!\n\n";
        }
    }
    else
    {
        while(!(
            op == 'a' || op == 'A'
            || op == 'l' || op == 'L'
               ))
        {
            clearScreen();
            if(rand() % 100)
            { // very stupid man right here
                if(op == 'i' || op == 'I')
                { // show the goblin's stats only if the goblin didn't see the __Attacker
                    //std::cout<<"\nThe goblin has: "<<__Attacked->getArmor().getString();

                    std::cout<<"State of Goblin: "; __Attacked->showBodyStatus();
                    std::cout<<"\n\n";
                }
                else if(op == 's' || op == 'S')
                {
                    Stats::showStats(__Attacker);
                    getchr(); // waits for user input
                    clearScreen();
                }

                std::cout<<"\nYou and the goblin just stay in your places, waiting for something to happen.\n\n";
            }
            else
            {
                std::cout<<"\nLike one in a hundred, you got caught by the goblin even thought you didn't do anything. Prepare!\n\n";
                sleep(2);
                break;
            }

            std::cout << "You still see the goblin"
                <<", what would you like to do?\n"
                <<"\tAttack(a/A)\n"
                <<"\tInspect visually(i/I)\n"
                <<"\tLeave(l/L)\n"
                <<"\tShow Stats(s/S)\n"
                <<"\tNothing(anything else)\n"
                <<"> "; op = getchr();
        }

        if(op == 'l' || op == 'L')
        {
            if(rand() % 10)
            { // gets caught
                std::cout<<"\n\nYou got caught by the goblin from making to much noise. Prepare!\n\n";
            }
            else
            { // escapes
                std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
                finishBattle();
                return;
            }
        }
    }

    while(__Attacked->getHealth() > 0)
    {
        clearScreen();
        reactBattle(op);

        if(__Attacked->isDead() || __Attacker->isDead())
        {
            finishBattle();
            return;
        }

        __Attacker->update();
        __Attacked->update();

        // start of new round
        //std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        std::cout<<"You are mid-battle"
            <<"\n\tGolbin's status: " << __Attacked->status()
            <<"\n\tYou(hp): " <<__Attacker->getHealth()
            <<"\nWhat would you like to do?\n"
            <<"\tAttack(a/A)\n"
            <<"\tInspect visually(i/I)\n"
            <<"\tRun(r/R)\n"
            <<"\tShow Stats(s/S)\n"
            <<"\tNothing(anything else)\n"
            <<"> "; op = getchr();
    }

}

void Battle::reactBattle(int option)
{
    if(option == 'a' || option == 'A')
    {
        clearScreen();
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
            std::cout<<"You are stupid and the goblin hit you!\n";
            __Attacked->attack(__Attacker, WOODEN_SWORD);
        }
        else
        { // gets caught
            std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
            sleep(1);
            finishBattle();
            return;
        }
    } 
    else if(option == 's' || option == 'S')
    {
        Stats::showStats(__Attacker);
        getchr(); // user input
        clearScreen();
    }
    else
    {
        std::cout<<"Because you are stupid, and did nothing "
            <<"the goblin hit you with his sword he had.\n";
        __Attacked->attack(__Attacker, WOODEN_SWORD);
    }
}
