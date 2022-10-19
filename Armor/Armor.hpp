#pragma once

#include "../Item/Item.h"

class Armor : public Item
{
    int m_protection;
    public:
        Armor();
        Armor(Item item, int protection);

        void setProtection(int protection);
        int getProtection() const;
};
