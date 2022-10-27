#pragma once

#include "Item/Item.h"
#include "ItemList.h"
#include <memory>
#include <utility>
#include <string>

class Slot
{
    protected:
        std::shared_ptr<Item> m_item;
        int m_qty;
    public:
        Slot();
        Slot(Item* item, int qty);
        bool checkFree() const;

        Item* getItem() const;
        void setItem(Item* item);

        int getQty() const;
        void setQty(int qty);
        void addQty(int qty);
        void removeQty(int qty);
};
