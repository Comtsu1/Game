#pragma once

#include <string>

class Item
{
    private:
        std::string m_name;
        int m_id;
        int m_damage;
    public:
        Item(std::string name, int id, int damage) :m_id(id), m_name(name), m_damage(damage) {};

        inline int getID() const {return m_id;}
        inline std::string getName() const {return m_name;}

        inline bool isFree() const {return m_id == -1;}

        bool operator==(const Item& i) const {return this->getID() == i.getID();}
};
