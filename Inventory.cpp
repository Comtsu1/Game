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

void Invetory::add(std::unique_ptr<Item> item, const int& qty)
{
    for(int i = 0; i < 10; ++i)
    {
        if(*inv[i].getItem() == *item.get())
        {
            inv[i].addQty(qty);
            return;
        }
        else if(inv[i].checkFree())
        { // moving the item to a new Slot without CREATING A NEW SLOT
          // you dumb dumb
            inv[i].setItem(std::move(item), qty);
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
            std::cout<<inv[i].getItem()->getName()
                <<": "<<inv[i].getQty()
                <<"\n"
                <<inv[i].getItem()->show()
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
