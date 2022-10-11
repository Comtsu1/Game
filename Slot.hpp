#pragma once

#include <utility>
#include <string>

class Slot
{
    protected:
        std::string m_name;
        int m_iid;
        int m_qty;
    public:
        Slot(): m_iid(-1), m_qty(-1) {}
        Slot(int iid, int qty) : m_iid(iid), m_qty(qty) {}
        inline bool checkFree() const {return m_iid == -1;}

        inline const Slot& getSlot() {return *this;}
        inline void set(int iid, int qty){m_iid = iid; m_qty = qty;}


        inline std::string getName() const {return m_name;}
        inline int getIID() const {return m_iid;} 
        inline int getQty() const {return m_qty;} 

};
