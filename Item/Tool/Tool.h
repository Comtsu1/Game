#pragma once

#include "../Item.h"
#include <string>

class Tool : public Item
{
    private:
        int m_durability;
    public:
        Tool();
        Tool(Item item, int durability);

        int getDurability() const;

        void reduceDurability(int amount);
        void addDurability(int amount);

        std::string show() const override;
};