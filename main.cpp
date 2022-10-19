#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

#include "defines.h"
#include "ItemList.h"

#include "Item/Item.h"
#include "Inventory.hpp"
#include "Entity/Player/Player.hpp"
#include "Slot.hpp"

int getch();

int main()
{
    // new shit
    srand(time(0));

    std::unique_ptr<Player> p = std::make_unique<Player>();


    p->getInvetory().add(Slot(WOODEN_SWORD, 1));
    // p->setArmor(LEATHER_ARMOR_FULL_SET);

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
            case (int)('1'):
            case (int)('q'):
                p->adventure();
                break;
            case (int)('2'):
            case (int)('w'):
                std::cout<<"\n";
                p->getInvetory().show();

                std::cout<<CONTINUE_MESSAGE;
                getch();

                std::system("clear");
                break;
            case (int)('3'):
            case (int)('e'):
                gamerunning = 0;
                break;
        }
    }
}
