#pragma once
#include "Item.h"

struct AttackItem : Item
{
    ~AttackItem() override;
    AttackItem() : Item("attack item", 0) { }
    void use(Character*) override;

};
