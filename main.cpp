#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

#include "Item/Tool/Tool.h"
#include "defines.h"
#include "ItemList.h"

#include "Item/Item.h"
#include "Inventory.hpp"
#include "Entity/Player/Player.hpp"
#include "Slot.hpp"

#include "Battle.h"
#include "Stats.h"

// TODO need to implement armor

void clearScreen(); // from getch.cpp
int getchr(); // from getch.cpp

int main()
{
    // new shit
    srand(time(0));

    std::unique_ptr<Player> p = std::make_unique<Player>();

    p->getInvetory().add(std::move(WOODEN_SWORD), 1);
    // p->setArmor(LEATHER_ARMOR_FULL_SET);

    bool gamerunning = 1;

    clearScreen(); // clears the screen for the start of the game

    while(gamerunning)
    {
        std::cout<<"\nWelcome traveler\n"
                <<"You shall choose only one:\n"
                <<"\t1. Adventure\n"
                <<"\t2. View Inventory\n"
                <<"\t3. Exit\n";

        int option; option = getchr();
        switch (option)
        {
            case (int)('1'):
            case (int)('q'):
                clearScreen();
                p->adventure();
                break;
            case (int)('2'):
            case (int)('w'):
                std::cout<<"\n";
                p->getInvetory().show();

                std::cout<<CONTINUE_MESSAGE;
                getchr();

                clearScreen();
                break;
            case (int)('3'):
            case (int)('e'):
                gamerunning = 0;
                break;
        }

        if(p->isDead())
        {
            return 0; // player died
        }

        clearScreen();
    }
}
