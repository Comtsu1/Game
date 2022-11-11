#include "BodyPart.h"
#include "Head.h"

BodyPart::BodyPart()
    :m_health(10) {}
BodyPart::BodyPart(int hp)
    :m_health(hp) {}

int BodyPart::getHealth() const
{
    return this->m_health;
}

void BodyPart::setHealth(int value)
{
    m_health = value;
}

void BodyPart::damage(int amount)
{
    m_health += amount;
}

void BodyPart::heal(int amount)
{
    m_health += amount;
}
