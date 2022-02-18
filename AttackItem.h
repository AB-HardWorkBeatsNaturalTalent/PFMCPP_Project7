#include "Item.h"

struct AttackItem : public Item
{
    AttackItem() : Item("attack item", 2) { }
    void use(Character*) override;

};
