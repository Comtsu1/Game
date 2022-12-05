#pragma once

#include "Item/Item.h"
#include "Item/Armor/ArmorSet/ArmorSet.hpp"
#include "Item/Tool/Tool.h"

#include <memory>

#define NULL_ITEM std::make_unique<Item>("You should't have shit, but ok.", -1, 0)


#define APPLE std::make_unique<Item>("Apple", 1001, 1)
#define HERB std::make_unique<Item>("Herb", 2001, 0)

#define WOODEN_SWORD std::make_unique<Tool>(std::make_unique<Item>(Item("Wooden Sword", 910, 3)), 30)
#define STONE_SWORD std::make_unique<Tool>(std::make_unique<Item>("Stone Sword", 911, 6), 60)

#define COPPER_COIN std::make_unique<Item>("Copper Coin", 301, 1)
#define SILVE_COIN std::make_unique<Item>("Silver Coin", 302, 1)
#define GOLD_COIN std::make_unique<Item>("Gold Coin", 303, 1)

#define LEATHER_ARMOR_FULL_SET ArmorSet(LEATHER_ARMOR_HELMET, LEATHER_ARMOR_CHESTPLATE, LEATHER_ARMOR_LEGGINGS, LEATHER_ARMOR_BOOTS)
#define LEATHER_ARMOR_HELMET Armor(Item("Leather helmet", 10001, 0) , 2)
#define LEATHER_ARMOR_CHESTPLATE Armor(Item("Leather chestplate", 10002, 0) , 4)
#define LEATHER_ARMOR_LEGGINGS Armor(Item("Leather leggings", 10003, 0) , 3)
#define LEATHER_ARMOR_BOOTS Armor(Item("Leather boots", 10004, 0) , 1)


#define GOLD_ARMOR_FULL_SET ArmorSet(GOLD_ARMOR_HELMET, GOLD_ARMOR_CHESTPLATE, GOLD_ARMOR_LEGGINGS, GOLD_ARMOR_BOOTS)
#define GOLD_ARMOR_HELMET Armor(Item("Gold helmet", 10011, 2), 3)
#define GOLD_ARMOR_CHESTPLATE Armor(Item("Gold chestplate", 10012, 3), 6)
#define GOLD_ARMOR_LEGGINGS Armor(Item("Gold leggings", 10013, 4), 4)
#define GOLD_ARMOR_BOOTS Armor(Item("Gold boots", 10014, 2), 2)

