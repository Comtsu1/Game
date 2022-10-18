#pragma once

#include "../Slot.hpp"

class ArmorSet
{
    Slot m_helmet, m_chestplate, m_leggings, m_boots;
    public:
        ArmorSet();
        ArmorSet(Slot helmet, Slot chest, Slot leggings, Slot boots);

        void setArmor(ArmorSet set);
        void setArmor(Slot helmet, Slot chest, Slot leg, Slot boot);

        void setHelmet(Slot helmet);
        void setChestPlate(Slot chest);
        void setLeggings(Slot leggings);
        void setBoots(Slot boots);

        Slot getHelmet() const;
        Slot getChestPlate() const;
        Slot getLeggings() const;
        Slot getBoots() const;
};