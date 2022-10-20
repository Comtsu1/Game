#include "Adventure.h"

#include <cstdlib>
#include <iostream>

#include "Entity/Goblin/Goblin.hpp"
#include "ItemList.h"
#include "Slot.hpp"



void Adventure::generageAdventure(Player *player)
{
    Goblin_Attack(player);
}

void Adventure::Goblin_Attack(Player *player)
{
    Goblin goblin;
    // goblin.setArmor(GOLD_ARMOR_FULL_SET);
    goblin.setArmor(LEATHER_ARMOR_FULL_SET);

    std::cout << "You have encountered a goblin, with "
        << goblin.getHealth()
        <<"hp, what would you like to do?\n"
        <<"\tAttack(a/A)\n"
        <<"\tInspect visually(i/I)\n"
        <<"\tLeave(l/L)\n"
        <<"\tNothing(anything else)\n"
        <<"> ";
    int op;
    op = getch();
    
    if(op == 'a' || op == 'A')
    {
        player->attack(&goblin, player->getInvetory()[0].getItem());
    }
    else if(op == 'i' || op == 'I')
    {
        std::cout<<"\n\nThe goblin has: "<<goblin.getArmor().getString()
            <<"\n\n";
    }
    else if(op == 'l' || op == 'L')
    {
        if(rand() % 10)
        { // escapes
            std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
        }
        else
        { // gets caught
            std::cout<<"\n\nYou got caught by the goblin from making to much noise. Prepare!\n\n";
            return;
        }
    }
    else
    {
        while(!(
            op == 'a' || op == 'A'
            || op == 'i' || op == 'I'
            || op == 'l' || op == 'L'
               ))
        {
            std::system("clear");
            if(rand() % 100)
            { // very stupid man right here
                std::cout<<"\n\nYou and the goblin just stay in your places, waiting for something to happen.\n";
            }
            else
            {
                std::cout<<"\n\nLike one in a hundred, you got caught by the goblin even thought you didn't do anything. Prepare!\n\n";
                break;
            }
            
            std::cout << "You still see the goblin"
                <<", what would you like to do?\n"
                <<"\tAttack(a/A)\n"
                <<"\tInspect visually(i/I)\n"
                <<"\tLeave(l/L)\n"
                <<"\tNothing(anything else)\n"
                <<"> "; op = getch();
        }
        if(op == 'l' || op == 'L')
        {
            if(rand() % 10)
            { // escapes
                std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
            }
            else
            { // gets caught
                std::cout<<"\n\nYou got caught by the goblin from making to much noise. Prepare!\n\n";
            }
        }
    }

    while(goblin.getHealth() > 0)
    {
        if(op == 'a' || op == 'A')
        {
            player->attack(&goblin, player->getInvetory()[0].getItem());
            if(goblin.getHealth() <= 0) break; // forced brake 
        }
        else if(op == 'i' || op == 'I')
        {
            std::cout<<"\n\nThe goblin has: "<<goblin.getArmor().getString()
                <<"\n\n";
        }
        else 
        {
            std::cout<<"Because you are stupid, and did nothing "
                <<"the goblin hit you with his sword he had";
            goblin.attack(player, WOODEN_SWORD);
        }
        std::system("clear");
        std::cout<<"The goblin still has "
            << goblin.getHealth()
            <<"hp, what would you like to do?\n"
            <<"\tAttack(a/A)\n"
            <<"\tInspect visually(i/I)\n"
            <<"\tRun(l/L)\n"
            <<"\tNothing(anything else)\n"
            <<"> "; op = getch();
    }

    if(goblin.getHealth() <= 0)
    {
        // implement reward function TODO
        int reward = rand() % 4 + 1;
        std::cout<<"\n\nYou successfully defeated the goblin and got "<<reward<<" copper coins, they amount to shit!\n\n";
        player->getInvetory().add(Slot(COPPER_COIN, reward));
    }
}
