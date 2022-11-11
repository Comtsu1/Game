#pragma once

class BodyPart
{
    int m_health;

    public:
        int getHealth() const;
        void setHealth(int value);

        void damage(int amount);
        void heal(int amount);
}
