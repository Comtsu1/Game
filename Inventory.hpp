#pragma once

#include "Slot.hpp"
#include <vector>
#include <memory>

class Invetory
{
    Slot inv[40];
    public:
        Invetory();
        ~Invetory();
        Invetory(std::vector<std::unique_ptr<Slot>> s);
    
        void add(const Slot& s);
        void show(bool missing = 0) const;
        void remove(const int& index);

        //friend Invetory& operator+(Invetory inv, const Invetory& it);
        Slot& operator[](int index);
};
