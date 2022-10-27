#include "Slot.hpp"
#include "Item/Item.h"
#include "ItemList.h"

Slot::Slot()
    :m_item(NULL_ITEM), m_qty(-1)
{

}

Slot::Slot(Item* item, int qty)
    :m_item(item), m_qty(qty)
{

}

bool Slot::checkFree() const
{
    return m_item->isFree();
}

Item* Slot::getItem() const
{
    return m_item.get();
}

void Slot::setItem(Item* item)
{
    m_item = std::make_shared<Item>(item->getName(),
                                    item->getID(),
                                    item->getDamage());
}

int Slot::getQty() const
{
    return m_qty;
}

void Slot::setQty(int qty)
{
    m_qty = qty;
}

void Slot::addQty(int qty)
{
    m_qty += qty;
}

void Slot::removeQty(int qty)
{
    m_qty -= qty;
}
