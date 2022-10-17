#pragma once


#include "Item.h"
#include "ItemList.h"
#include <utility>
#include <string>

class Slot
{
    protected:
        Item m_item;
        int m_qty;
    public:
        Slot();
        Slot(Item i, int qty);
        bool checkFree() const;

        Item getItem() const;
        void setItem(Item i);

        int getQty() const;
        void setQty(int q);
        void addQty(int q);
        void removeQty(int q);
};
