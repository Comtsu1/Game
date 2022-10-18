#pragma once

#include "../Armor.hpp"

class ArmorSet
{
    Armor m_helmet, m_chestplate, m_leggings, m_boots;
    public:
        ArmorSet();
        ArmorSet(Armor helmet, Armor chest, Armor leggings, Armor boots);

        void setArmor(ArmorSet set);
        void setArmor(Armor helmet, Armor chest, Armor leg, Armor boot);

        void setHelmet(Armor helmet);
        void setChestPlate(Armor chest);
        void setLeggings(Armor leggings);
        void setBoots(Armor boots);

        Armor getHelmet() const;
        Armor getChestPlate() const;
        Armor getLeggings() const;
        Armor getBoots() const;
};