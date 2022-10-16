#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "Item.h"
#include "defines.h"

#include "ItemList.h"
#include "Inventory.hpp"
#include "Entity/Player/Player.hpp"
#include "Slot.hpp"

int getch();

int main()
{
    std::unique_ptr<Player> p = std::make_unique<Player>();


    p->getInvetory().add(Slot(WOODEN_SWORD, 1));

    bool gamerunning = 1;

    std::system("clear"); // clears the screen for the start of the game

    while(gamerunning)
    {
        std::cout<<"\nWelcome traveler\n"
                <<"You shall choose only one:\n"
                <<"\t1. Adventure\n"
                <<"\t2. View Inventory\n"
                <<"\t3. Exit\n";

        int option; option = getch();
        switch (option) {
            case START_ONE + 1: 
                p->adventure();
                break;
            case START_ONE + 2:
                std::cout<<"\n";
                p->getInvetory().show();

                std::cout<<CONTINUE_MESSAGE;
                getch();

                std::system("clear");
                break;
            case START_ONE + 3:
                gamerunning = 0;
                break;
        }
    }
}
