#pragma once

class BodyPart
{
    int m_health;

    public:
        BodyPart();
        BodyPart(int hp);

        int getHealth() const;
        void setHealth(int value);

        void damage(int amount);
        void heal(int amount);
};
