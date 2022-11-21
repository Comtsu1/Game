#pragma once

#include <string>

enum class Type
{
    NONE,
    left,
    right
};


enum class Parts
{
    Head,
    Chest,
    Arm,
    Leg,
};

class BodyPart
{
    int m_inithealth;
    int m_health;

    public:
        BodyPart();
        BodyPart(int hp);

        std::string virtual status() = 0;

        int getInitHealth() const;

        int getHealth() const;
        void setHealth(int value);

        void damage(int amount);
        void heal(int amount);
};
