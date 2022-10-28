#pragma once

#include "Item/Item.h"
#include "ItemList.h"
#include <memory>
#include <utility>
#include <string>

class Slot
{
    protected:
        std::unique_ptr<Item> m_item;
        int m_qty;
    public:
        Slot();
        Slot(std::unique_ptr<Item> item, int qty);
        Slot(Item* item, int qty);
        bool checkFree() const;

        Item* getItem() const;
        std::unique_ptr<Item>& getUniqueItem();

        void setItem(std::unique_ptr<Item> item, const int& qty = 1);
        void setItem(Slot& slot);

        int getQty() const;
        void setQty(const int& qty);
        void addQty(const int& qty);
        void removeQty(const int& qty);
};
