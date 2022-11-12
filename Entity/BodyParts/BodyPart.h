#pragma once

#include <string>
enum class Parts
{
    left,
    right,
};

class BodyPart
{
    int m_health;

    public:
        BodyPart();
        BodyPart(int hp);

        std::string virtual status() = 0;

        int getHealth() const;
        void setHealth(int value);

        void damage(int amount);
        void heal(int amount);
};
