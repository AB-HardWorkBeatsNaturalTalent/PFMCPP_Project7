#pragma once
#include "Item.h"

struct AttackItem : public Item
{
    ~AttackItem() override;
    AttackItem() : Item("attack item", 0) { }
    void use(Character*) override;

};
