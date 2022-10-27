#pragma once

#include "../Item.h"
#include <string>

class Tool : public Item
{
    int m_durability;
    public:
        Tool();
        Tool(Item* item, int durability);

        int getDurability() const;

        void addDurability(int amount);
        void reduceDurability(int amount);

        std::string show() const;
};
