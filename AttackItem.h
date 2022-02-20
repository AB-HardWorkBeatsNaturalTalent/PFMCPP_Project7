#pragma once
#include "Item.h"

struct AttackItem : Item
{
    ~AttackItem() override;
    AttackItem() : Item("attack item", 10) { }
    void use(Character*) override;

};
