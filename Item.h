#pragma once

#include <string>

class Item
{
    private:
        std::string m_name;
        int m_id;
    public:
        Item(std::string name, int id) :m_id(id), m_name(name) {};

        inline int getID() const {return this->m_id;}
        inline std::string getName() const {return this->m_name;}

        inline bool isFree() const {return m_id == -1;}
};
