#include "Inventory.hpp"

#include "Item/Item.h"
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

void Invetory::add(const Slot& slot)
{
    for(int i = 0; i < 10; ++i)
    {
        if(inv[i].getItem() == slot.getItem())
        {
            inv[i].addQty(slot.getQty());
            return;
        }
        else if(inv[i].checkFree())
        {
            inv[i] = slot;
            return;
        }
    }
}

void Invetory::show(bool missing) const
{
    for(int i = 0; i < 10; ++i)
    {
        if(!inv[i].checkFree())
        {
            std::cout<<inv[i].getItem().getName()
                <<": "<<inv[i].getQty()
                <<"\n"
                <<inv[i].getItem().show()
                <<"\n";
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
    inv[index].setItem(NULL_ITEM);
}

Slot& Invetory::operator[](int index)
{
    return inv[index];
}
