#include "Slot.hpp"
#include "Item.h"
#include "ItemList.h"

Slot::Slot()
    :m_item(NULL_ITEM), m_qty(-1)
{

}

Slot::Slot(Item i, int qty)
    :m_item(i), m_qty(qty)
{

}

bool Slot::checkFree() const
{
    return m_item.isFree();
}

Item Slot::getItem() const
{
    return m_item;
}

void Slot::setItem(Item i)
{
    m_item = i;
}

int Slot::getQty() const
{
    return m_qty;
}

void Slot::setQty(int q)
{
    m_qty = q;
}

void Slot::addQty(int q)
{
    m_qty += q;
}

void Slot::removeQty(int q)
{
    m_qty -= q;
}
