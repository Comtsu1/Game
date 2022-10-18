#pragma once

#include "Slot.hpp"
#include "Armor/ArmorSet/ArmorSet.hpp"

#include <vector>
#include <memory>

class Invetory
{
    Slot inv[10];
    ArmorSet m_armor;
    public:
        Invetory();
        ~Invetory();
    
        void add(const Slot& slot);
        void show(bool missing = 0) const;
        void remove(const int& index);

        //friend Invetory& operator+(Invetory inv, const Invetory& it);
        Slot& operator[](int index);
};
