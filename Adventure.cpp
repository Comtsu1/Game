#include "Adventure.h"

#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "defines.h"

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

    std::system("clear");
    std::cout << "You have encountered a goblin:"
        <<"\n\tGoblin: " << goblin.getHealth()
        <<"\n\tYou: "<< player->getHealth()
        <<"\nWhat would you like to do?\n"
        <<"\tAttack(a/A)\n"
        <<"\tInspect visually(i/I)\n"
        <<"\tLeave(l/L)\n"
        <<"\tNothing(anything else)\n"
        <<"> ";
    int op;
    op = getch();
    std::cout<<"op: "<<(char)op<<"\n";
    
    if(op == 'l' || op == 'L')
    {
        if(rand() % 10)
        { // escapes
            std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
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
            || op == 'i' || op == 'I'
            || op == 'l' || op == 'L'
               ))
        {
            std::system("clear");
            if(rand() % 100)
            { // very stupid man right here
                std::cout<<"\nYou and the goblin just stay in your places, waiting for something to happen.\n";
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
                <<"\tNothing(anything else)\n"
                <<"> "; op = getch();
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
                return;
            }
        }
    }

    while(goblin.getHealth() > 0)
    {
        std::system("clear");
        if(op == 'a' || op == 'A')
        {
            player->attack(&goblin, player->getInvetory()[0].getItem());
            goblin.attack(player, WOODEN_SWORD);
        }
        else if(op == 'i' || op == 'I')
        {
            std::cout<<"\nThe goblin has: "<<goblin.getArmor().getString()
                <<"\n\n";
        }
        else if(op == 'r' || op == 'R')
        {
            if(rand() % 10)
            { // gets caught
                std::cout<<"You are stupid and the goblin hit you!\n";
                goblin.attack(player, WOODEN_SWORD);
            }
            else
            { // gets caught
                std::cout<<"\n\nYou escaped without the goblin noticing you.\n";
                sleep(1);
                return;
            }
        }
        else 
        {
            std::cout<<"Because you are stupid, and did nothing "
                <<"the goblin hit you with his sword he had.\n";
            goblin.attack(player, WOODEN_SWORD);
        }
        

        if(goblin.getHealth() <= 0) break; // forced brake 
        if(player->getHealth() <= 0)
        {
            std::cout<<"\n\nYou died, too bad!...";
            sleep(1);
            return;
        }

        std::cout<<"You are mid-battle"
            <<"\n\tGolbin: " << goblin.getHealth()
            <<"\n\tYou: " <<player->getHealth()
            <<"\nWhat would you like to do?\n"
            <<"\tAttack(a/A)\n"
            <<"\tInspect visually(i/I)\n"
            <<"\tRun(r/R)\n"
            <<"\tNothing(anything else)\n"
            <<"> "; op = getch();
    }

    if(goblin.getHealth() <= 0)
    {
        // implement reward function TODO
        int reward = rand() % 4 + 1;
        std::cout<<"\n\nYou successfully defeated the goblin and got "<<reward<<" copper coins, they amount to shit!\n\n";
        player->getInvetory().add(COPPER_COIN, reward);
    }
}
