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

ArmorSet Entity::getArmor() const
{
    return m_armorset;
}


void Entity::setArmor(ArmorSet set)
{
    m_armorset = set;
}

void Entity::attack(Entity *entity, std::unique_ptr<Item> item)
{
    entity->damage(item->getDamage() - entity->getArmor().calculateProtection());
}


void Entity::attack(Entity *entity, Item* item)
{
    entity->damage(item->getDamage() - entity->getArmor().calculateProtection());
}

std::string Entity::getVisualAttributes() const
{
    return m_armorset.getString();
}

double Entity::getHealth() const
{
    return m_health;
}
