#pragma once


class Entity
{
    protected:
        int m_health;
    public:
        Entity(int h): m_health(h) {};
        virtual void damage(int d) = 0;
        int virtual getHealth() const = 0;


};
