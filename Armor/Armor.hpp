#pragma once

#include "../Item.h"

class Armor : public Item
{
    int m_protection;
    public:
        Armor();
        Armor(Item item);

        void setProtection(int protection);
        int getProtection() const;
};