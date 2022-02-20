#pragma once

#include "Item.h"
#include "Character.h"

struct DefensiveItem : Item
{
    DefensiveItem() : Item("defensive item", 4) { }
    void use(Character* character) override;
};



