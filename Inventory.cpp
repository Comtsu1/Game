#include "Inventory.hpp"

#include "Item.h"
#include "Slot.hpp"
#include "ItemList.h"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

Invetory::Invetory()
{

}

Invetory::~Invetory()
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

void Invetory::show(bool missing) const
{
    for(int i = 0; i < 30; ++i)
    {
        if(!inv[i].checkFree())
        {
            std::cout<<inv[i].getItem().getName()<<": "<<inv[i].getQty()<<"\n";
        }
        else
        {
            if(missing) std::cout<<"-\n";
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

    inv[index].set(NULL_ITEM);
}

Slot& Invetory::operator[](int index)
{
    if(index < 0 || index > 30)
    {
        throw std::out_of_range("index not found");
    }

    return inv[index];
}
