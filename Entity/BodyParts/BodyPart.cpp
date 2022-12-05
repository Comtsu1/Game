#include "BodyPart.h"
#include "Head.h"

BodyPart::BodyPart()
    :m_inithealth(10), m_health(10) {}
BodyPart::BodyPart(int hp)
    :m_inithealth(hp), m_health(hp) {}

int BodyPart::getInitHealth() const
{
    return m_inithealth;
}

int BodyPart::getHealth() const
{
    return m_health;
}

void BodyPart::setHealth(int value)
{
    m_health = value;
}

void BodyPart::damage(int amount)
{
    m_health -= amount;
}

void BodyPart::heal(int amount)
{
    m_health += amount;
}

double BodyPart::getPercentage()
{
    return ((double)m_health / m_inithealth) * 100.0f;
}
