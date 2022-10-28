#include "Slot.hpp"
#include "Item/Item.h"
#include "ItemList.h"
#include <memory>
#include <utility>

Slot::Slot()
    :m_item(std::move(NULL_ITEM)), m_qty(-1)
{

}

Slot::Slot(std::unique_ptr<Item> item, int qty)
    :m_item(std::move(item)), m_qty(qty)
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

std::unique_ptr<Item>& Slot::getUniqueItem()
{
    return m_item;
}

void Slot::setItem(std::unique_ptr<Item> item, const int& qty)
{
    m_item.reset();
    m_item = std::move(item);

    this->setQty(qty);
}

void Slot::setItem(Slot& slot)
{
    m_item.reset();
    m_item = std::move(slot.getUniqueItem());
}

int Slot::getQty() const
{
    return m_qty;
}

void Slot::setQty(const int& qty)
{
    m_qty = qty;
}

void Slot::addQty(const int& qty)
{
    m_qty += qty;
}

void Slot::removeQty(const int& qty)
{
    m_qty -= qty;
}
