#include "Inventory.hpp"
#include "Slot.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

Invetory::Invetory()
{

}

void Invetory::add(const Slot& s)
{
    for(int i = 0; i < 30; ++i)
    {
        if(inv[i].checkFree())
        {
            inv[i] = s;
            return;
        }
    }
}

void Invetory::show() const
{
    for(int i = 0; i < 30; ++i)
    {
        if(!inv[i].checkFree())
        {
            std::cout<<inv[i].getName()<<" "<<inv[i].getQty()<<"\n";
        }
        else
        {
            std::cout<<"-\n";
        }
    }
}

// removes information from index "index"
void Invetory::remove(const int& index)
{
    if(index < 0 || index > 30)
    {
        throw std::out_of_range ("index out of range");
    }

    inv[index].set(-1, -1);
}

Slot& Invetory::operator[](int index)
{
    if(index < 0 || index > 30)
    {
        throw std::out_of_range("index not found");
    }

    return inv[index];
}
