#pragma once

#include "Item.h"
#include "Character.h"

struct DefensiveItem : public Item
{
    DefensiveItem() : Item("defensive item", 4) { }
    void use(Character* character) override;
};



