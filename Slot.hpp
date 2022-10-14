#pragma once

#include "Item.h"

#include <utility>
#include <string>

class Slot
{
    protected:
        Item m_item;
        int m_qty;
    public:
        Slot(): m_item(Item("", -1)), m_qty(-1) {}
        Slot(Item i, int qty) : m_item(i), m_qty(qty) {} 
        inline bool checkFree() const {return m_item.isFree();}

        inline Item getItem() const {return m_item;}
        inline void set(Item i){m_item = i;}

        inline int getQty() const {return m_qty;} 

};
