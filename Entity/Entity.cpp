#include "Entity.hpp"

Entity::Entity()
    :m_health(100) {}
Entity::Entity(int hp)
    :m_health(hp) {}

void Entity::damagePart(BodyPart *part, int amount)
{
    part->damage(amount);
}

void Entity::damage(double amount)
{
    m_health -= amount;
}

void Entity::heal(double amount)
{
    m_health += amount;
}

double Entity::getHealth() const
{
    return m_health;
}
