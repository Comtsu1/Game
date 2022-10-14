#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

#include <unistd.h> // for STDIN_FILENO
#include <termios.h>

#include "ItemList.h"

#include "Inventory.hpp"
#include "Player.hpp"
#include "Slot.hpp"


#define START_ONE 48 // code ascii for '0'

int main()
{

    // setting termios settings
    struct termios old_settings, new_settings;

    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;

    new_settings.c_lflag &= (~ICANON & ~ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    // end
    std::unique_ptr<Player> p = std::make_unique<Player>();


    p->getInvetory().add(Slot(WOODEN_SWORD, WOODEN_SWORD_ID, 1));

    p->getInvetory().show();


    bool gamerunning = 1;

    while(gamerunning)
    {
        std::cout<<"Welcome traveler\n"
                <<"You shall choose only one:\n"
                <<"\t1. Adventure\n"
                <<"\t2. View Inventory\n"
                <<"\t3. Exit\n";

        int option; option = getc(stdin);
        switch (option) {
            case START_ONE + 1: 

                break;
            case START_ONE + 2:
                std::cout<<"\n";
                p->getInvetory().show();
                std::cout<<"\n";
                break;
            case START_ONE + 3:
                gamerunning = 0;
                break;
        }

    }

    // be in the habit of disabling after use
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

}
