#pragma once

#include "../Item.h"
#include <memory>
#include <string>

class Tool : public Item
{
    int m_durability;
    public:
        Tool();
        Tool(std::unique_ptr<Item> item, int durability);

        int getDurability() const;

        void addDurability(int amount);
        void reduceDurability(int amount);

        std::string show() const;
};
