#pragma once
#include "Item.h"

struct AttackItem : public Item
{
    ~AttackItem() override;
    AttackItem() : Item("attack item", 2) { }
    void use(Character*) override;

};
