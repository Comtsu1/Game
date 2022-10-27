#pragma once

#include <string>

class Item
{
    private:
        std::string m_name;
        int m_id;
        int m_damage;
    public:
        Item();
        Item(std::string name, int id, int damage);
        Item(Item* item);

        int getID() const;
        
        std::string getName() const;
        virtual std::string show() const;

        int getDamage() const;

        bool isFree() const;

        bool operator==(const Item& item) const;
};
