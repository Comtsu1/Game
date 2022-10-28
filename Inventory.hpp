#pragma once

#include "Slot.hpp"

#include <vector>
#include <memory>

class Invetory
{
    Slot inv[10];
    public:
        Invetory();
        ~Invetory();
    
        void add(std::unique_ptr<Item> item, const int& qty);
        void show(bool missing = 0) const;
        void remove(const int& index);

        //void setArmor(ArmorSet armor);
        //ArmorSet getArmor() const;

        //friend Invetory& operator+(Invetory inv, const Invetory& it);
        Slot& operator[](int index);
};
